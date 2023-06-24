#include <stdio.h>
#define MIN(x, y) ((x) < (y) ? (x) : (y))

void change_pos(int *, int);

int FIFO(int numberOfPages, int pageFrames, int pageErrors, char *arr, char (*arr2)[numberOfPages])
{
    int x = MIN(numberOfPages, pageFrames);
    for (int i = 0; i < x; i++)
    for (int j = 0; j < x; j++)
    {
        if(i == j)
        {
            arr2[i][i] = arr[i];
            arr2[pageFrames + 1][i] = '*';
            pageErrors++;
        }
        if(j < i)
        {
            arr2[j][i] = arr2[j][i-1];
        }
    }

    int pos = 0;
}

void change_pos(int *pos, int pageFrame)
{
    *pos ++;
    *pos = (*pos) % pageFrame;
}