#include <stdio.h>
#include <math.h>
void hexaconvert(long decimal){
    char hex[]="0123456789ABCDEF";
    char hexanum[100]={0};
    int i=0,j=0;
    int remainder=0;
    while(decimal != 0){
        remainder=decimal%16;
        hexanum[i]=hex[remainder];
        decimal=decimal/16;
        i++;
    }
    for( j=i-1  ;j>= 0;j--)
        printf("%c",hexanum[j]);
    return 0;
}
void convert(long decimal,int notation){
    int i=1;
    int remainder=0;
    int answer=0;
    while(decimal!=0){
        remainder=decimal%notation;
        answer+=(remainder*i);
        decimal/=notation;
        i=i*10;
    }
    printf("%ld",answer);
    return 0;
}
int main(){
    int notation;
    long decimal;
    scanf("%d %ld",&notation,&decimal);
    if(notation <=1 || notation >=17 || decimal <0 || decimal >1000000000){
        printf("E");
    }
    else if(notation==16){
        hexaconvert(decimal);
    }
    else{
        convert(decimal,notation);
    }
    return 0;
}
