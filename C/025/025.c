#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUMBER 0
#define IDENTIFIER 1
#define INVALID 2

int main()
{
    char data[100];
    int i, length, type = NUMBER;
    while (scanf("%s", data))
    {
        length = strlen(data);
        for (i = 0; i < length; i++)
        {
            if(data[i] == '.')
                return 0;
            printf("%c", data[i]);
            if (data[i] >= '0' && data[i] <= '9')
                continue;
            else if((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z') ||
                     data[i] == '_')
            {
                if(type == INVALID)
                    continue;
                type = IDENTIFIER;
            }
            else
                type = INVALID;
        }
        
        if (type == NUMBER)
            printf(" - Number\n");
        else if(type == IDENTIFIER)
            printf(" - Identifier\n");
        else
            printf(" - Invalid\n");
        type = NUMBER;
    }
    return 0;
}
