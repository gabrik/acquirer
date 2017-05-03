CC=gcc
CFLAGS=-m64 -O3 -g0
BIN=acquirer

#for unikernel
RUMPCC=x86_64-rumprun-netbsd-gcc
RUMPBAKE=rumprun-bake
BAKEFLAGS=hw_virtio
KERNEL_FILE=acquirer.bin
RUMPBIN=acquirer-rump

x86_64 :  acquirer.c  
	${CC} acquirer.c  ${CFLAGS} -o ${BIN} 

unikernel: acquirer.c
	${RUMPCC} acquirer.c -o ${RUMPBIN}
	${RUMPBAKE} ${BAKEFLAGS} ${KERNEL_FILE} ${RUMPBIN}


clean :
	rm -rf acquirer
	rm -rf ${KERNEL_FILE} ${RUMPBIN}
	rm -rf *.o
