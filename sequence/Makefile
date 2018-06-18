.PHONY:clean
sequence:sequence.o
	gcc -g $^ -o $@
%.o:%.c
	gcc -c -g $^ -o $@
clean:
	rm -rf *.o sequence
