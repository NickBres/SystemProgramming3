#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

int getLine(char s[]);                 // get line from stdin char by char
int getword(char *w);                  // get word from stdin char by char
int substring(char *str1, char *str2); // check if str2 is substring of str1
int similar(char *s, char *t, int n);  // check if s is similar to t with n changes
void print_lines(char *str);           // print lines that contain str
void print_similar_words(char *str);   // print words that are similar to str
void print(char *arr);                 // print string

int main()
{
    char word[WORD] = {0};
    getword(word);

    char f = getchar();
    if (f == 'a')
    {
        print_lines(word);
    }
    else if (f == 'b')
    {
        print_similar_words(word);
    }
    return 0;
};

void print_similar_words(char *str)
{
    int length = 1;
    while (length < WORD)
    {
        char word[WORD] = {0};
        length = getword(word);
        if (length >= (int)strlen(str) && similar(word, str, 1))
        {
            print(word);
        }
    }
}

void print_lines(char *str)
{
    int length = 1;
    while (length < LINE)
    {
        char line[LINE] = {0};
        length = getLine(line);
        if (substring(line, str))
        {
            print(line);
        }
    }
}

int similar(char *s, char *t, int n)
{
    char *p = s;
    char *q = t;
    char *pe = s + strlen(s);
    int count = 0;
    while (p != pe)
    {
        if (*p == *q) // same char in both strings
        {
            p++;
            q++;
        }
        else // different char
        {
            p++;
            count++;
        }
        if (count > n) // to much need to delete
            return 0;
    }
    return 1;
};

int substring(char *str1, char *str2)
{
    char *p = str1;
    char *q = str2;
    char *r = str1 + strlen(str1);
    char *s = str2 + strlen(str2);

    while (p != r)
    {

        if (*p == *q) // same char in both strings
        {
            q++;
            p++;
        }
        else if (q == str2) // q is at the start of str2 and chars are different
        {
            p++;
        }
        else // chars are different, return q to the start of str2
        {
            q = str2;
        }

        if (q == s) // all chars in str2 were found in str1
            return 1;
    }
    return 0;
};

int getword(char w[])
{
    char *p = w;
    int charCount = 0;
    char c;
    while (charCount < WORD - 1 && (c = getchar()) != '\n' && c != '\t' && c != ' ') // get char by char until space, tab or new line. keep the last char for \0
    {                                                                                // getting word char by char
        *p++ = c;
        charCount++;
    }
    return charCount + 1; // +1 for \0 at the end of the string
};

int getLine(char s[])
{
    char *p = s;
    int charCount = 0;
    char c;
    while (charCount < LINE - 1 && (c = getchar()) != '\n') // get char by char until new line. keep the last char for \0
    {                                                       // getting line char by char
        *p++ = c;
        charCount++;
    }
    return charCount + 1; // +1 for \0 at the end of the string
};

void print(char *arr)
{
    char *p = arr;
    while (*p) // print char by char until \0
    {
        printf("%c", *p);
        p++;
    }
    printf("\n");
};