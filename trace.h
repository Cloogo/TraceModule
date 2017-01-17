#ifndef _MYTRACE_H
#define _MYTRACE_H
#define DEBUG
extern void Trace_locate(const char* func,const char* file,const int line);
extern void Trace_enter(const char* funcn,const char* file,const int line);
extern void Trace_leave(const char* funcn,const char* file,const int line);
extern void Trace_print(const char* funcn,const char* fmt,...);
extern void Trace_eprint(const char* funcn,const char* fmt,...);
extern void Trace_argp(const char* funcn,const char* argname,const char* fmt,...);
#define Trace_LOC() Trace_locate(__FUNCTION__,__FILE__,__LINE__)
#define Trace_E() Trace_enter(__FUNCTION__,__FILE__,__LINE__)
#define Trace_L() Trace_leave(__FUNCTION__,__FILE__,__LINE__)
#define Trace_P(fmt,...) Trace_print(__FUNCTION__,fmt,__VA_ARGS__)
#define Trace_EP(fmt,...) Trace_eprint(__FUNCTION__,fmt,__VA_ARGS__)
#define Trace_AP(fmt,arg) Trace_argp(__FUNCTION__,#arg,fmt,arg)
#define Trace_API(arg) Trace_AP("%d\n",arg)
#define Trace_APC(arg) Trace_AP("\'%c\'\n",arg)
#define Trace_APS(arg) Trace_AP("\"%s\"\n",arg)
#define Trace_APD(arg) Trace_AP("%ff\n",arg)
#define Trace_APL(arg) Trace_AP("%ldl\n",arg)
#endif
