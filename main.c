#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int special_case(int x)
{
    if (x==0)
    {
        printf("0\n");
        return 1;
    }

    if (x==-1)
    {
        printf("-1\n");
        return 1;
    }

    if (x == 1)
    {
        printf ("1\n");
        return 1;
    }

    return 0;
}

int check_arg_user (int argc, char* argv[])
{
    if (argc != 2)
    {
        printf ("Usage: %s <NUM>\n\tWhere <NUM> is the number for factorization\n", argv[0]);
        return 1;
    }

    char* string = argv[1];
    int i = 0;
    while (string[i]!='\0')
    {
        if (!( (string[i]>='0' && string[i]<='9') || string[i]=='-'))
        {
            printf ("This is not a number, check the entered data\n");
            return 1;
        }
        i++;
    }

    if (string[0]=='-')
    {
        i--;
    }

    if (i>9)
    {
        printf ("The number is too large, enter less\n");
        return 1;
    }

    return 0;
}

int main(int argc, char* argv[])
{
    if (check_arg_user (argc, argv))
    {
        return 1;
    }
    
    int num = atoi (argv[1]);

    if (special_case (num))
    {
        return 0;
    }
    
    if (num<0)
    {
        printf ("-1*");
        num = abs (num);
    }

    char* out_string=factorization(num);
    out_string[strlen (out_string) - 1] = '\0';
    printf("%s\n",out_string);
    
    return 0;
}