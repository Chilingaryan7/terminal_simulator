#include "header.h"

char user_name[USER_NAME_MAX_SIZE] = {0};
int command_count = 0;
char ** history;
int main(){
        status_t terminal_status;
        char command[COMMAND_SIZE] = {0};
        char argument[ARG_SIZE] = {0};
        char * commands[COMMANDS_COUNT] = {"cd", "exit", "help", "history", "pwd", "echo", "clear", "setenv", "unsetenv", "chpromt"};

        history = (char **) calloc(sizeof(char *), 1);
        assert(history != NULL);
        history[command_count] = (char *) calloc(sizeof(char), COMMAND_SIZE);
        assert(history[command_count] != NULL);

        printf("Hello in terminal\nEnter your user name(max 122 sybol): ");

        if(!fgets(user_name, USER_NAME_MAX_SIZE - 2, stdin)){
            perror("fgets error: ");
            exit(EXIT_FAILURE);
        }
        
        user_name[strlen(user_name) - 1] = '\0'; 

        printf("You have this commands: ");
        for(int i = 0; i < COMMANDS_COUNT; ++i){
            printf("%s ", commands[i]);
        }
        putchar('\n');
        while (1){
            fputs(user_name, stdout);
            putchar('>');
            scanf("%s", command);
            strcpy(history[command_count++],command);

            history = (char **) realloc (history,sizeof(char *) * command_count + 1);
            assert(history != NULL);

            history[command_count] = (char *) calloc(sizeof(char), COMMAND_SIZE);
            assert( history[command_count] != NULL);

            terminal_status = WRONG;
            for (int i = 0; i < COMMANDS_COUNT; ++i){
                if (!strcmp(commands[i], command)){
                   
                        if (i == 1){
                            terminal_status = EXIT;
                            printf("Good bye\n");
                            break;
                        }

                        terminal_status = RUN;
                        

                        if (i == 2){
                            scanf("%s", argument);
                            char command[ARG_SIZE] = "help ";
                            strcat(command, argument);
                            system(command);
                            break;
                        }
                        if (i == 9){
                            fflush(stdin);
                            printf("Enter new user name: ");
                            fgets(user_name, USER_NAME_MAX_SIZE - 2, stdin);
                             user_name[strlen(user_name) - 1] = '\0'; 
                            break;
                        }

                        if (i == 0){
                            scanf("%s", argument);
                            if (chdir(argument) < 0){
                                perror("chdir error: ");
                                exit(EXIT_FAILURE);
                            }
                            break;
                        }

                        if (i == 3) {
                            scanf("%s", argument);
                            my_history(atoi(argument));
                            break;
                        }

                        if (i == 7 ){
                            scanf("%s", argument);
                            my_setenv(argument);
                            break;
                        }

                        if (i == 8 ){
                            scanf("%s", argument);
                            unsetenv(argument);
                            break;
                        }

                        if (i == 5 ){
                        fgets(argument, ARG_SIZE - 2, stdin);
                         argument[strlen(argument) - 1] = '\0';
                        create_child(command, argument);
                        break;
                    }

                        else {
                         create_child(command, NULL);
                         break;
                      }
                   }
               }

            if(terminal_status == EXIT){
                break;
            }

            if(terminal_status == WRONG){
                printf("wrong command\n");
            }

        }    
        for(int i = 0; i < command_count; ++i){
            free(history[i]);
            history[i] = NULL;
        }
        free(history);
        history = NULL;
        return 0;
}   

void my_history(int count){
    count = count > command_count ? command_count : count;
    for(int i = command_count - count; i < command_count; ++i){
        fputs(history[i], stdout);
        putchar('\n');
    }
    return ;
}