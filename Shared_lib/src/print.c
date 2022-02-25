#include <log.h>
#include <getopt.h>

static struct option long_options[] =
{
    {"program", optional_argument, NULL, 'P'},
    {NULL, 0, NULL, 0}
};



int main(int argc, char **argv)
{
    char*filename= "log.db";
    dbopen(filename);
    int c;
    int option_index = 0;
    
    
    while(1){
        c = getopt_long(argc, argv, ":P:", long_options, &option_index);
        char* progname= argv[2];
        if(argv[1] == NULL){
            print_table();
        }
        if (c == -1){
        break;
        }
        switch (c)
        {
        case 'P':
            prepare_print(progname);
        break;
    
        default:
            printf("\n incorect argument\n");
            exit(1);
        break;
        }
    }

    dbclose();
}