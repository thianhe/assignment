#include <stdio.h>
int main(){
    int abook,bbook,cbook;
    double result;
    scanf("%d %d %d",&abook,&bbook,&cbook);


    if( abook>=1 && abook<=10 ){
        result+=abook*380;
    }
    else if( abook>=11 && abook<=20 ){
        result+=(abook*380*0.9);
    }
    else if( abook>=21 && abook<=30 ){
        result+=(abook*380*0.85);
    }
    else if( abook>=31 ){
        result+=(abook*380*0.8);
    }
    // abook //

    if( bbook>=1 && bbook<=10 ){
        result+=bbook*1200;
    }
    else if( bbook>=11 && bbook<=20 ){
        result+=(bbook*1200*0.95);
    }
    else if( bbook>=21 && bbook<=30 ){
        result+=(bbook*1200*0.85);
    }
    else if( bbook>=31 ){
        result+=(bbook*1200*0.8);
    }
    // bbook //

    if( cbook>=1 && cbook<=10 ){
        result+=cbook*180;
    }
    else if( cbook>=11 && cbook<=20 ){
        result+=(cbook*180*0.85);
    }
    else if( cbook>=21 && cbook<=30 ){
        result+=(cbook*180*0.8);
    }
    else if( cbook>=31 ){
        result+=(cbook*180*0.7);
    }
    // cbook //

    printf("%.f",result);
    return 0;
}
