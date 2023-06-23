#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void pause_program();
void input_program(int *);
void random_arr(int, int *);
// void out(int, int *);

int main(int argc, char* argv[])
{
    int input, numberOfPages;
    int arr[100];
    input_program(&input);

    switch(input)
    {
        case 1:
            {
                numberOfPages = 11;
                int default_arr[] = {2, 1, 5, 2, 1, 2, 6, 0, 0, 0, 7};
                memcpy(arr, default_arr, sizeof(default_arr));
                break;
            }

        default:
            {
                printf("Please input number of pages: ");
                scanf("%d", &numberOfPages);
                random_arr(numberOfPages, arr);
            }
        // out(numberOfPages, arr);
        return 0;
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
        //system("clear");
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

void random_arr(int numberOfPages, int *arr)
{
    srand(time(NULL));
    for (int i = 0; i < numberOfPages; i++)
    {
        arr[i] = rand() % 10;
    }
}

// void out(int numberOfPages, int *arr)
// {
//     for (int i = 0; i < numberOfPages; i++)
//     {
//         printf("%d\t",arr[i]);
//     }
// }