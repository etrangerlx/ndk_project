//
// Created by rainbow on 2022/9/17.
//

#ifndef NEW_DELETE_MEMORYTRACE_HPP
#define NEW_DELETE_MEMORYTRACE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <memory>
#include <typeinfo>

using namespace std;
bool Isdebug = false;

struct MemInfo {
    void *pMemAddress = nullptr;
    string typeName = "";
    size_t hashCode = 0;
    string fileName = "";
    string funName = "";
    int Line = 0;
    bool isArray = false;
    int bMemsize = 0;

    bool operator<(const MemInfo &m1) {
        if (Line > m1.Line) {
            return true;
        } else {
            return false;
        }
    }

    friend bool operator<(const MemInfo &t1, const MemInfo &t2) {
        if (t1.Line <= t2.Line) {
            return true;
        } else {
            return false;
        }
    }
};

class MemoryTrace {
public:
    MemoryTrace() {
        MemTotalCur = 0;
        MemTotalMax = 0;

        MembBlockCountCur = 0;
        MembBlockCountMax = 0;
    }

    ~MemoryTrace() {
        if (MemMap.size() != 0) {
            printMemInfo();
            abort();
        }
    }


    void NEW_RECORD(void *pMemBase, string classtype, size_t hash, \
     string fN, bool isA, int Memsize, string funN, int line) {
//        if (Isdebug) {
        MemInfo meminfotmp;
        meminfotmp.pMemAddress = (void *) pMemBase;
        meminfotmp.typeName = classtype;
        meminfotmp.hashCode = hash;
        meminfotmp.funName = funN;
        meminfotmp.isArray = isA;
        meminfotmp.bMemsize = Memsize;
        meminfotmp.fileName = fN;
        meminfotmp.Line = line;

        MemTotalCur += Memsize;
        MembBlockCountCur++;
        //记录内存申请情况
        if (MemTotalCur > MemTotalMax) {
            MemTotalMax = MemTotalCur;
        }
        if (MembBlockCountCur > MembBlockCountMax) {
            MembBlockCountMax = MembBlockCountCur;
        }
        clock_t t = clock();

        MemMap.insert(pair<MemInfo, clock_t>(meminfotmp, t));
        cout << "new MEMSIZE:" << MemMap.size() << endl;
    }

    void DELETE_RECORD(void *pMemBase, bool isA) {
        for (auto itr = MemMap.begin(); itr != MemMap.end(); itr++) {
            if (itr->first.pMemAddress == pMemBase) {
                MemTotalCur -= itr->first.bMemsize;
                MembBlockCountCur --;
                MemMap.erase(itr);
                pMemBase = nullptr;
                break;
            }
        }
        cout << "remain MEMSIZE:" << MemMap.size() << endl;
    }

    bool isNormall() {
        //TODO
    }

    void printMemInfo() {
        for (auto itr = MemMap.begin(); itr != MemMap.end(); itr++) {
            cout << "FILENAME:" << itr->first.fileName << ","
                 << "FUNCTION:" << itr->first.funName << ","
                 << "[" << itr->first.Line << "]" << endl;
        }
        cout << "MembBlockCountCurrent:" << MembBlockCountCur << endl;
        cout << "MembBlockCountMaxinum:" << MembBlockCountMax << endl;
        cout << "MemTotalCurrent:" << MemTotalCur << endl;
        cout << "MemTotalMaxinum:" << MemTotalMax << endl;
    }

private:
    //记录内存总量
    long long MemTotalCur;
    long long MemTotalMax;
    //记录内存块总量
    int MembBlockCountCur;
    int MembBlockCountMax;
    //内存信息|时间信息
    map<MemInfo, clock_t> MemMap;
//    vector<MemInfo> MemVec;
};
static MemoryTrace MEM;
#define ALGO_NEW(T,pVoid) {\
    pVoid =new T;\
    MEM.NEW_RECORD(pVoid,typeid(T).name(),typeid(T).hash_code(),string(__FILE__),\
                        false, sizeof(T),string(__FUNCTION__),int(__LINE__));\
}

//#define ALGO_NEW(T,pVoid,size) {\
//    pVoid =new[] T;\
//    MEM.NEW_RECORD(pVoid,typeid(T).name(),typeid(T).hash_code(),string(__FILE__),\
//                        true, size*sizeof(T),string(__FUNCTION__),int(__LINE__));\
//}


#define ALGO_DELETE(pVoid,flag) {\
    if(flag){\
        MEM.DELETE_RECORD(pVoid,true);\
        delete [] pVoid;\
    } else {\
        MEM.DELETE_RECORD(pVoid,false);\
        delete pVoid;\
    }\
    pVoid = nullptr;\
}


#endif //NEW_DELETE_MEMORYTRACE_HPP





