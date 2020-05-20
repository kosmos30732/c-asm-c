#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<inttypes.h>


/*
 * -first arg is a divider
 *
 * -second arg idicates whether 
 *     this is the last devider or not;
 *     if it equal 1 it is last
 */
typedef int32_t (*callback)(int32_t,int32_t);


/*
 * Funtion that make factorization 
 * 
 *  x - number for factorization
 * cb - fuction pointer output of the divider
*/
extern int32_t factorization(int32_t x, callback cb);


//fuction that printf a deviders
int32_t print_res(int32_t x, int32_t y)
{
    //in case if this is the last divider
    if (y==1)
    {
        printf("%d\n",x);
        return 0;
    }

    printf("%d*",x);

    return 0;
} 


void factorize(int32_t x, callback cb)
{
    //special case
    if (x==0 || x==1 || x==-1)
    {
        cb(x,1);
        return;
    }

    //if the number is negative
    if (x<0)
    {
        printf("-1*");
        x=abs(x);
    }

    factorization(x, cb);

    return;
}


int main(int argc, char* argv[])
{
    //check the users args
    if (argc != 2)
    {
        printf ("Usage: %s <NUM>\n\tWhere <NUM> is the number for factorization\n", argv[0]);
        return 1;
    }

    //check that the user's number not contain wrong chars
    int i=0;
    while (argv[1][i]!='\0')
    {
        if (!((argv[1][i]>='1' && argv[1][i]<='9')|| argv[1][i]=='-'))
        {
            printf("It's not a number check it and try again\n");
            return 0;
        }
        i++;
    }

    //check that user's number included in int32_t
    long int num=strtol(argv[1], NULL, 10);
    if (errno==ERANGE || abs(num)>=2147483647)
    {
        printf("Your number too large, put less number\n");
        return 1;
    }
    
    factorize(num, print_res);
    
    return 0;
}