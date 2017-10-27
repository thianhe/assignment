#include <stdio.h>

void type1(int type,int row){
    int i=0,j=0;
    for(i=1;i<=(row+1)/2;i++){
        for(j=1;j<=i;j++){
            printf("*");
        }

        printf("\n");
    }
    row/=2;
    for(i=row;i>=1;i--){
        for(j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}

void type2(int type,int row){
    int i=0,j=0;
    for(i=1;i<=(row+1)/2;i++){
        for(j=(row+1)/2;j>i;j--){
            printf(".");
        }
        for(j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    row/=2;
    for(i=row;i>=1;i--){
        for(j=0;j<=row-i;j++){
            printf(".");
        }

        for(j=i;j>=1;j--){
            printf("*");
        }

        printf("\n");
    }

}
void type3(int type,int row){
    int i=0,j=0;
    for(i=1;i<=(row+1)/2;i++){
        for(j=(row+1)/2;j>i;j--){
            printf(".");
        }
        for(j=1;j<=i;j++){
            printf("*");
        }
        for(j=1;j<=i-1;j++){
            printf("*");
        }

        printf("\n");
    }
    row/=2;

    for(i=row;i>=1;i--){
        for(j=0;j<=row-i;j++){
            printf(".");
        }

        for(j=i;j>=1;j--){
            printf("*");
        }
        for(j=1;j<=i-1;j++){
            printf("*");
        }
        printf("\n");
    }
}
int main(){
    int type=0,row=0;
    scanf("%d %d",&type,&row);
    if(type==1){
        type1(type,row);
    }
    else if(type==2){
        type2(type,row);
    }
    else{
        type3(type,row);
    }
    return 0;
}
