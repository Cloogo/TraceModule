#include <stdio.h>
#include <stdarg.h>
#include "trace.h"

static int depth;

static void fillspace(){
    for(int i=0;i<depth;i++){
        printf(" ");
    }
}

void Trace_locate(const char* funcn,const char* file,const int line){
#ifdef DEBUG
    fillspace();
    printf("\e[34m");
    printf("[%s]-[%s:%d]",funcn,file,line);
    printf("\e[0m");
    fflush(stdout);
#endif
}

void Trace_enter(const char* funcn,const char* file,const int line){
#ifdef DEBUG
    printf("\n");
    fillspace();
    printf("[%s]-[%s:%d]",funcn,file,line);
    printf(" Enter...\n");
    fflush(stdout);
    depth++;
#endif
}

void Trace_leave(const char* funcn,const char* file,const int line){
#ifdef DEBUG
    depth--;
    fillspace();
    printf("[%s]-[%s:%d]",funcn,file,line);
    printf(" Exit.\n");
    printf("\n");
    fflush(stdout);
#endif
}

void Trace_print(const char* funcn,const char* fmt,...){
#ifdef DEBUG
    fillspace();
    printf("\e[32m");
    printf("[%s]",funcn);
    va_list argslist;
    va_start(argslist,fmt);
    vprintf(fmt,argslist);
    va_end(argslist);
    printf("\e[0m");
    fflush(stdout);
#endif
}

void Trace_eprint(const char* funcn,const char* fmt,...){
#ifdef DEBUG
    fillspace();
#endif
    printf("\e[31m");
    printf("[%s]",funcn);
    va_list argslist;
    va_start(argslist,fmt);
    vprintf(fmt,argslist);
    va_end(argslist);
    printf("\e[0m");
    fflush(stdout);
}

void Trace_argp(const char* funcn,const char* argname,const char* fmt,...){
#ifdef DEBUG
    fillspace();
    printf("\e[33m");
    printf("[%s]%s=",funcn,argname);
    va_list argslist;
    va_start(argslist,fmt);
    vprintf(fmt,argslist);
    va_end(argslist);
    printf("\e[0m");
    fflush(stdout);
#endif
}
