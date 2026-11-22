all: a.out

a.out: main.c header.h addstud.c deletestud.c showstud.c modifystud.c savestud.c sortstud.c
	cc main.c addstud.c deletestud.c showstud.c modifystud.c savestud.c sortstud.c

clean:
	rm -f a.out *.o
