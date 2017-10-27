#include<stdio.h>
#include<math.h>
void getValue(int number){
    int i,j,k,isPrime,addanswer,factorial=1;
    for( i=2; i<=number ;i++ ){
        if( number%i ==0 ){
            isPrime=1;
            for( j=2 ; j<=(i/2) ; j++ ){
                if( i%j==0 ){
                    isPrime=0;
                    break;
                }
            }
            if(isPrime==1){
                factorial=1;
                for(k=1; k<=i; k++){
                    factorial = factorial*k;
                }
                printf("%d ",factorial);
                addanswer += factorial;
            }
        }
    }
    printf("\n%d",addanswer);

}
int validInput(double num){
    if( num<=0 || num!=ceil(num) || (int)num==0){
        return 1;
    }
    return 0;
}
int main(){
    double number;
    int input;
    scanf("%lf",&number);
    input=validInput(number);
    if(input==1){
        printf("E");
    }
    else{
        getValue(number);
    }
    return 0;
}
