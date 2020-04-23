#include <stdio.h>
#include <cs50.h>
#include <math.h>

float getMoney(void);
int countChange(int cents);
int main(void)
{
    float money = getMoney();
    int cents = round(money * 100);
    int count = countChange(cents);
    printf("hello %i", count);
}

float getMoney(void)
{
    float money;
    do
    {
        money = get_float("How much? ");
    }
    while(money < 0);
    return money;
}

int countChange(int cents)
{
    int count = 0;
    while(cents > 0)
    {
        if(cents >= 25)
        {
            cents -= 25;
            count++;
        }
        else if(cents >= 10)
        {
            cents -= 10;
            count++;
        }
        else if(cents >= 5)
        {
            cents -= 5;
            count++;
        }
        else if(cents >= 1)
        {
            cents -= 1;
            count++;
        }
    }
    return count;
}
