#The compiler
CC:=gcc
#The flags
CFLAGS:=-Wall -Wextra -std=gnu11 -g -fsanitize=address -fsanitize=leak -O3
LDFLAGS:=-lm
NAME:=demineur

all: main.o $(NAME).o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(NAME).o: $(NAME)/$(NAME).c $(NAME)/$(NAME).h
	$(CC) -c $< $(CFLAGS)

main.o: main.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o all

rebuild: clean all