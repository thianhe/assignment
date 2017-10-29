#include<stdio.h>
int main() {
	//answer
	int ans_1, ans_2, ans_3, ans_4;
	int try_1, try_2, try_3, try_4;

	int counterA, counterB;
	int i = 0;
	scanf("%d %d %d %d", &ans_1, &ans_2, &ans_3, &ans_4);
	while(1)
	{
		counterA = counterB = 0;
		scanf("%d", &try_1);
		if(try_1 == -1)
			break;
		scanf("%d %d %d", &try_2, &try_3, &try_4);

		if(ans_1 == try_1) {
			counterA++;
			try_1 = 99;
		}
		else if(ans_1 == try_2)
			counterB++;
		else if(ans_1 == try_3)
			counterB++;
		else if(ans_1 == try_4)
			counterB++;

		if(ans_2 == try_2)
		{
			counterA++;
			try_2 = 99;
		}
		else if(ans_2 == try_1)
			counterB++;
		else if(ans_2 == try_3)
			counterB++;
		else if(ans_2 == try_4)
			counterB++;

		if(ans_3 == try_3)
		{
			counterA++;
			try_3 = 99;
		}
		else if(ans_3 == try_1)
			counterB++;
		else if(ans_3 == try_2)
			counterB++;
		else if(ans_3 == try_4)
			counterB++;


		if(ans_4 == try_4){
			counterA++;
			try_4 = 99;
		}
		else if(ans_4 == try_1)
			counterB++;
		else if(ans_4 == try_2)
			counterB++;
		else if(ans_4 == try_3)
			counterB++;

		printf("%dA%dB\n", counterA, counterB);
	}
	return 0;
}
