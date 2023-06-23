#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void pause_program();
void input_program(int *);

int main(int argc, char* argv[])
{
    int input;
    input_program(&input);
    printf("%d", input);
    
    switch(input)
    {
        case 1:
            {
                break;
            }

        case 2:
            {
                break;
            }
    }
}

void pause_program()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    getchar();
}

void input_program(int *input)
{
    do
    {
        system("clear");
        printf("--- Page Replacement algorithm ---\n");
        printf("1. Default referenced sequence\n");
        printf("2. Manual input sequence\n");
        printf("You choose: ");
        scanf(" %d", input);

        if (*input < 1 || *input > 2)
        {
            printf("Invalid input. Please try again!");
            pause_program();
        }
    } while (*input < 1 || *input > 2);

}