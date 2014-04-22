CFLAGS:=-Wall -Wextra

all: main
main: main.o

.PHONY: clean
clean:
	$(RM) main main.o
