CC = gcc
CCFLDB = -g -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector
CCFL = -Wall -Werror -Wextra -std=c11

all:

tests: degree_tests

degree_tests: tests/series_degree_tests.c .bin/analysis-tools.o
	$(CC) $(CCFL) -c $< -o .bin/$@.o
	$(CC) $(CCFL) .bin/$@.o .bin/analysis-tools.o -o ../build/$@

.bin/analysis-tools.o: analysis-tools.c prepare
	$(CC) $(CCFL) -c $< -o $@

prepare:
	mkdir -p .bin

clean:
	rm -rf .bin
	rm ../build/*_tests

rebuild: clean all
