CFLAGS = -Wall -Wextra

test: test.o sha256.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c sha256.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f test test.o sha256.o
