#include <stdio.h>

void getResult(int nine_first, int nine_second, int ten_first, int ten_second, int eleven){
    int sum = nine_first+nine_second+ten_first+ten_second+eleven;
    printf("%d",sum);
}
int main(){
    int nine_first=0,nine_second=0;
    int ten_first=0,ten_second=0;
    int eleven=0;
    scanf("%d %d %d %d",&nine_first,&nine_second,&ten_first,&ten_second);
    if(ten_first==10 || ten_second==10)
        scanf("%d",&eleven);
    getResult(nine_first,nine_second,ten_first,ten_second,eleven);
}



