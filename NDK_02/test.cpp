//
// Created by rainbow on 2022/9/17.
//
#include "include/MemoryTrace.h"

//void *operator new(size_t size){
//    cout<<"new"<<endl;
//    return malloc(size);
//}

class object {
public:
    int x = 0;
    int y = 0;
};
int main(){
    object *obj = ALGO_NEW(object);
    ALGO_DELETE(object,obj);
    return 0;
}