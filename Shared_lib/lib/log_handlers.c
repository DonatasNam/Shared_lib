#include "log.h"

void open_err_handler(int rc){
    if(SQLITE_OK != rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    } 
}

void insert_err_handler(int rc)
{
    if(SQLITE_OK != rc) {
		fprintf(stderr, "Error binding value in insert (%i): %s\n", rc, sqlite3_errmsg(db));
		sqlite3_close(db);
    }
}
void prepare_err_handler(int rc)
{
    if(SQLITE_OK != rc) {
		fprintf(stderr, "Can't prepare select statment (%i): %s\n", rc, sqlite3_errmsg(db));
		sqlite3_close(db);
        sqlite3_free(err);
	}
}
void step_err_handler(int rc)
{
    if(SQLITE_DONE != rc) {
		fprintf(stderr, "insert statement didn't return DONE (%i): %s\n", rc, sqlite3_errmsg(db));
    }
}
