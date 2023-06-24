#include <stdio.h>

void main(){
    float x[2][2], y[2][2], z[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
        printf("Enter number a%d%d \n",i,j);
        scanf("%f", &x[i][j]);
        }
    }
    printf("Enter the elements of the second matrix\n");
    for(int i=0;i<2;i++){
       for(int j=0;j<2;j++){
            printf("Enter number b%d%d\n",i,j);
            scanf("%f", &y[i][j]);
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            z[i][j]=x[i][j]+y[i][j];
        }
        printf("\n the sum matrix\n");
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                printf("%f\t",z[i][j]);
                if (j==1)
                printf("\n");
            }
        }
    }


}