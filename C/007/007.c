#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c,d,e;
    double average,variance,sd;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    average=(a+b+c+d+e)/5.0;
    variance=fabs((a*1.0-average)*(a*1.0-average)+(b*1.0-average)*(b*1.0-average)+(c*1.0-average)*(c*1.0-average)+
             (d*1.0-average)*(d*1.0-average)+(e*1.0-average)*(e*1.0-average))/5.0;
    sd=sqrt(variance);
    printf("%.2f\n",variance);
    printf("%.2f\n",sd);
    printf("%.2f\n",average);
    return 0;
}
