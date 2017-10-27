#include <stdio.h>
int main(){
    int lecture_1=0,lecture_2=0,lecture_3=0,
        hours_1=0,hours_2=0,hours_3=0,
        time_11=0,time_12=0,time_21=0,time_22=0,time_31=0,time_32=0;
    int i=0;

    scanf("%d %d",&lecture_1,&hours_1);
    if( hours_1<=0 || hours_1>=3 ){
        printf("-1");
        return 0;
    }
    if( hours_1==1 ){
        scanf("%d",&time_11);
    }
    if( hours_1==2 ){
        scanf("%d",&time_11);
        scanf("%d",&time_12);
    }

    scanf("%d %d",&lecture_2,&hours_2);
    if( hours_2<=0 || hours_2>=3 ){
        printf("-1");
        return 0;
    }
    if( hours_2==1 )
        scanf("%d",&time_21);
    if( hours_2==2 ){
        scanf("%d",&time_21);
        scanf("%d",&time_22);
    }

    scanf("%d %d",&lecture_3,&hours_3);
    if( hours_3<=0 || hours_3>=3 ){
        printf("-1");
        return 0;
    }
    if( hours_3==1 )
        scanf("%d",&time_31);
    if( hours_3==2 ){
        scanf("%d",&time_31);
        scanf("%d",&time_32);
    }

    if( lecture_1<=999 || lecture_1>=10000 || lecture_2<=999 || lecture_2>=10000 || lecture_3<=999 || lecture_3>=10000){
        printf("-1");
        return 0;
    }
    if( time_11<=10 ||time_12>=99 || time_21<=10 ||time_22>=99 ||time_31<=10 ||time_32>=99 ){
        printf("-1");
        return 0;
    }
    if( time_11==time_21 ){
        printf("%d,%d,%d\n",lecture_1,lecture_2,time_11);
        i++;
    }
    if( time_11==time_22 ){
        printf("%d,%d,%d\n",lecture_1,lecture_2,time_11);
        i++;
    }
    if( time_11==time_31 ){
        printf("%d,%d,%d\n",lecture_1,lecture_3,time_11);
        i++;
    }
    if( time_11==time_32 ){
        printf("%d,%d,%d\n",lecture_1,lecture_3,time_11);
        i++;
    }

    if( time_12==time_21 ){
        printf("%d,%d,%d\n",lecture_1,lecture_2,time_12);
        i++;
    }
    if( time_12==time_22 ){
        printf("%d,%d,%d\n",lecture_1,lecture_2,time_12);
        i++;
    }
    if( time_12==time_31 ){
        printf("%d,%d,%d\n",lecture_1,lecture_3,time_12);
        i++;
    }
    if( time_12==time_32 ){
        printf("%d,%d,%d\n",lecture_1,lecture_3,time_12);
        i++;
    }
    if( time_21==time_31 ){
        printf("%d,%d,%d\n",lecture_2,lecture_3,time_21);
        i++;
    }
    if( time_21==time_32 ){
        printf("%d,%d,%d\n",lecture_2,lecture_3,time_21);
        i++;
    }
    if( time_22==time_31 ){
        printf("%d,%d,%d\n",lecture_2,lecture_3,time_22);
        i++;
    }
    if( time_22==time_32 ){
        printf("%d,%d,%d\n",lecture_2,lecture_3,time_22);
        i++;
    }
    if(i==0)
        printf("correct");
    return 0;
}
