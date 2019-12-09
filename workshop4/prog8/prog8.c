#include <stdio.h>
int main(){
    long sum=0;
    int i=21;
    while(i<911){
        sum=sum+1;
        i=i+3;
    }
    printf('%lf',sum);
    return(0);
}