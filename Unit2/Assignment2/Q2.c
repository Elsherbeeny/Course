#include <stdio.h>

void main(){
    int n;
    float x[100], sum=0.0, average;
    printf("Enter a number from 0 to 100\n");
    scanf("%d",&n);
    if(n>100 ||n<0){
        printf("the number is wrong enter a number from 0 to 100");
        scanf("%d",&n);
        
    }
    for(int i=0;i<n;i++){
        printf("Enter NUM%d:\n",i+1);
        scanf("%f",&x[i]);
        sum+=x[i];
    }
    average= sum/n;
    printf("\n the average is %f",average);
}