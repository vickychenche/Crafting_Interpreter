CFLAGS = -g -Wall -Werror -fsanitize=address

all: main

main: main.o chunk.o memory.o debug.o value.o vm.o
	gcc ${CFLAGS} -o $@ $^ 

%.o: %.c chunk.h common.h memory.h debug.h value.h vm.h
	gcc ${CFLAGS} -c $< -o $@

clean:
	rm -f *.o main