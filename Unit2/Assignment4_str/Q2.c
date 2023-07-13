#include<stdio.h>

struct Sdistance{
    int feet;
    float inch;
}sum,x,y;

void main(){
    printf("Enter the first distance\n Feet:");
    scanf("%d",&x.feet);
    printf("Inch:");
    scanf("%f",&x.inch);
    printf("Enter the second distance\n Feet:");
    scanf("%d",&y.feet);
    printf("Inch");
    scanf("%f",&y.inch);
    sum.feet=x.feet+y.feet;
    sum.inch=x.inch+y.inch;
    if(sum.inch>=12){
        sum.feet++;
        sum.inch-=12;
    }
    printf("the sum is %d feet\t%.2finch",sum.feet,sum.inch);
}