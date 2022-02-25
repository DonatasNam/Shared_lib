LIB:= liblog.so
CFILES:= log_init.c log_handlers.c log_insert.c log_table.c log_print.c
CFLAGS:= -Wall -fpic -shared
.PHONY: all clean install uninstall

all: $(LIB)

$(LIB): $(CFILES)

	$(CC) $(CFLAGS) -o $@ $^ -l sqlite3

install: $(LIB) 
	install -m 644 log.h /usr/include
	install -m 755 liblog.so /usr/lib
	ln -sf /Shared_lib/lib/$(LIB)


uninstall:
	$(RM) /usr/include/log.h
	$(RM) /usr/lib/liblog.so


clean:
	$(RM) $(LIB)
