#include <stdio.h>
#include <string.h>

#define MAX_INPUT 1024



int main (void) {
    char input[MAX_INPUT];

    while(1) {
        printf("fsh>: ");
        fgets(input,MAX_INPUT,stdin);

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting... \n");
            break;
        }

        printf("Unknown command: %s \n", input);
    }
    return 0;
}
// work in progess run at your own risk 