#include <stdio.h>
int getTriangle(int a,int b,int c){
    if ( (a+b<=c) || (a+c<=b) || (b+c<=a) || a<=0 || b<=0 || c<=0){
        return 1;
    }
    else if( a==b && a==c && b==c){
        return 2;
    }
    else if( a==b || a==c || b==c ){
        return 3;
    }
    else{
        return 4;
    }

}
int main(){
    int a,b,c;
    int result;
    scanf("%d %d %d",&a,&b,&c);
    result=getTriangle(a,b,c);
    if( result == 1 ){
        printf("not triangle");
    }
    else if( result == 2 ){
        printf("equilateral triangle");
    }
    else if( result == 3 ){
        printf("isosceles triangle");
    }
    else {
        printf("triangle");
    }
    return 0;
}
