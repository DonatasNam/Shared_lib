#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <sqlite3.h>
sqlite3* db;
char* err;

void dbopen(char *filename);
void log_init();
void log_end();
void dbclose();
char * statement_table();
char * print_statement();
void create_table();
void print_table();
void add_to_table();
char *add_statement();
void prepare_stmt(char* prog, char *time, int line, char*file, char* level, char *msg);
void open_err_handler(int rc);
void insert_err_handler(int rc);
void prepare_err_handler(int rc);
void step_err_handler(int rc);
void log_info(char*prog,int line, char* file,char* msg);
void log_warn(char*prog,int line, char* file,char* msg);
void log_error(char*prog,int line, char* file,char* msg);
void prepare_print(char* program);



