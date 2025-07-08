#include <stdio.h>
#include <string.h>

#define MAX_INPUT 1024



int main (void) {
    char input[MAX_INPUT];

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
        
    }
    return 0;
}
// work in progess run at your own risk 