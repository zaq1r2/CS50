#include <cs50.h>
#include <stdio.h>

int getHeight(void);
void printSpaces(int s);
void printHashes(int n);
void printStairs(int h);

int main(void)
{
    int n = getHeight();
    printStairs(n);
}

int getHeight(void)
{
    int n;
    do
    {
        n = get_int("Enter a number between 1 and 8: ");
    }while(n < 1 || n > 8);
    return n;
}


void printSpaces(int s)
{
    for(int i = 0; i < s; i++)
    {
        printf(" ");
    }
}

void printHashes(int n)
{
    for(int i = 1; i <= 2; i++)
    {
        for(int j = 1; j <= n; j++)
            {
                printf("#");
            }
            if(i == 1)
            {
                printSpaces(2);
            }
            
    }
}

void printStairs(int h)
{
    for(int i = 1; i <= h; i++)
    {
        printSpaces(h-i);
        printHashes(i);
        printf("\n");
    }
}
