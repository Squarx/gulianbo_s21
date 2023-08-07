CFLAGS= -Wall -Werror -Wextra -std=c11 -D_GNU_SOURCE

all: s21_grep

s21_grep:
	gcc ${CFLAGS} s21_grep.c -o s21_grep

style : s21_grep
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	$(pwd)
	cp ../../materials/linters/.clang-format ./
	clang-format -n ./*.c ./*.h
	rm -rf ./.clang-format
test: s21_grep
	cp ./test_grep/* ./
	bash test_func_grep.sh
	make clean
testL: s21_grep
	sh test_leak_grep.sh
clean:
	rm -rf s21_grep
	rm -rf *.txt
	rm -rf *.sh
	rm -rf *.log
	rm -rf CPPLINT.cfg
	rm -rf ./.clang-format
