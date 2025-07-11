#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024

void WelcomeMessage(void);

int main (void) {
    char input[MAX_INPUT];

    WelcomeMessage();

    while(1) {
        printf("ffsh>: ");
        fgets(input,MAX_INPUT,stdin);

        input[strcspn(input, "\n")] = 0;

        // if input is empty just ignore the command
        if (input[0] == '\0') {
            continue;
            }

        if (strcmp(input, "exit") == 0) {
            printf("Exiting... \n");
            break;
        }
        
        // Standard way to fork proccesses, duplicates the process, and we let the child execute commands
        pid_t pid = fork();

        if (pid == 0) {
            // childPID = 0 
        }
        else if (pid > 0) {
            // parentPID > 0
        }
        else {
            // if fork fails for some reason, output an error
            perror("fork");
        }
    }
    return 0;
}

void WelcomeMessage(void) {
    printf("=====================================\n");
    printf("  Welcome to FFSH - Fast & Flexible Shell!\n");
    printf("  Type 'exit' to quit.\n");
    printf("=====================================\n\n");
}
// work in progess run at your own risk 