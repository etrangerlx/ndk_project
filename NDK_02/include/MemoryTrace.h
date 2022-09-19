//
// Created by rainbow on 2022/9/17.
//

#ifndef NEW_DELETE_MEMORYTRACE_H
#define NEW_DELETE_MEMORYTRACE_H

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <memory>
#include <typeinfo>

using namespace std;

class MemInfo {
public:
    void *pMemAddress = nullptr;
    string typeName ;
    size_t hashCode = 0;
    string fileName ;
    string funName ;
    int Line = 0;
    bool isArray = false;
    int bMemsize = 0;

    bool operator<(const MemInfo &t1) {
        if (t1.hashCode <= hashCode) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator<(const MemInfo &t1,const MemInfo &t2){
        if (t1.hashCode <= t2.hashCode) {
            return true;
        } else {
            return false;
        }
    }
};

class MemoryTrace {
public:
    MemoryTrace() {
        MemToatalCur = 0;
        MemToatalMax = 0;

        MembBlockCountCur = 0;
        MembBlockCountMax = 0;
    }

    ~MemoryTrace(){
        if (MemMap.size() != 0) {
            printMemInfo();
            abort();
        }
    }

    template<typename T>
    T * NEW_RECORD(string classtype, size_t hash, \
     string fN, bool isA, int Memsize, string funN,int line){

        T * pMemBase = new T();
        MemInfo meminfotmp;
        meminfotmp.pMemAddress= (void *)pMemBase;
        meminfotmp.typeName = classtype;
        meminfotmp.hashCode = hash;
        meminfotmp.funName = funN;
        meminfotmp.isArray = isA;
        meminfotmp.bMemsize = Memsize;
        meminfotmp.fileName = fN;
        meminfotmp.Line=line;

        MemToatalCur += Memsize;
        MembBlockCountCur++;
        //记录内存申请情况
        if (MemToatalCur > MembBlockCountMax) {
            MembBlockCountMax = MemToatalCur;
        }
        if (MembBlockCountCur > MemToatalMax) {
            MemToatalMax = MembBlockCountCur;
        }
        clock_t t =clock();

        MemMap.insert(pair<MemInfo,size_t>(meminfotmp,t));
        return pMemBase;
    }

    template <typename T>
    void DELETE_RECORD(T *pMemBase, bool isA){
        for (map<MemInfo,clock_t>::iterator itr = MemMap.begin(); itr != MemMap.end(); itr++) {
            if ((T*)itr->first.pMemAddress == pMemBase) {
                MemToatalCur -= itr->first.bMemsize;
                MembBlockCountCur--;
                MemMap.erase(itr);
                cout<<pMemBase<<endl;
                delete(pMemBase);
                pMemBase = nullptr;
            }
        }
    }

    bool isNormall(){
        //TODO
    }

    void printMemInfo(){
        for(map<MemInfo,clock_t>::iterator itr= MemMap.begin();itr != MemMap.end();itr++){
            cout<<"FILENAME:"<<itr->first.fileName<<","
            <<"FUNCTION:"<<itr->first.funName<<","
            <<"["<<itr->first.Line<<"]"<<endl;
        }
    }

private:
    //记录内存总量
    long long MemToatalCur;
    long long MemToatalMax;
    //记录内存块总量
    int MembBlockCountCur;
    int MembBlockCountMax;
    //内存信息|时间信息
    map<MemInfo, clock_t> MemMap;
};

static MemoryTrace MEM;//静态全局变量，用于存储、释放内存new、delete堆栈信息

#define ALGO_NEW(T) MEM.NEW_RECORD<T>(typeid(T).name(),typeid(T).hash_code(),string(__FILE__),\
                        false, sizeof(T),string(__FUNCTION__),int(__LINE__))

#define ALGO_DELETE(T,pVoid) MEM.DELETE_RECORD<T>(pVoid,false)
#endif //NEW_DELETE_MEMORYTRACE_H





