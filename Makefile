CC= gcc
RM= rm -f

CFLAGS= -Wall -Wextra -pedantic -std=c17 -ggdb # -Werror
LIBS= -lm

.PHONY: day01
day01:
	$(CC) $(LIBS) day01.c -o day01.out
	./day01.out < day01.txt
