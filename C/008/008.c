#include <stdio.h>
#include <math.h>

int main(){
    double a,b,c;
    double t;
    double x1,x2;
    scanf("%lf %lf %lf",&a,&b,&c);
    t = b*b-4*a*c;

    if( t>=0 ){
        x1 = (-b+sqrt(t))/(2*a);
        x2 = (-b-sqrt(t))/(2*a);
        printf("%.1f\n",x1);
        printf("%.1f\n",x2);
    }

    else {
        x1=-b/(2*a)+0;
        x2=sqrt(-t)/(2*a);
        printf("%.1f+%.1fi\n",x1,x2);
        printf("%.1f-%.1fi",x1,x2);
    }
    return 0;
}
