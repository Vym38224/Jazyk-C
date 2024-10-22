// Napište program, který spojí dva textové řetězce (zadané přímo ve funkci main()). Ve funkci vytvořte nový řetězec a ten pak vypište.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str1 = "Hello, ";
    char *str2 = "world!";
    int len1 = 0;
    int len2 = 0;
    while (str1[len1] != '\0')
    {
        len1++;
    }
    while (str2[len2] != '\0')
    {
        len2++;
    }
    char *str3 = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (str3 == NULL)
    {
        printf("Memory allocation failed for str3.\n");
        return 1;
    }
    for (int i = 0; i < len1; i++)
    {
        str3[i] = str1[i];
    }
    for (int i = 0; i < len2; i++)
    {
        str3[len1 + i] = str2[i];
    }
    str3[len1 + len2] = '\0';
    printf("%s\n", str3);
    free(str3);
    return 0;
}