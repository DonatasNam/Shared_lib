#include <log.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{ 
    char *exename = strrchr(argv[0], '/');
        if (exename)
            ++exename;   
        else
            exename = argv[0];
    char *filename= "log.db";
    dbopen(filename);
    create_table();
    srand(time(NULL));
    int i = (rand()%9001);
        if(i<4500){
            log_info(exename,__LINE__,__FILE__,"Levels normal");
            sleep(1);
        }else if(i<9000 && i>4500){
            log_warn(exename,__LINE__,__FILE__,"Levels aproching limit");
            sleep(3);
        }else if(i>8999){
            log_error(exename,__LINE__,__FILE__,"ITS OVER 9000");
            sleep(5);
        }
    dbclose();
}