# Learn Makefile

```bash
❯ g++ -c main.cpp print_hello.cpp sum_to.cpp
❯ g++ -o prog *.o
❯ ./prog
Hello, this is my cpp!
Sum to 5 is 15
```

**Simple run**

```bash
make             # Compile
make cleanall    # Clean objects and program
```


> The makefile sample is

```
# My Makefile
# This is a comment line
SHELL = /bin/sh
cur_dir := $(shell pwd)

# Program to compiling C programs
CC=g++
# CFLAGS will be the options passed to the compiler. 
CFLAGS= -c -Wall -O2

OBJS= main.o sum_to.o print_hello.o
FOO = $(OBJS:.o=.cpp)

all: hello prog run_test

hello:
	@# disable echoling
	@echo ""
	@echo "* * * * * * * * * * * * * * * * * * * * * * * * *"
	@echo "Current time is" `date`
	@echo "Working dir is" $(cur_dir)
	@echo "* * * * * * * * * * * * * * * * * * * * * * * * *" 
	@echo "Hello GNU Make!" "Nice to meet you" $(USER) "!"
	@echo "* * * * * * * * * * * * * * * * * * * * * * * * *" 

prog: ${OBJS} 
	@echo "Making the target program"
	$(CC) $^ -o $@
	@# equal to $(CC) main.o sum_to.o print_hello.o -o prog
	@echo "* * * * * * * * * * * * * * * * * * * * * * * * *" 
	@echo "Now you got the Program! "
	@echo ""

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

sum_to.o: sum_to.cpp
	$(CC) $(CFLAGS) sum_to.cpp

print_hello.o: print_hello.cpp
	$(CC) $(CFLAGS) print_hello.cpp

run_test:
	./prog

# Phony Targets
.PHONY: cleanall cleanobj

cleanall: cleanobj
	@rm prog

cleanobj:
	@rm *.o

# End
```
