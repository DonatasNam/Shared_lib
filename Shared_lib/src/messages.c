#include "gen.h"


void info(char* prog)
{
    char* msg= "genereal information";
    log_info(prog,__LINE__,__FILE__,msg);
    sleep(1);
}
void warn(char* prog)
{
    char* msg= "genereal warning";
    log_warn(prog,__LINE__,__FILE__,msg);
    sleep(1);
}

void error(char* prog)
{
    char* msg= "genereal error";
    log_error(prog,__LINE__,__FILE__,msg);
    sleep(5);
}
