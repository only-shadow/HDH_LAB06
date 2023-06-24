#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "FIFO.h"

void pause_program();
void input_program(int *);
void random_arr(int, char *);
void out(int, char *);
void input_pageframe(int *);
void choose_algorithm(int *);
void init_matrix(int, int, char(*)[*]);
void out_matrix(int, int, char (*)[*]);

int main(int argc, char* argv[])
{
    int input, numberOfPages, pageFrames, choose, pageErrors;
    char arr[100];
    char arr2[100][100];
    input_program(&input);

    switch(input)
    {
        case 1:
            {
                numberOfPages = 11;
                char default_arr[] = {'2', '1', '5', '2', '1', '2', '6', '0', '0', '0', '7'};
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
    }

    input_pageframe(&pageFrames);
    choose_algorithm(&choose);
    
    
    init_matrix(pageFrames, numberOfPages, arr2);

    return 0;
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

void random_arr(int numberOfPages, char *arr)
{
    srand(time(NULL));
    for (int i = 0; i < numberOfPages; i++)
    {
        arr[i] = rand() % 10;
    }
}

void out(int numberOfPages, char *arr)
{
    for (int i = 0; i < numberOfPages; i++)
    {
        printf("%d\t",arr[i]);
    }
}

void input_pageframe(int *pageframes)
{
    do
    {
        //system("clear");
        printf("--- Page Replacement algorithm ---\n");
        printf("Input page frames: ");
        scanf(" %d", pageframes);

        if (*pageframes < 1)
        {
            printf("Invalid input. Please try again!");
            pause_program();
        }
    } while(*pageframes < 1);
}

void choose_algorithm(int *choose)
{
    do
    {
        //system("clear");
        printf("--- Page Replacement algorithm ---\n");
        printf("1. FIFO algorithm\n");
        printf("2. OPT algorithm\n");
        printf("3. LRU algorithm\n");
        printf("You choose ");
        scanf(" %d", choose);

        if (*choose < 1 || *choose > 3)
        {
            printf("Invalid input. Please try again!");
            pause_program();
        }
    } while(*choose < 1 || *choose > 3);
}

void init_matrix(int numberOfPages, int pageFrames, char (*arr)[numberOfPages])
{
    for (int i = 0; i < numberOfPages; i++)
    for (int j = 0; j < pageFrames + 1; j++)
    {
        arr[j][i] = 2;
    }
}

void out_matrix(int numberOfPages, int pageFrames, char (*arr)[numberOfPages])
{
    for (int i = 0; i < numberOfPages; i++)
    for (int j = 0; j < pageFrames + 1; j++)
    {
        printf("%d\t", arr[j][i]);
    }
}