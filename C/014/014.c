#include <stdio.h>
#include <math.h>
int fees(int starthrs,int startmin,int endhrs,int endmin){
    int hrs = 0, min = 0;
    int fees=0;
    if( startmin>endmin ){
        endhrs -= 1;
        endmin += 60;
    }
    hrs = endhrs-starthrs;
    min = endmin-startmin+(hrs*60);
    if( min<=120 )
        fees = (min/30)*30;
    else if( min<=240){
        fees = 120 + ceil((min-120)*1.0/30)*40 ;
    }
    else
    {
        fees = 120+160+ceil((min-240)*1.0/30)*60 ;
    }
    return fees;
}

int main(){
    int starthrs,startmin,endhrs,endmin;
    char colon;
    int feesvalue[3]={0};
    int x,i,j;
    for( i=0;i<3;i++ ){
        scanf("%d:%d",&starthrs,&startmin);
        scanf("%d:%d",&endhrs,&endmin);
        if( starthrs<0 || starthrs>=25 || startmin <0 || startmin >60 ||endhrs<0 || endhrs>=25 || endmin <0 || endmin >60){
            feesvalue[i]=-1;
            continue;
        }
        feesvalue[i] = fees(starthrs,startmin,endhrs,endmin);
    }
    for(j = 0; j < i; j++){
        if(feesvalue[j] == -1)
            printf("error\n");
        else
            printf("%d\n",feesvalue[j]);
    }
    return 0;
}
