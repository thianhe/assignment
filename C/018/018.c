#include <stdio.h>
#include <math.h>

int main(){
    int number,i,j;
    int diff1, diff2, diff3;
    double factor1, factor2, factor3;
    int input[20][5];
    scanf("%d",&number);

    if(number<1 || number>20){
        printf("E");
        return 0;
    }
    for(i=0;i<number;i++){
        for(j=0;j<4;j++){
            scanf("%d",&input[i][j]);
        }
    }
    for(i=0;i<number;i++){
        diff1 = input[i][1] - input[i][0];
        diff2 = input[i][2] - input[i][1];
        diff3 = input[i][3] - input[i][2];

        factor1 = (double) input[i][1] / input[i][0];
        factor2 = (double) input[i][2] / input[i][1];
        factor3 = (double) input[i][3] / input[i][2];

        if((diff1 == diff2) && (diff2 == diff3) && (diff1 == diff3)){
                input[i][4] = input[i][3] + diff1;
        }
        else if(factor1 == factor2 &&(factor2 == factor3) && (factor1 == factor3)){
            input[i][4] = input[i][3] * factor1;
        }
        else{
            input[i][0] = -99;
        }
    }
    for(i = 0; i < number; i++){
        for(j = 0; j < 5; j++){
            if(input[i][0] == -99)
            {
                printf("E");
                break;
            }
            else{
                printf("%d ",input[i][j]);
            }
        }
        printf("\n");
    }
}

