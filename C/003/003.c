#include <stdio.h>
#include <math.h>
int main(){
    int num1=0;
    int num2=0;
    double difference=0;
    double sum=0;
    double quotient=0;
    double product=0;

    scanf("%d",&num1);
    scanf("%d",&num2);
    difference=fabs(num1-num2);
    sum=num1+num2;
    quotient=(double)num1/num2;
    product=num1*num2;

    printf("Difference:%.2f\n",difference);
    printf("Sum:%.2f\n",sum);
    printf("Quotient:%.2f\n",quotient);
    printf("Product:%.2f\n",product);
return 0;

}
