#include "header.h"
void my_setenv(char * arg){
        pid_t child = fork();
    int status = 0;
    if(child < 0){
        perror("fork error: ");
        exit(EXIT_FAILURE);
    }

     if (child == 0) {
        char *eq_pos = strchr(arg, '=');
        if (!eq_pos) {
            printf("wrong argument\n");
            exit(EXIT_FAILURE);
        }

        size_t name_len = eq_pos - arg;
        char *name = strndup(arg, name_len);
        char *value = strdup(eq_pos + 1);

        if (name == NULL || value == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        if (setenv(name, value, 1)) {
            perror("setenv error");
            free(name);
            free(value);
            exit(EXIT_FAILURE);
        }

        free(name);
        free(value);
        exit(EXIT_SUCCESS);
     }
        if(child){
            waitpid(child, &status, 0);
            if(WIFSIGNALED(status)){
                printf("child status =  %d\n", WTERMSIG(status));
            }

            if(WIFSTOPPED(status)){
                 printf("child status =  %d\n", WSTOPSIG(status));
            }
    }
    return;
}
void create_child(char * command, char * argument){
    pid_t child = fork();
    int status = 0;
    if(child < 0){
        perror("fork error: ");
        exit(EXIT_FAILURE);
    }

    if(!child){
        if(execlp(command, command, argument, NULL) == -1){
            perror("execlp error: ");
            exit(EXIT_FAILURE);
            }    
        }

        if(child){
            waitpid(child, &status, 0);
            if(WIFSIGNALED(status)){
                printf("child status =  %d\n", WTERMSIG(status));
            }

            if(WIFSTOPPED(status)){
                 printf("child status =  %d\n", WSTOPSIG(status));
            }
    }
    return;
}