OBJS = main.o parse_http.o
CC = g++

p:${OBJS}
	${CC} ${OBJS} -o p
main.o:main.cpp parse_http.h
	${CC} -c main.cpp -o main.o
parse.o:parse_http.cpp parse_http.h
	${CC} -g -c parse_http.cpp -o parse_http.o
clean:
	rm -f *.o p