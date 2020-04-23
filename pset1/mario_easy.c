#include <cs50.h>
#include <stdio.h>

int getHeight(void);
void printStairs(int h);

int main(void)
{
    int height = getHeight();
    printStairs(height);
}


int getHeight(void)
{
    int n;
    do
    {
        n = get_int("Please enter a number between 1 and 8: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void printStairs(int h)
{
    for (int j = 1; j <= h; j++)
    {
        for (int k = 0; k < h-j; k++)
        {
            printf(" ");
        }
       for (int i = 0;i<j ; i++)
       {
           printf("#");
       }    
       printf("\n");
    }
}