CC=gcc
CFLAGS=-m64 -O3 -g0
BIN=acquirer

x86_64 :  acquirer.c  
	${CC} acquirer.c  ${CFLAGS} -o ${BIN} 
clean :
	rm -rf acquirer
	rm -rf *.o
