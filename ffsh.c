#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024 
#define MAX_ARGS 64 

void welcome_message(void);
void parse_input(char *input, char **args);

int main(void) 
{
    char input[MAX_INPUT]; // input buffer of 1024 chars
    char *args[MAX_ARGS];  // input buffer of 64 args (strings)

    welcome_message(); // display welcome message when starting ffsh

    while (1) // main shell loop
    { 
        printf("ff$h>: "); // prompt user input with ff$h>: 
        fgets(input, MAX_INPUT, stdin); // get user input 

        input[strcspn(input, "\n")] = 0; // remove newline character from input commands

        if (input[0] == '\0') // if input is nothing, just ignore it and continue
        { 
            continue;
        }

        if (strcmp(input, "exit") == 0) // if input is 'exit' break the loop and print a exit message
        {
            printf("Exiting ff$h... \n");
            break;
        }
        if (strcmp(input, "welcome") == 0) // if input is "welcome" print the welcome message again and continue
        {
            welcome_message();
            continue;
        }

        parse_input(input, args); 

        pid_t pid = fork(); // fork the proccess and assign a pid_t to variable pid

        if (pid == 0) // if pid = 0 then its a child proccess
        {
            if (execvp(args[0], args) == -1)  // to check the if statement, the child runs the argument "ls" and if it executes properly the rest of the code is ignored
            {
                perror("ff$h"); // we must print an error message if execvp() fails
            }
            exit(EXIT_FAILURE); // same as exit(1), just more standardized, returns a 1
        }
        else if (pid > 0) // if pid > 0 then its a parent proccess
        {
            wait(NULL); // parent proccess waits for the child proccess before proceeding
        }
        else 
        {
            perror("fork"); // provide a error message if this fork fails
        }
    }
    return(0); 
}

void welcome_message(void) // simple function to display a welcome message
{
    printf("=====================================\n");
    printf("  Welcome to FFSH - Fast & Flexible Shell!\n");
    printf("  Type 'exit' to quit.\n");
    printf("  Type 'cat README.md' to display README\n");
    printf("  Type 'welcome' to display this welcome message again\n");
    printf("=====================================\n\n");
} // consider making these into string literals in the future if wanting to add custom message function

void parse_input(char *input, char *args[])
{
    int i = 0; // counter variable
    args[i] = strtok(input, " "); // split string/tokenize with strtok() put it the strings back into "args" array as indexes. 
    // if for example: ls README.md, then we split 2 args, "ls" and "README.md"

    while (args[i] != NULL && i < MAX_ARGS - 1) { // while the argument is not equal to a NULL value, and i is less than the MAX_ARGS 
        i++;
        args[i] = strtok(NULL, " "); // strtok(NULL, " ") continues tokenizing the same string
    }
    args[i] = NULL; // ensure the last argument is NULL terminated
}
