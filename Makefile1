OBJS = main.o parse_http.o
CC = g++

p:${OBJS}
	${CC} ${OBJS} -o p
main.o:main.cpp parse_http.h
parse.o:parse_http.cpp parse_http.h
clean:
	rm -f *.o p