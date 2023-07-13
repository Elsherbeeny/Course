#include<stdio.h>

void main(){
    char x;
    float y,z;
    printf("Enter the operator:");
    scanf("%c",&x);
    
        printf("\n Enter 2 numbers");
        scanf("%f%f",&y,&z);

        switch (x)
        {
        case '+':
        printf("\n y%cz=%f",x,y+z);
            break;
        case '-':
          printf("\n y%cz=%f",x,y-z);
        break;
         case '*':
          printf("\n y%cz=%f",x,y*z);
        break;
         case '/':
          printf("\n y%cz=%f",x,y/z);
        break;

        default:
        printf("\n operator is not right");
            break;
        }

    
}