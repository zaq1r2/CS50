#include <stdio.h>
#include <cs50.h>

long getCardNumber();
int getDigits(long n);
int getStartingDigits(long n, int d);
int getSum(long n);
bool checkVisa(int n, int s);
bool checkAmex(int n, int s);
bool checkMaster(int n, int s);
bool sumChecker(int sum);
string checkCard(int n, int s, int sum);

int main(void)
{   
    long card_number = getCardNumber();
    int num_digits = getDigits(card_number);
    int start_digits = getStartingDigits(card_number, num_digits);
    int sum = getSum(card_number);
    string card_type = checkCard(num_digits, start_digits, sum);
    
    printf("%s\n", card_type);
}

long getCardNumber()
{
    long n = get_long("What's the number? ");
    return n;
}

int getDigits(long n)
{
    int count = 0;
    while(n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

int getStartingDigits(long n, int d)
{
    int count = 0;
    while(d-count > 2)
    {
        n /= 10;
        count++;
    }
    return (int) n;
}

int getSum(long n)
{
    int sum = 0;
    int sum2 = 0;
    int r;
    int count = 0;
    int digit;
    while(n>0)
    {
        r = n % 10;
        n /= 10;
        if(count % 2 == 0)
        {   
            sum += r;
        }
        else
        {
            r *= 2;
            while(r > 0)
            {
                digit = r % 10;
                sum2 += digit;
                r /=10;
            }
        }
        count++;
    }
    return sum2 + sum;
}

bool checkVisa(int n, int s)
{
    if((n == 13 || n == 16) && s > 39 && s < 50)
    {
        return true;
    }
    return false;
}
bool checkAmex(int n, int s)
{
    if(n == 15 && (s == 34 || s == 37))
    {
        return true;
    }
    return false;
}
bool checkMaster(int n, int s)
{
    if(n == 16 && s > 50 && s < 56)
    {
        return true;
    }
    return false;
}

bool sumChecker(int sum)
{
    if(sum % 10 == 0)
    {
        return true;
    }
    return false;
}

string checkCard(int n, int s, int sum)
{
    if(sumChecker(sum))
    {
        if(checkVisa(n,s))
        {
            return "VISA";
        }
        else if(checkAmex(n,s))
        {
            return "AMEX";
        }
        else if(checkMaster(n,s))
        {
            return "MASTERCARD";
        }
        else
        {
            return "INVALID";
        }
    }
    else
    {
        return "INVALID";
    }
}