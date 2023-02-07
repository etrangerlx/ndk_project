//
// Created by Administrator on 2023/2/7.
//

#ifndef ANDROIDNDK_CPU_CORE_H
#define ANDROIDNDK_CPU_CORE_H


class CPU_core {
    int GetCpuMaxFreqNum() {
        //获取CPU大核频率判断大核
        int res;
        int cpu0Freq, cpu7Freq;
        FILE *fp = fopen("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq", "rb");
        if (fp != nullptr) {
            fseek(fp, 0, SEEK_END);
            int FileLen = ftell(fp);
            rewind(fp);
            char *pIn = new [FileLen + 1];
            memset(pIn, 0
            FileLen + 1);
            fread(pIn, 1, FileLen + 1, fp);
            fclose(fp);
            printf("FileLen:%d", FileLen);
            cpu0Freq = atoi(pIn);
            delete[] pIn;
        }
        fp = fopen("/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_max_freq", "rb");
        if (fp != nullptr) {
            fseek(fp, 0, SEEK_END);
            int FileLen = ftell(fp);
            rewind(fp);
            char *pIn = new [FileLen + 1];
            memset(pIn, 0
            FileLen + 1);
            fread(pIn, 1, FileLen + 1, fp);
            fclose(fp);
            printf("FileLen:%d", FileLen);
            cpu7Freq = atoi(pIn);
            delete[] pIn;
        }
        printf("cpu0freq:%d,cpu7freq:%d", cpu0Freq, cpu7Freq);
        if (cpu0Freq > cpu7Freq) {
            res = 1;
        } else {
            res = 0;
        }
        return res;
    }

    void SetCPU(int cpuMax01) {
#ifndef _WIN32
        //绑定大核CPU
        int policy, priority;
        struct sched_param param;
        if( policy == SHED_OTHER) {
            int ret ::setpriority(PRIO_PROCESS,0,-19);

        } else {
            struct sched_param shed_p;
            ::sched_getparam(0,&sched_p);
            priority =  shed_p.sched_priority;
        }
        int tId = gettid();
        cpu_set_t mask;
        CPU_ZERO(&mask);
        if(cpuMax01) {
            CPU_SET(0,&mask);
            CPU_SET(1,&mask);
        } else {
            CPU_SET(6,&mask);
            CPU_SET(7,&mask);
        }
        sched_setaffinity(tid,sizeof(mask),&mask);
#endif
    }
};


#endif //ANDROIDNDK_CPU_CORE_H
