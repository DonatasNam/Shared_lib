#include "gen.h"


int main(int argc, char *argv[])
{
    char *filename= "log.db";
     char *exename = strrchr(argv[0], '/');
        if (exename)
            ++exename;   
        else
            exename = argv[0];
    dbopen(filename);
        create_table();
        error(exename);
        warn(exename);
        info(exename);

    dbclose();
}
