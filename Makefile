student: addstud.o deletestud.o showstud.o modifystud.o savestud.o sortstud.o main.o
	cc addstud.o deletestud.o showstud.o modifystud.o savestud.o sortstud.o main.o -o student

addstud.o: addstud.c header.h
	cc -c addstud.c

deletestud.o: deletestud.c header.h
	cc -c deletestud.c

showstud.o: showstud.c header.h
	cc -c showstud.c

modifystud.o: modifystud.c header.h
	cc -c modifystud.c

savestud.o: savestud.c header.h
	cc -c savestud.c

sortstud.o: sortstud.c header.h
	cc -c sortstud.c

main.o: main.c header.h
	cc -c main.c

clean:
	rm -f *.o student
