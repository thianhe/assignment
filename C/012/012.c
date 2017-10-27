#include <stdio.h>
#include <math.h>
int main(){
    int a1=0,a2=0;
    int b1=0,b2=0;
    int c1=0,c2=0;
    int sum=0;
    scanf("%d %d %d %d %d %d",&a1,&a2,&b1,&b2,&c1,&c2);


    if( b1>=a1 && a2>=b1 )
            sum=abs(c2-a1);
    else if( a1==b1 && b1==c1 && a2==b2 && b2==c2)
        sum=abs(a1-a2);
    else if( a2==b1 && b2==c1 )
        sum=abs(a1-a2)+abs(b1-b2)+abs(c1-c2);
    else
        sum=abs(a1-a2)+abs(b1-b2)+abs(c1-c2);
    printf("%d",sum);
    return 0;
}
