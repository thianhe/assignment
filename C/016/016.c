#include<stdio.h>
int main(){
    int month=0;
    double usage_lastyear=0,usage_thisyear=0;
    double discount=0;
    double fees=0;

    scanf("%d %lf %lf",&month,&usage_lastyear,&usage_thisyear);
    if ( month>=7 && month<=9 ){
        if(usage_lastyear>usage_thisyear){
            if(usage_thisyear<=120){
                discount=(usage_lastyear-usage_thisyear)*0.6;
                fees=(usage_thisyear*2.10)-discount;
            }
            else if(usage_thisyear>=121 && usage_thisyear<=330){
                discount=(usage_lastyear-usage_thisyear)*0.6;
                fees=(usage_thisyear*3.02)-discount;
            }
            else if(usage_thisyear>=331 && usage_thisyear<=500){
                discount=(usage_lastyear-usage_thisyear)*0.6;
                fees=(usage_thisyear*4.39)-discount;
            }
            else if(usage_thisyear>=501 && usage_thisyear<=700){
                discount=(usage_lastyear-usage_thisyear)*0.6;
                fees=(usage_thisyear*4.97)-discount;
            }
            else{
                discount=(usage_lastyear-usage_thisyear)*0.6;
                fees=(usage_thisyear*5.63)-discount;
            }
        }
        else{
                if(usage_thisyear<=120){
                    fees=(usage_thisyear*2.10);
                }
                else if(usage_thisyear>=121 && usage_thisyear<=330){
                    fees=(usage_thisyear*3.02);
                }
                else if(usage_thisyear>=331 && usage_thisyear<=500){
                    fees=(usage_thisyear*4.39);
                }
                else if(usage_thisyear>=501 && usage_thisyear<=700){
                    fees=(usage_thisyear*4.97);
                }
                else{
                    fees=(usage_thisyear*5.63);
                }
        }
    }
    else{
        if(usage_lastyear>usage_thisyear){
            if(usage_thisyear<=120){
                discount=(usage_lastyear-usage_thisyear)*0.6;
                fees=(usage_thisyear*2.10)-discount;
            }
            else if(usage_thisyear>=121 && usage_thisyear<=330){
                discount=(usage_lastyear-usage_thisyear)*0.6;
                fees=(usage_thisyear*2.68)-discount;
            }
            else if(usage_thisyear>=331 && usage_thisyear<=500){
                discount=(usage_lastyear-usage_thisyear)*0.6;
                fees=(usage_thisyear*3.61)-discount;
            }
            else if(usage_thisyear>=501 && usage_thisyear<=700){
                discount=(usage_lastyear-usage_thisyear)*0.6;
                fees=(usage_thisyear*4.01)-discount;
            }
            else{
                discount=(usage_lastyear-usage_thisyear)*0.6;
                fees=(usage_thisyear*4.50)-discount;
            }
        }
        else{
            if(usage_thisyear<=120){
                fees=(usage_thisyear*2.10);
            }
            else if(usage_thisyear>=121 && usage_thisyear<=330){
                fees=(usage_thisyear*2.68);
            }
            else if(usage_thisyear>=331 && usage_thisyear<=500){
                fees=(usage_thisyear*3.61);
            }
            else if(usage_thisyear>=501 && usage_thisyear<=700){
                fees=(usage_thisyear*4.01);
            }
            else{
                fees=(usage_thisyear*4.50);
            }
        }
    }
    printf("%.2f",fees);
}
