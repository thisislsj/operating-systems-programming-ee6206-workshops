//structures
#include <stdio.h>

struct mystruct{
    char char_value;
    int int_value;
    double double_value;
};
union myunion{
    char value;
    int val;
    double va;
};
struct mystruct initialize(char *pt1,int *pt2,double *pt3);

int main(){
    char usr_char;
    int usr_int;
    double usr_double;

    printf("Enter the character: \n");
    scanf("%c", &usr_char);

    printf("Enter the integer: \n");
    scanf("%d",&usr_int);

    printf("Enter the double: \n");
    scanf("%lf", &usr_double);

    struct mystruct new1=initialize(&usr_char,&usr_int,&usr_double);

    union myunion new;
    new.cha_value=usr_char;
    new.int_value=usr_int;
    new.double_value=usr_double;

    printf("\n For Structure:The character entered is %c, integer is %d, and double is %lf",new1.char_value,new1.int_value,new1.double_value);

    printf("\n For Union:The character entered is %c, integer is %d, and double is %lf",new1.char_value,new1.int_value,new1.double_value);

    return(0);
}



struct mystruct initialize(char *pt1,int *pt2,double *pt3){
    struct mystruct str1;
    str1.char_value=*pt1;
    str1.int_value=*pt2;
    str1.double_value=*pt3;
    return str1;
}



