//
// Created by rainbow on 2022/9/17.
//
#include "../include/Mylog.h"
#include <stdlib.h>

#ifdef ANDROID
#include <sys/system_properties.h>
LOG::LOG(){
    char logstr[PROP_VALUE_MAX] = {0};
    __system_property_get("debug.log.levelenable",logstr);
    int enablelevel = 0x0;
    if (strlen(logstr)>0){
        enablelevel = atoi(logstr);
    }
    loglevel = enablelevel;
}
#else
LOG::LOG(){
    loglevel = LOG_LEVELV;
}
#endif

void LOG::setLoglevel(int lelevel){
    loglevel = lelevel;
}
int LOG::getLoglevel(){
    return loglevel;
}
