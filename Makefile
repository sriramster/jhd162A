CFLAGS= -Wall -Wshadow -Wwrite-strings -Wsign-compare -Wfloat-equal \
	-Wmissing-noreturn -Wbad-function-cast \
	-Wmissing-prototypes -Winline -Wredundant-decls -O3
all:
	gcc $(CFLAGS) -DDEBUG lcd.c -o bb
	strip bb
