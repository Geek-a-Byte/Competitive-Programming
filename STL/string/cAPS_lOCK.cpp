#include <stdio.h>
#include <string.h>
int main()
{
    char c[101], s[101], flag;
    scanf("%s", c);
    int l = strlen(c);

    for (int i = 1; c[i] != '\0'; i++)
    {

        if (c[i] < 91)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (l == 1 && c[0] > 96)
    {
        c[0] = c[0] - 32;
        printf("%s", c);
        return 0;
    }

    if (flag == 1 && c[0] < 91 || flag == 1 && c[0] > 96)
    {
        for (int i = 0; i < l; i++)
        {
            if (c[i] < 91)
                c[i] = c[i] + 32;
            else if (c[i] > 96)
            {
                c[i] = c[i] - 32;
            }
        }
    }
    printf("%s", c);
}