all: mainfile.o tablecheck.o encryption.o
	gcc -g  mainfile.o tablecheck.o  encryption.o -o hw4  -lm

mainfile.o: mainfile.c hw4.h
	gcc -c -g -Wall mainfile.c  

tablecheck.o: tablecheck.c hw4.h
	gcc -c -g -Wall tablecheck.c  

encryption.o: encryption.c hw4.h
	gcc -c -g -Wall encryption.c 



clean:
	rm *.o
	rm hw4
