#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

typedef int (*callback)(int,int);

extern int factorization(int x, callback cb);

int check_arg_user (int argc, char* argv[])
{
    if (argc != 2)
    {
        printf ("Usage: %s <NUM>\n\tWhere <NUM> is the number for factorization\n", argv[0]);
        return 1;
    }

    long int num=strtol(argv[1], NULL, 10);
    if (errno==ERANGE || num>100000000)
    {
        printf("Your number too large, put less number\n");
        return 1;
    }

    return 0;
}

int print_res(int x, int y)
{
    if (y==1)
    {
        printf("%d\n",x);
        return 0;
    }

    printf("%d*",x);
    return 0;
} 

void factorize(int x)
{
    if (x==0)
    {
        printf("0");
        return;
    }

    if (x==1)
    {
        printf("1");
        return;
    }

    if (x==-1)
    {
        printf("-1");
        return;
    }

    if (x<0)
    {
        printf("-1*");
        x=abs(x);
    }

    factorization(x, print_res);

    return;
}

int main(int argc, char* argv[])
{
    if (check_arg_user (argc, argv))
    {
        return 1;
    }
    
    factorize(atoi(argv[1]));
    
    return 0;
}