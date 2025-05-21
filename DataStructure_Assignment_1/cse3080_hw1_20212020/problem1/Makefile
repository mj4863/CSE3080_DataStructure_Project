cc = gcc
target = hw1_naive hw1_kmp
all : $(target)

hw1_naive : hw1_naive.c
	$(cc) -o $@ $^
hw1_kmp : hw1_kmp.c
	$(cc) -o $@ $^

clean :
	rm $(target)