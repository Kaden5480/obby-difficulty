CC ?= cc
CFLAGS ?= -march=native -O2 -pipe

CFLAGS := $(CFLAGS) -Wall -Wextra -Werror

OBJS := src/main.o src/args.o src/calc.o

.PHONY: build clean

build: obby-diff

clean:
	rm -f $(OBJS) obby-diff

obby-diff: $(OBJS)
	$(CC) $(CFLAGS) -Xlinker --strip-all -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<
