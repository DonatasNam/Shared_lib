#include "log.h"

void dbclose()
{
    sqlite3_close(db);
}

void dbopen(char *filename)
{
    int rc =sqlite3_open(filename, &db);
    open_err_handler(rc);
}
