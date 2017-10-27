#include <stdio.h>
int main(){
    double height;
    double weight;
    double bmi;
    scanf("%lf",&height);
    scanf("%lf",&weight);

    bmi=weight/(height*height);
    printf("%.1f",bmi);

return 0;

}
