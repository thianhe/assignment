#include <stdio.h>
#include <math.h>

int Compute(int start_last, int end_last, int start_current, int end_current){
    int length = 0, repeatedLength = 0;
     if(start_current < start_last){
         printf("E");
         return length; //length = 0;
     }
    if(start_current < end_last){
        repeatedLength = end_last - start_current;
    }
    if(end_current > end_last) {
        length += end_current - start_current - repeatedLength;
    }
    return length;
}

int main(){
    int i = 0, j = 0, testcase = 0, line = 0;
    int start_last, end_last, start_current, end_current;
    int repeatedLength, length[5000] = { 0 };
    scanf("%d", &testcase);
    for(i = 0; i < testcase; i++){
        scanf("%d", &line);
        scanf("%d %d", &start_last, &end_last);
        length[i] = end_last - start_last;
        for(j = 0; j < line - 1; j++){
            repeatedLength = 0;
            scanf("%d %d", &start_current, &end_current);
            length[i] += Compute(start_last, end_last, start_current, end_current);
            end_last = end_current;
            start_last = start_current;
        }
    }
    for(i = 0; i < testcase; i++) {
        printf("%d\n", length[i]);
    }
    return 0;
}
