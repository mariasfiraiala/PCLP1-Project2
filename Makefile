#Copyright Maria Sfiraiala (maria.sfiraiala@stud.acs.upb.ro)
# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# pickp all sources
SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)

# define targets
TARGETS=my_octave

build: $(OBJS) $(TARGETS)

my_octave: my_octave.c
	$(CC) $(CFLAGS) $@.o -o $@

clean:
	rm -f $(TARGETS) $(OBJS)

