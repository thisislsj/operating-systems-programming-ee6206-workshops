//NOTE--------------
//arrays
//address of the first block = array_name

//data_type arrayname[size];
//arrayname[index];
//-------------------

#include<stdio.h>

int main()
{
    //declare the array of numbers
    double inp[10];

    for(int j=0;j<10;j++){
        printf("Enter number %d \n", (j+1));
        scanf("%lf", &inp[j]);
        //scanf("%lf", inp+j);   //this code can also be used as inp is the address of the first block

    }

    double minimum=inp[0];
    int k=0;
    while(k<10){
        if (minimum > inp[k]){minimum=inp[k];}
        
        k++;
    }
    printf("The minimum of the numbers that you entered is : %0.1lf", minimum);
    return(0);
}