#include<stdio.h>
void function(int a,int b, int c, int d,int w,int x, int y, int z){
    int correctA=0,correctB=0;
    if(a==w){
        correctA++;
        w=99;
    }
    else if(a==x ){
        correctB++;
        x=99;
    }
    else if(a==y ){
        correctB++;
        y=99;
    }
    else if(a==z ){
        correctB++;
        z=99;
    }
    if(b==x ){
        correctA++;
        x=99;
    }
    else if(b==w){
        correctB++;
        w=99;
    }
    else if(b==y){
        correctB++;
        y=99;
    }
    else if(b==z){
        correctB++;
        z=99;
    }

    if(c==y){
        correctA++;
        y=99;
    }
    else if(c==w){
        correctB++;
        w=99;
    }
    else if(c==x){
        correctB++;
        x=99;
    }
    else if(c==z){
        correctB++;
        z=99;
    }
    if(d==z ){
        correctA++;
        z=99;
    }
    else if(d==w){
        correctB++;
        w=99;
    }
    else if(d==x){
        correctB++;
        x=99;
    }
    else if(d==y){
        correctB++;
        y=99;
    }
    printf("%dA%dB",correctA,correctB);
}
int main() {
	int w = 0, x = 0, y = 0, z = 0;
	int a = 0, b = 0, c = 0, d = 0;
	int correctA=0,correctB=0;
	scanf("%d %d %d %d", &w, &x, &y, &z);
	while(1){
        scanf("%d",&a);
        if(a==-1){
            break;
        }
        scanf("%d %d %d", &b, &c, &d);
        function(a,b,c,d,w,x,y,z);
    }
    return 0;
}
