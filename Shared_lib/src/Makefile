OBJ:= gen
OBJ1:= r_gen
PRINT:= print 
PRINT_SRC:= print.c
CFLAGS:= -Wall
LIB:= -llog 
SRC:= gen.c messages.c 
R_SRC:= r_gen.c 
RM_dir:= rm -r

.PHONY: all clean install uninstall

all: $(OBJ) $(OBJ1) $(PRINT)

$(PRINT): $(PRINT_SRC)

	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(OBJ): $(SRC)

	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(OBJ1): $(R_SRC) 

	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

install: $(OBJ) $(OBJ1) $(PRINT)

	install -d ../programs

	install -m 755 $(PRINT) ../programs
	install -m 755 $(OBJ) ../programs
	install -m 755 $(OBJ1) ../programs

uninstall: 
	$(RM) ../programs/$(OBJ)
	$(RM) ../programs/$(OBJ1)
	$(RM) ../programs/$(PRINT)
clean: 
	$(RM) $(OBJ) 
	$(RM) $(OBJ1)
	$(RM) $(PRINT)
	$(RM_dir) ../programs
	
