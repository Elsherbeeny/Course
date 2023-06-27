#include <stdio.h>
int facto(int x);
void main(){
    int x;
    printf("Enter a number :");
    scanf("%d",&x);
    printf("\n the factorial of the number you entered=%d",facto(x));

}
int facto (int x){
    int i,fact=1;
    for(i=1;i<=x;i++){
        fact=fact*i;
    }
    return fact;

}