#ifndef HEADER
#define HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include <string.h>
#define USER_NAME_MAX_SIZE 124
#define ARG_SIZE 512
#define COMMAND_SIZE 32
#define HISTORY_SIZE 100
#define COMMANDS_COUNT 10
void create_child(char *, char *);
void my_history(int);
void my_setenv(char *);
typedef enum Status {RUN, EXIT, WRONG} status_t;
#endif 