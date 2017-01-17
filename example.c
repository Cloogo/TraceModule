#include <stdio.h>
#include "trace.h"

void echo_c(){
    Trace_E();
    char type='A';
    Trace_APC(type);
    Trace_L();
}

void echo_i(){
    Trace_E();
    int indicator=10;
    Trace_API(indicator);
    Trace_L();
}

void echo_f(){
    Trace_E();
    float rate=0.001;
    Trace_APD(rate);
    Trace_L();
}

void echo_d(){
    Trace_E();
    double discount=0.9;
    Trace_APD(discount);
    Trace_L();
}

void echo_l(){
    Trace_E();
    long len=1024;
    Trace_APL(len);
    Trace_L();
}
void echo_str(){
    Trace_E();
    char* msg="Hello world!";
    Trace_APS(msg);
    Trace_L();
}

void echo_multiargs(){
    Trace_E();
    Trace_P("Name:%s\t Age:%d \tLevel:%c\n","Cloogo",20,'S');
    Trace_L();
}

void echo_errmsg(){
    Trace_E();
    Trace_EP("%s\n","process 111 unable to get the lock!");
    Trace_L();
}

void nest_2th(){
    Trace_E();
    echo_c();
    echo_i();
    echo_str();
    echo_d();
    echo_multiargs();
    Trace_L();
}

void nest_1th(){
    Trace_E();
    nest_2th();
    Trace_L();
}

void nest(){
    Trace_E();
    nest_1th();
    Trace_L();
}

void test(const char* str){
    Trace_E();
    Trace_APS(str);
    echo_c();
    echo_i();
    echo_f();
    echo_d();
    echo_str();
    echo_multiargs();
    echo_errmsg();
    nest();
    Trace_L();
}

int main(){
    Trace_E();
    test("testing");
    Trace_L();
    Trace_LOC();
    return 0;
}
