#include <stdio.h>

void main (){
    int x[50],element,numele,i;
    printf("Enter the number of elements:");
    scanf("%d",&numele);
    if(numele>50){
        printf("Enter a number from 1 to 50 please :");
        scanf("%d",&numele);
    }
    for(i=0;i<numele;i++){
        printf("\nEnter element number %d: ",i+1);
        scanf("%d",&x[i]);
    }
    printf("\n Enter the element you want to search for:");
    scanf("%d",&element);
    for(i=0;i<numele;i++){
        if(x[i]==element){
            printf("\nthe number was found in element %d",i+1);
            i=10000;
        }
    }
    if(i==numele){
        printf("not found");
    }
}