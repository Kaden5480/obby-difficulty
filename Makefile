CC ?= cc
CFLAGS ?= -march=native -O2 -pipe

CFLAGS := $(CFLAGS) -Wall -Wextra -Werror

OBJS := src/main.o \
		src/cmd/cmd.o \
		src/cmd/parse.o \
		src/lib/calc.o \
		src/lib/display.o

.PHONY: build clean

build: obby-diff

clean:
	rm -f $(OBJS) obby-diff

obby-diff: $(OBJS)
	$(CC) $(CFLAGS) -Xlinker --strip-all -o $@ -lm $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<
