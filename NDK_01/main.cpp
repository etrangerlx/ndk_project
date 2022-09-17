//
// Created by rainbow on 2022/9/17.
//
#include <iostream>
#include "./include/Mylog.h"
int main(){
    for(int i = 0; i<100;i++){
        ALGO_VERBOSE("hello");
        ALGO_WARN("hello");
        ALGO_INFO("hello");
        ALGO_DEBUG("hello");
        ALGO_ERROR("hello");
    }
    return 0;
}