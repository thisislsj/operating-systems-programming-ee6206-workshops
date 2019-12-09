//PASSING A VALUE TO A FUNCTION

//1. PASS BY VALUE

// 2. PASS BY REFERENCE
// uses pointers
// int *pt;  //declaring pointers

#include <stdio.h>
double getMaximum(double * pt);
int main()
{
    //declare the array of numbers
    double inp[10];

    for(int j=0;j<10;j++){
        printf("Enter number %d \n", (j+1));
        scanf("%lf", &inp[j]);
        //scanf("%lf", inp+j);   //this code can also be used as inp is the address of the first block

    }
    printf("The maximum of the numbers that you entered is : %lf", getMaximum(inp));
    return(0);
}

double getMaximum(double * pt)
{
    double maximum = *pt;
    int k =0;
    while(k<10)
    {
        if(maximum < *(pt+k)){maximum = *(pt+k);}
        k++;
    }
    return(maximum);
}