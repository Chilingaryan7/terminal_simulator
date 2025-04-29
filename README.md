# Terminal Program

This is a simple terminal program implemented in C. It allows users to execute basic commands and manage environment variables. The program supports commands like `cd`, `exit`, `help`, `history`, and more.

## Features

- Execute system commands like `cd`, `pwd`, `echo`, etc.
- View command history.
- Set and unset environment variables.
- Change the user prompt.

Available Commands
	1.	cd [directory] - Change the current working directory.
	2.	exit - Exit the terminal program.
	3.	help [command] - Show help for a specific command.
	4.	history [count] - Show the last count commands from history.
	5.	pwd - Display the current working directory.
	6.	echo [message] - Print the provided message.
	7.	clear - Clear the terminal screen.
	8.	setenv [VAR=value] - Set an environment variable.
	9.	unsetenv [VAR] - Unset an environment variable.
	10.	chprompt - Change the user prompt.
 
 
## Compilation

To compile the program, simply run the following `make` command:

```bash

make

./terminal

make clean



