#include "log.h"


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

char * statement_table()
{
    
    char *sql="CREATE TABLE ERROR_MESSAGE(ID INTEGER PRIMARY KEY AUTOINCREMENT, PROGRAM TEXT, TIME TEXT, LINE INT, FILE TEXT,ERROR_LEVEL TEXT, ERROR_MESSAGE TEXT);";

    
    return sql;
}

void create_table()
{

    char *sql= statement_table();
    sqlite3_exec(db, sql, callback, 0, &err);
    
}

