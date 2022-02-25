#include "log.h"

char *statement_print()
{
    char *sql ="SELECT * FROM ERROR_MESSAGE WHERE PROGRAM=?;";
    return sql;
}

char *print_statement()
{
    char *sql ="SELECT * FROM ERROR_MESSAGE;";
    return sql;
}


void print_table()
{
    sqlite3_stmt* stmt = NULL;
    int rc;
    char *sql= print_statement();
    rc= sqlite3_prepare(db,sql,-1, &stmt,NULL);
    prepare_err_handler(rc);
    
    printf("\nID  |PROGRAM   |TIME      |LINE|FILE            |ERROR_LEVEL|ERROR_MESSAGE\n");

    do{
        rc= sqlite3_step(stmt);
        if (rc == SQLITE_DONE){
            break;
        }
        int one = sqlite3_column_int(stmt,0);
        const unsigned char* two = sqlite3_column_text(stmt,1);
        const unsigned char* three = sqlite3_column_text(stmt,2);
        int four = sqlite3_column_int(stmt,3);
        const unsigned char* five = sqlite3_column_text(stmt,4);
        const unsigned char* six = sqlite3_column_text(stmt,5);
        const unsigned char* seven = sqlite3_column_text(stmt,6);
        printf("%4d|%10s|%10s|%4d|%16s|%11s|%s\n",one,two,three,four,five,six,seven);
    
    } while(rc != SQLITE_DONE);
    rc =sqlite3_reset(stmt);
    rc =sqlite3_finalize(stmt);
}


void prepare_print(char* program)
{
    sqlite3_stmt* stmt = NULL;
    int rc;
    char *sql= statement_print();

    rc= sqlite3_prepare(db,sql,-1, &stmt,NULL);
    prepare_err_handler(rc);

    rc= sqlite3_bind_text(stmt,1,program,strlen(program),SQLITE_TRANSIENT);
    insert_err_handler(rc);
    printf("\nID  |PROGRAM   |TIME    |LINE|FILE        |ERROR_LEVEL|ERROR_MESSAGE\n");

    do{
        rc= sqlite3_step(stmt);
        if (rc == SQLITE_DONE){
            break;
        }
        int one = sqlite3_column_int(stmt,0);
        const unsigned char* two = sqlite3_column_text(stmt,1);
        const unsigned char* three = sqlite3_column_text(stmt,2);
        int four = sqlite3_column_int(stmt,3);
        const unsigned char* five = sqlite3_column_text(stmt,4);
        const unsigned char* six = sqlite3_column_text(stmt,5);
        const unsigned char* seven = sqlite3_column_text(stmt,6);
        printf("%4d|%10s|%8s|%4d|%12s|%11s|%s\n",one,two,three,four,five,six,seven);
    
    } while(rc != SQLITE_DONE);
    rc =sqlite3_reset(stmt);
    rc =sqlite3_finalize(stmt);
}