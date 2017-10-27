#include <stdio.h>

void type1(int row){
    int i=0,j=0;
    for(i=1;i<=(row+1)/2;i++){
        for(j=(row+1)/2;j>i;j--){
            printf(".");
        }
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        for(j=i-1;j>=1;j--){
            printf("%d",j);
        }
        printf("\n");
    }
    row/=2;

    for(i=row;i>=1;i--){
        for(j=0;j<=row-i;j++){
            printf(".");
        }
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        for(j=i-1;j>=1;j--){
            printf("%d",j);
        }
        printf("\n");
    }

}
void type2(int row){
    int i=0,j=0;

    for(i=row;i>=1;i--){
        for(j=1;j<=row-i;j++){
            printf(".");
        }

        for(j=1+(i-1)*2;j>1;j=j-2){
            printf("%d",j);

        }

        for(j=1;j<=1+(i-1)*2;j=j+2){
            printf("%d",j);

        }
        printf("\n");
    }

}
int main(){
    int type=0,row=0;

    while(1){
        scanf("%d",&type);
        if(type==-1){
            return 0;
        }

        scanf("%d",&row);
        if(type==1){
            if(row<=0 || row>=18 || row%2==0 ){
                printf("E\n");
                continue;
            }
        }
        else if(type!=1 && type!=2){
            printf("E\n");
            continue;
        }
        else if(type==2){
            if(row<=0 || row>=6){
                printf("E\n");
                continue;
            }
        }
        else if(type!=1 && type!=2){
            printf("E\n");
            continue;
        }
        if(type==1){
            type1(row);
        }
        if(type==2){
            type2(row);
        }
    }
    return 0;
}
