terminal: main.c lib.c
	gcc -Wall main.c lib.c -o terminal

clean:
	rm -f terminal
