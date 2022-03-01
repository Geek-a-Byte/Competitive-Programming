#include <stdio.h>
#include <string.h>
int main()
{
    char s[101];
    gets(s);
    char ch[6] = "hello";
    int j = 0, count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ch[j])
        {
            j++;
            count++;
        }
    }
    if (count == 5)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}