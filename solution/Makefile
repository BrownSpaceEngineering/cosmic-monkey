CC = gcc
CFLAGS = -g3 -Wall -Wextra -Wconversion -Wcast-qual -Wcast-align -g
CFLAGS += -Winline -Wfloat-equal -Wnested-externs
CFLAGS += -pedantic -std=gnu99 -Werror

DEBUG = -DDEBUG

EXECS = cosmic_monkey cosmic_monkey_debug
DEPS = cosmic_monkey.c

.PHONY = all clean

all: $(EXECS)

cosmic_monkey_debug: $(DEPS) 
	$(CC) $(CFLAGS) $(DEBUG) $^ -o $@

cosmic_monkey: $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@

# 33sh: jobs.h jobs.c sh-complete.c
# 	$(CC) $(CFLAGS) $(PROMPT) $^ -o $@

# 33noprompt: jobs.h jobs.c sh-complete.c
# 	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(EXECS)

