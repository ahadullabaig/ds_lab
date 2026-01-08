#include <stdio.h>
#include <stdlib.h>

char* concatenate(char* s1, char* s2)
{
    int len1 = 0, len2 = 0;

    while(s1[len1] != '\0')
    {
        len1++;
    }

    while(s2[len2] != '\0')
    {
        len2++;
    }

    char* s = (char*) malloc(len1 + len2 + 1);

    for(int i=0; i<len1; i++)
    {
        s[i] = s1[i];
    }

    for(int i=0; i<=len2; i++)
    {
        s[len1 + i] = s2[i];
    }

    return s;
}

int palindrome(char* s)
{
    int len = 0;

    while(s[len] != '\0')
    {
        len++;
    }
    
    for (int i=0; i<len; i++)
    {
        if (s[i] != s[len - 1 - i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char* s1 = "nayan";
    char* s2 = " N";

    char* s = concatenate(s1, s2);

    printf("%s\n", s);

    free(s);

    if(palindrome(s1))
        printf("Palindrome\n");
    else
        printf("NP\n");

    return 0;
}
