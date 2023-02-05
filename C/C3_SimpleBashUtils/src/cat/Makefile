CFLAGS= -Wall -Werror -Wextra -std=c11 -D_GNU_SOURCE
all: s21_cat

s21_cat:
	gcc ${CFLAGS} s21_cat.c -o s21_cat

check: s21_cat
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	$(pwd)
	cp ../../materials/linters/.clang-format ./
	clang-format -n ./*.c ./*.h
	rm -rf ./.clang-format
	rm -rf CPPLINT.cfg
test: s21_cat
	cp ./test_cat/* ./
	sh test_func_cat.sh
	sh test_leak_cat.sh
	make clean

clean:
	rm -rf s21_cat
	rm -rf test_s21_cat.log
	rm -rf test_sys_cat.log
	rm -rf *.txt
	rm -rf *.sh
	rm -rf *.log
	rm -rf CPPLINT.cfg
	rm -rf ./.clang-format