
#include "MemoryTrace.hpp"
#include <unistd.h>
//变量类型
//https://blog.csdn.net/weixin_45743799/article/details/104861109

//void *operator new(size_t size) {
//    void *p = nullptr;
//    p = malloc(size);
//
//    if (p == nullptr) {
//        cout << "new error" << endl;
//        return nullptr;
//    } else {
//
//        cout << "new object addr:" << p << "," << "size:" << size << endl;
//    }
//    return p;
//}
//void operator delete(void *pVoid) {
//    if (pVoid != nullptr) {
//        free(pVoid);
//        cout << "delete:" << pVoid << endl;
//        pVoid = nullptr;
//    }
//}
//void operator delete[] (void *pVoid){
//    if(pVoid != nullptr){
//        free(pVoid);
//        cout<<"delete[]:"<<pVoid<<endl;
//        pVoid = nullptr;
//    }
//}

class object {
public:
    int x = 0;
    int y = 0;

    void print() {
        cout << x << endl;
        cout << y << endl;
    }

    object() {
        cout << "construct object:" << this << endl;
    }

    ~object() {
        cout << "deconstruct object:" << this << endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    string str = "xian.lei";
    object *obj = nullptr;
    object *obj1 = nullptr;
    object *obj2 = nullptr;
    ALGO_NEW(object,obj);

    ALGO_NEW(object,obj1);
    ALGO_NEW(object,obj2);

    int *p1 = nullptr;
    ALGO_NEW(int,p1);
    ALGO_DELETE(p1);
//    object *obj = MEM.NEW_RECORD<object>(typeid(object).name(),typeid(object).hash_code(),
//            string(__FILE__),false, sizeof(object),string(__FUNCTION__),int(__LINE__));
//    sleep(1);
    ALGO_DELETE(obj1);
//    delete obj1;
//    sleep(1);
//    MemoryTrace::printMemInfo();
    ALGO_DELETE(obj2);
    ALGO_DELETE(obj);
//    delete obj2;
//    MEM.DELETE_RECORD<object>(obj,false);
    return 0;
}
