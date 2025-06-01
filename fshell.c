#include <stdio.h>
#define MAX_INPUT 1024



int main (void) {
    char input[MAX_INPUT];

    while(1) {
        printf("fsh>: ");
        fgets(input,MAX_INPUT,stdin);

        printf("You typed this command: %s \n", input);
    }
    return 0;
}
// work in progess run at your own risk 