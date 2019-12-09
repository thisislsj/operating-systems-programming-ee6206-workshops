#include<stdio.h>
#include<math.h>

int main(){
    double h,r,v;
    printf(" /n Enter the height: ");
    scanf("%lf",&h);
    printf("/n Enter the radius: ");
    scanf("%lf",&r);
    v=M_PI*r*r*h;
    printf("The volume is ", v);
    return(0);
}