#include "log.h"

char *add_statement()
{
    char *sql ="INSERT INTO ERROR_MESSAGE (ID,PROGRAM,TIME,LINE,FILE,ERROR_LEVEL,ERROR_MESSAGE) "  \
         "VALUES (NULL,?, ?, ?, ?, ?, ?); ";
    return sql;
}

char *timestamp(){
    time_t     now;
    struct tm  ts;
    char *buf=malloc(80);
    time(&now);
    ts = *localtime(&now);

    strftime(buf,80,"%H:%M:%S", &ts);

    return buf;
}

void prepare_stmt(char* prog, char *time, int line, char*file, char* level, char *msg)
{
    sqlite3_stmt* stmt = NULL;
    int rc;
    char *sql= add_statement();

     rc =sqlite3_prepare_v2(db,sql,-1, &stmt,NULL);
    prepare_err_handler(rc);
     rc =sqlite3_bind_text(stmt,1,prog,strlen(prog),NULL);
    insert_err_handler(rc);
     rc =sqlite3_bind_text(stmt,2,time,strlen(time),NULL);
    insert_err_handler(rc);
     rc =sqlite3_bind_int(stmt,3,line);
    insert_err_handler(rc);
     rc =sqlite3_bind_text(stmt,4,file,strlen(file),NULL);
    insert_err_handler(rc);
     rc =sqlite3_bind_text(stmt,5,level,strlen(level),NULL);
    insert_err_handler(rc);
     rc =sqlite3_bind_text(stmt,6,msg,strlen(msg),NULL);
    insert_err_handler(rc);

     rc =sqlite3_step(stmt);
    step_err_handler(rc);

    sqlite3_clear_bindings( stmt );
    sqlite3_reset(stmt);
    sqlite3_finalize(stmt);
}


void log_info(char*prog,int line, char* file,char* msg)
{
    char*time= timestamp();
    char* level ="INFO";
    prepare_stmt(prog,time,line,file,level,msg);
    free(time);
}

void log_warn(char* prog,int line, char* file,char* msg)
{
    char*time= timestamp();
    char* level ="WARNING";
    prepare_stmt(prog,time,line,file,level,msg);
    free(time);
}
void log_error(char*prog,int line, char* file,char* msg)
{
    char*time= timestamp();
    char* level ="ERROR";
    prepare_stmt(prog,time,line,file,level,msg);
    free(time);
}