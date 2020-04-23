#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

bool isValidKey(string key);
int stringLength(string s);
int getShiftValue(string key);
string encrypt(string plaintext, int shift);


int main(int argc, string argv[])
{
    if(argc <= 1 || argc > 2 || !isValidKey(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string key = argv[1];
    int keyLength = stringLength(key);
    int shift = getShiftValue(key);
    string plaintext = get_string("What would you like to encrypt? ");
    string encrypted = encrypt(plaintext, shift);
    printf("ciphertext: %s\n",encrypted);
}


bool isValidKey(string key)
{
    int length = stringLength(key);
    for(int i = 0; i < length; i++)
    {
        if(isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
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

int getShiftValue(string key)
{
    return atoi(key);
}


string encrypt(string plaintext, int shift)
{
    int length = stringLength(plaintext);
    for(int i = 0; i < length; i++)
    {
        if(isalpha(plaintext[i]) && isupper(plaintext[i]))
        {
            plaintext[i] = plaintext[i] - (int)'A';
            plaintext[i] = ((int)plaintext[i] + shift) % 26;
            plaintext[i] = plaintext[i] + (int)'A';
        }
        else if(isalpha(plaintext[i]) && islower(plaintext[i]))
        {
            plaintext[i] = plaintext[i] - 'a';
            plaintext[i] = ((int)plaintext[i] + shift) % 26;
            plaintext[i] = plaintext[i] + 'a';
        }
    }
    return plaintext;
}