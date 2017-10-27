#include <stdio.h>

int main(){
    int innetcall,outnetcall,phonecall,innetmessage,outnetmessage;
    double typeone,typetwo,typethree;
    scanf("%d %d %d %d %d",&innetcall,&outnetcall,&phonecall,&innetmessage,&outnetmessage);
    typeone=(innetcall*0.08)+(outnetcall*0.139)+(phonecall*0.135)+(innetmessage*1.128)+(outnetmessage*1.483);
    typetwo=(innetcall*0.07)+(outnetcall*0.130)+(phonecall*0.121)+(innetmessage*1.128)+(outnetmessage*1.483);
    typethree=(innetcall*0.06)+(outnetcall*0.108)+(phonecall*0.101)+(innetmessage*1.128)+(outnetmessage*1.483);

    if (typeone < 183){
        typeone = 183;
    }
    if (typetwo < 383){
        typetwo = 383;
    }
    if (typethree < 983){
        typethree = 983;
    }
    if ( typeone < typetwo  && typeone < typethree ){
        printf("%.0f\n",typeone);
        printf("183");
    }
    else if ( typetwo < typeone  && typetwo < typethree ){
        printf("%.0f\n",typetwo);
        printf("383");
    }
    else if ( typethree < typeone  && typethree < typetwo ){
        printf("%.0f\n",typethree);
        printf("983");
    }
    return 0;
}
