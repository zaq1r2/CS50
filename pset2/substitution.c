#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


bool validateKey(string key);
int convertCharToNum(char c);
char convertNumToChar(int n);
int stringLength(string s);
string encrypt(string plaintext, string key);
string sanitize(string s);

int main(int argc, string argv[])
{
    if(argc <= 1 || argc > 2 || !validateKey(argv[1]))
    {
        printf("Working\n");
        return 1;
    }
    string key = argv[1];
    string plaintext = get_string("What would you like to encrypt: ");
    string encrypted = encrypt(plaintext, key);
    printf("ciphertext: %s\n", encrypted);
}


bool validateKey(string key)
{
    int length = stringLength(key);
    int n;
    if(length != 26)
    {
        return false;
    }
    int alpha[26];
    for(int i = 0; i < 26; i++)
    {
        alpha[i] = 0;
    }
    for(int i = 0; i < 26; i++)
    {
        n = convertCharToNum(key[i]);
        if(alpha[n] != 0)
        {
            return false;
        }
        else
        {
            alpha[n]++;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(alpha[i] != 1)
        {
            return false;
        }
    }
    return true;
}

int convertCharToNum(char c)
{
    if(isupper(c))
    {
        return (int)c - (int)'A';
    }
    else
    {
        return (int)c - (int)'a';
    }
}

char convertNumToChar(int n)
{
    return (char)(n - 1 + 'a');
}

int stringLength(string s)
{
    int length = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

string encrypt(string plaintext, string key)
{
    int length = stringLength(plaintext);
    char str[length];
    string s = strcpy(str, plaintext);
    s = sanitize(s);
    for(int i = 0; i < length; i++)
    {
        if(isalpha(s[i]))
        {
            int position = convertCharToNum(s[i]);
            if(isupper(plaintext[i]))
            {
                s[i] = toupper(key[position]);
            }
            else
            {
                s[i] = tolower(key[position]);
            }
        }
    }
    return s;
}

string sanitize(string s)
{
    int length = stringLength(s);
    for(int i = 0; i < length; i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}