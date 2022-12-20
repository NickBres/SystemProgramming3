#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

int getLine(char s[]);
int getword(char *w);
int substring(char *str1, char *str2);
int similar(char *s, char *t, int n);
void print_lines(char *str);
void print_similar_words(char *str);
void print(char *arr, int len);

int main()
{
    char word[WORD] = {0};
    int wordSize = getword(word);
    printf("Word : ");
    print(word,wordSize);

    char f = getchar();
    if(f == 'a'){
        printf("Print lines function:\n");
        print_lines(word);
    }else if (f == 'b'){
        printf("Print similar words function:\n");
        print_similar_words(word);
    }
    return 0;
};

void print_similar_words(char *str){
    while(1){
        char word[WORD] = {0};
        int length = getword(word);
        if(length >= (int)strlen(str) && similar(word,str,1)){
            printf("Similar word: ");
            print(word,length); 
        } 
        bzero(word,WORD);
    }
}

void print_lines(char *str){
    while(1){
        char line[LINE] = {0};
        int length = getLine(line);
        if(substring(line,str)){
            print(line,length); 
        } 
        bzero(line,LINE);
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
        if (*p == *q)
        {
            p++;
            q++;
        }
        else
        {
            p++;
            count++;
        }
        if (count > n)
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
        
        if (*p == *q)
        {  
            q++;
            p++;
        }
        else if (q == str2)
        {
            p++;
        }
        else // return q to the start of str2
        {
            q = str2;
        }

        if (q == s)
            return 1;
    }
    return 0;
};

int getword(char w[])
{
    char *p = w;
    int charCount = 0;
    char c;
    while (charCount < WORD && (c = getchar()) != '\n' && c != '\t' && c != ' ')
    { // getting word char by char
        *p = c;
        p++;
        charCount++;
    }
    *p = '\0';
    charCount++;
    return charCount;
};

int getLine(char s[])
{
    char *p = s;
    int charCount = 0;
    char c;
    while (charCount < LINE - 1 && (c = getchar()) != '\n')
    { // getting line char by char
        *p++ = c;
        charCount++;
    }
    *p = '\0';
    charCount++;
    return charCount;
};

void print(char *arr, int len)
{
    char *p = arr;
    char *r = arr + len;
    while (p != r)
    {
        printf("%c", *p);
        p++;
    }
    printf("\n");
};