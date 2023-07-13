#include<stdio.h>

void main(){
    int arr[15],n,*pointer;
    printf("Enter the number of the array elements:");
    scanf("%d",&n);
    pointer=arr;
    for(int i=0;i<n;i++){
        printf("\nEnter element number %d:",i+1);
        scanf("%d",pointer);
        pointer++;
    }
    pointer=&arr[n-1];
    printf("The reversed array\n");
    for(int i=0;i<n;i++){
        printf("element %d=%d\t",n-i,*pointer);
        pointer--;
    }
}