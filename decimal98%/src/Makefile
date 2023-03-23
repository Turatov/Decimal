CC=gcc
CFLAGS= -std=c11 -g -Wall -Wextra -Werror

GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov

LIB_PATH = ../lib
OBJ_PATH = ../lib/obj
LIBS=-lcheck -lm -lpthread

ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)

DBINARY_SRCS =  s21_dbinary.c
DECIMAL_SRCS =  s21_add.c s21_sub.c s21_div.c s21_mul.c \
							 s21_from_decimal_to_float.c s21_from_decimal_to_int.c \
							 s21_from_float_to_decimal.c s21_from_int_to_decimal.c \
							 s21_round.c s21_floor.c s21_truncate.c s21_is_equal.c \
							 s21_is_greater_or_equal.c s21_is_greater.c \
							 s21_is_less_or_equal.c s21_is_less.c s21_dop_decemal.c\
							 s21_is_not_equal.c s21_mod.c s21_negate.c
TESTS = s21_test_add.c s21_test_sub.c s21_test_div.c s21_test_mul.c \
							 s21_test_from_decimal_to_float.c s21_test_from_decimal_to_int.c \
							 s21_test_from_float_to_decimal.c s21_test_from_int_to_decimal.c \
							 s21_test_round.c s21_test_floor.c s21_test_truncate.c s21_test_is_equal.c \
							 s21_test_is_greater_or_equal.c s21_test_is_greater.c \
							 s21_test_is_less_or_equal.c s21_test_is_less.c \
							 s21_test_is_not_equal.c s21_test_mod.c s21_test_negate.c
NAME = test
REPORT_NAME = report
.PHONY: s21_decimal.a s21_dbinary.a

all: test

main:
	gcc -g -c main.c -o out.o
	gcc -g out.o -L . s21_decimal.a -o d 
	./d

s21_dbinary.a:	
	$(CC) $(CFLAGS) $(DBINARY_SRCS) -o s21_dbinary.o -c
	ar rc s21_dbinary.a s21_dbinary.o

l: s21_dbinary.a	
	$(CC) $(CFLAGS) $(DECIMAL_SRCS) -c
	ar rc s21_decimal.a *.o s21_dbinary.a


s21_decimal.a: s21_dbinary.a	
	$(CC) $(CFLAGS) $(DECIMAL_SRCS) -c
	ar rc s21_decimal.a *.o s21_dbinary.a

style:	
	clang-format -i *.c
	clang-format -n *.c

test: s21_decimal.a	
	cd tests && $(CC) $(CFLAGS) ../s21_decimal.a test.c $(TESTS) -o test $(LIBS)
	./tests/test

clean:	
	rm -rf *.o  *.info
	rm -rf *.gcda *.gcno *.out tests/*gcda tests/*gcno
	rm -rf tests/test
	rm -rf report

gcov_report: add_coverage rebuild
	cd tests && ./test
	lcov -t 'test' -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html
	rm -rf *.gcda *.gcno *.out tests/*gcda tests/*gcno

add_coverage:
		$(eval CFLAGS += --coverage)

rebuild: clean test
