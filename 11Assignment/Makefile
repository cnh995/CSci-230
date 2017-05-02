HEADERS = *.h

all: hw11-ChristianHansen-A.c hw11-ChristianHansen-B.c hw11-ChristianHansen-C.c hw11-ChristianHansen-D.c $(HEADERS)
	gcc -Wall -c hw11-ChristianHansen-A.c hw11-ChristianHansen-B.c hw11-ChristianHansen-C.c hw11-ChristianHansen-D.c
	ar -cvq hw11-lib-ChristianHansen.a *.o
	gcc hw11-ChristianHansen-4.c -ldl -o hw11-ChristianHansen-4
	gcc -c -fPIC hw11-ChristianHansen-A.c hw11-ChristianHansen-B.c hw11-ChristianHansen-C.c hw11-ChristianHansen-D.c
	gcc -shared -o hw11-lib-ChristianHansen.so hw11-ChristianHansen-A.o hw11-ChristianHansen-B.o hw11-ChristianHansen-C.o hw11-ChristianHansen-D.o
	export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
