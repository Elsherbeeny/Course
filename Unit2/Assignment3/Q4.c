#include <stdio.h>
int power(int x,int n);
void main (){
    int y,z;
    printf("Enter the base number:");
    scanf("%d",&y);
    printf("Enter the power number");
    scanf("%d",&z);
    printf("the total is:%d",power(y,z));

}
int power (int x , int n){
    for (int i=1;i<n;i++){
        x*=x;
    }
    return x;
}