#include <stdio.h>
//declare the function
long unsigned factorial(int num);

int main(){
    //call the function
    int input;
    printf("Enter the number: ");
    scanf("%d",&input);
    printf("The factorial of number %d is %lu", input,factorial(input));
    return(0);
}

//function definition
long unsigned factorial(int num)
{
    if(num<0){printf("Factorial of an number cannot be zero");}
    else if(num==0){number1=1;return(number1);}
    else
    {
        return(num*factorial(num-1));
    }
    
}