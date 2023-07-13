#include <stdio.h>

void main(){
    float x[10][10], trans[10][10];
    int r,c;
    printf("Enter the number of rows and colums:");
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("enter NUM%d%d\n",i,j);
            scanf("%f",&x[i][j]);



        }


    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            trans[j][i]=x[i][j];

        }
        }

         for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%f\n",trans[i][j]);
            if(j==r-1)
            printf("\n");
        }
}
}