#include <stdio.h>

#define LINE 256
#define WORD 30

int getLine(char s[]);
int getword(char w[]);
int substring(char *str1, char *str2);
int similar(char *s, char *t, int n);
void print_lines(char *str);
void print_similar_words(char *str);
void print(char *arr, int len);

int main()
{
    char text[WORD] = "hello";
    int textLength = strlen(text);
    print(text,textLength);
    printf("textLength: %d\n",textLength);

    char word[WORD] = {};
    char *p = word;
    for(int i=0;i<WORD - 10;i++){
        *p = 'a' + i;
        p++;
    }
    //int wordSize = getword(word);
    print(word,WORD - 10);
    //printf("wordSize: %d\n",wordSize);
    return 0;
};

void print_lines(char *str){
    while(1){
        char line[LINE] = {0};
        int length = getLine(line);
        if(substring(line,str)){
            printf("----------------\n");
            print(line,length);   
            printf("----------------\n"); 
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

    printf("%c\n", *r);

    while (p != r)
    {
        printf("Entered while: %c\n", *p);
        if (*p == *q)
        {
            printf("%c",*p);
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
            printf("\n");
        }

        if (q == s)
            return 1;
    }
    return 0;
};

int getword(char w[])
{
    int *p = w;
    int charCount = 0;
    char c;
    while (charCount < WORD && (c = getchar()) != '\n' && c != '\t' && c != ' ')
    { // getting word char by char
        *p = c;
        p++;
        charCount++;
    }
    return charCount;
};

int getLine(char s[])
{
    int *p = s;
    int charCount = 0;
    char c;
    while (charCount < LINE && (c = getchar()) != '\n')
    { // getting line char by char
        *p = c;
        p++;
        charCount++;
    }
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