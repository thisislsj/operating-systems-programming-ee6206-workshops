#include <stdio.h>

int main(){
    char c;
    printf("\n Please enter your gender: "); //inclass probabale Qs
    scanf("%c",&c);

    if(c=='f' || c=='F'){
        printf("You are a Women");
    }else if(c=='m' || c=='M'){
        printf("You are a Man");
    }else{
        printf("Invalid Input");
    }

}