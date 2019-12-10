//Arrange user input 10 numbers in ascending order using knowledge of arrays,loops,pass by reference,functions and pointers?
#include<stdio.h>

void swapifhigh(double *pt1, double *pt2);
void ascending(double *arr_pt);

int main(){
    double userInp[10];
    for(int i=0;i<10;i++){
        printf("\n Enter value %d:",(i+1));
        scanf("%lf", userInp+i);
    }
    ascending(userInp);
    for(int i=0;i<10;i++){
        printf("\n %lf", *(userInp+i));
        
    }
    return(0);
}

void ascending(double *arr_pt){
    for(int i=0;i<10;i++){
        for(int j=9;j>i;j--){
            swapifhigh(arr_pt +i,arr_pt+j);
        }
    }
}

void swapifhigh(double *pt1, double *pt2){
    if((*pt1)>(*pt2)){
        double temp;
        temp=*pt1;
        *pt1=*pt2;
        *pt2=temp;
    }
}