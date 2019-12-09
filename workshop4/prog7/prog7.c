#include <stdio.h>

int main(){
    char o;
    float n1;
    float n2;
    float ans;
    printf("What is the operation:");
    scanf("%c",&o);

    printf(" \n Input n1:");
    scanf("%f",&n1);

    printf(" \n Input n2:");
    scanf("%f",&n2);

    switch(o){
        case('a'):
        ans=n1+n2;
        break;

        case('s'):
        ans=n1-n2;
        break;

        case('m'):
        ans=n1*n2;
        break;

        case('d'):
        if(n2==0){
            printf("Can not devide by zero");
            return(0);
        }
        ans=n1/n2;
        break;

        default:
        printf("Invalid Operation");
        break;

    }
    printf(" \n %.3f \n "  ,ans);

    return(0);

}