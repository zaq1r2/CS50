#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int get_word_count(string s);
int get_letter_count(string s);
int get_sentence_count(string s);
int get_index(int wc, int lc, int sc);


int main(void)
{
    string str = get_string("Enter a string plz: ");
    int lc = get_letter_count(str);
    int wc = get_word_count(str);
    int sc = get_sentence_count(str);
    int index = get_index(wc,lc,sc);
    if(index < 1)
        printf("Before Grade 1\n");
    else if(index > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", index);
}

int get_word_count(string s)
{
    int count = 0;
    int length = strlen(s);
    for(int i = 0; i < length - 1; i++)
    {
        if((count == 0 && isalpha(s[i])) || (isspace(s[i]) && isalpha(s[i+1])))
        {
            count++;
        }
    }
    return count;
}
int get_letter_count(string s)
{
    int count = 0;
    int length = strlen(s);
    for(int i = 0; i < length; i++)
    {
        if(isalpha(s[i]))
        {
            count++;
        }
    }
    return count;
}
int get_sentence_count(string s)
{
    int count = 0;
    int length = strlen(s);
    for(int i = 0; i < length; i++)
    {
        if(s[i] == '?' || s[i] == '!' || s[i] == '.' )
        {
            count++;
        }
    }
    return count;
}
int get_index(int wc, int lc, int sc)
{

    float multiplier = (float) 100 / (float)wc;
    float lc_per_wc = lc * multiplier;
    float sc_per_wc = sc * multiplier;
    float float_index = 0.0588 * lc_per_wc - 0.296 * sc_per_wc - 15.8;
    float rounded_index = round(float_index);
    return (int)rounded_index;
}

