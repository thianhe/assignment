/*
 *Class: Computer Science And Information Engineering Year 2
 *ID : 105590050
 *Name : Lee Thian He
 *Homework Number : 1
 *Date of homework : 28 / 9 / 2017
 *Purpose : To play memory matching game with arranging 2pairs of number 1 to number 8 randomly.
 *          User enters two coordinate points to determine which two coordinate's number to be "showed up",
 *          if the two number match ,both number will not be "flipped back",if the two number don't match then the both will be
 *		   "flipped back".
 */
#include <iostream>
#include <string>
#include <ctime>
#define VALIDATION coor[0]!='(' || coor[2]!=',' || coor[4]!=')' ||\
				   coor[1] < '1' || coor[1] > '4' || coor[3] < '1' || coor[3] > '4'       //定義非正常的輸入

using namespace std;

void Get50Spaces()			//空五十行
{
    for (int i = 0; i < 50; i++)
        cout << endl;
}
void ShuffleNumber(int answer[][5])			//“洗牌”
{
    srand(time(NULL));		//每次的隨機數都不同

    for (int x = 1; x <= 4; x++)
    {
        for (int y = 1; y <= 4; y++)
        {
            int i = rand() % 4 + 1;				//随機數字1到4
            int j = rand() % 4 + 1;
            swap(answer[x][y], answer[i][j]);			//把所有陣列都與隨機到的陣列交換位置一次
        }
    }
}
void SetNumber(int view[][5], int answer[][5])				//製成數字，兩組依序1到8
{
    int index = 1;

    for (int x = 1; x <= 4; x++)			//一維陣列
    {
        for (int y = 1; y <= 4; y++)		//二維陣列
        {
            view[x][y] = 0;					//0 即星星“*”
            answer[x][y] = index;
            index++;

            if (index > 8)				//第一組1到8依序排完，排下一組1到8
                index = 1;
        }
    }

    ShuffleNumber(answer);				//把依序的兩組1到8號放到洗牌function
    /*cout << "-------- TESTING CHEAT SHEET --------\n"; 答案
    cout << "\t[1]\t[2]\t[3]\t[4]" << endl;

    for (int y = 1; y <= 4; y++)
    {
        cout << "[" << y << "]\t";

        for (int x = 1; x <= 4; x++)
            cout << " " << answer[x][y] << "\t";

        cout << "\n";
    }

    cout << "-------------------------------------\n";*/
}
void GetInput(int* x1, int* y1, int* x2, int* y2)			//輸入兩個坐標點
{
    char coor[100];		//坐標

    try
    {
        cout << "Please enter the coordinate1 : ";
        cin >> coor;

        if (VALIDATION)				//如果使用者輸入如上面定義的非正常字串，輸出錯誤訊息並提示使用者重新輸入
        {
            throw "Incorrect input.Please try again.";
        }

        *x1 = coor[1] - '0';		//char轉換至int
        *y1 = coor[3] - '0';
        cout << "Please enter the coordinate2 : ";
        cin >> coor;
        cout << endl;

        if (VALIDATION)
        {
            throw"Incorrect input.Please try again.";
        }

        *x2 = coor[1] - '0';
        *y2 = coor[3] - '0';

        if (*x1 == *x2 && *y1 == *y2)			//兩個坐標點不能相同
            throw "Two coordinate must be different.Please try again.";
    }
    catch (const char* ERROR_MESSAGE)
    {
        cout << ERROR_MESSAGE << endl;
        GetInput(x1, y1, x2, y2);			//再次呼叫輸入funtion
    }
}
void CheckNumber(int x1, int y1, int x2, int y2, int view[][5], int answer[][5], int* flippedCard, bool* IsMatch)			//檢查使用者是否猜對
{
    view[x1][y1] = answer[x1][y1];			//“亮出底牌”，顯示號碼
    view[x2][y2] = answer[x2][y2];

    if (answer[x1][y1] == answer[x2][y2])		//如果猜對
    {
        *flippedCard = *flippedCard + 1;		//翻牌+1
        *IsMatch = true;
    }

    if (*IsMatch == false)
    {
        *IsMatch = false;
        Get50Spaces();
    }
}
void PrintOutput(int* x1, int* y1, int* x2, int* y2, bool IsMatch, int view[][5])			//輸出結果
{
    cout << "(" << *x1 << "," << *y1 << ") " << "(" << *x2 << "," << *y2 << ")";

    if (IsMatch)			//對應上面得檢查號碼funtion，如果猜對輸出一樣；猜錯輸入出不一樣
        cout << " is Match!!\n" << endl;
    else
        cout << " is Not Match!!\n" << endl;

    cout << "\t[1]\t[2]\t[3]\t[4]" << endl;			//遊戲盤格式

    for (int y = 1; y <= 4; y++)
    {
        cout << "[" << y << "]\t";

        for (int x = 1; x <= 4; x++)
        {
            if (view[x][y] == 0)			//覆蓋“卡牌”
                cout << " *\t";
            else
                cout << " " << view[x][y] << "\t";
        }

        cout << endl;
    }

    cout << endl;

    if (!IsMatch)		//猜錯的號碼下局將蓋回去（變成星星“*”）
        view[*x1][*y1] = view[*x2][*y2] = 0;
}
void End()			//游戲結束
{
    cout << "Congratulation!!You win!!";
}
int main()
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;			//四個坐標點
    int view[5][5] = {}, answer[5][5] = {};		//看牌陣列和牌的陣列
    int flippedCard = 0;
    bool IsMatch = false;
    SetNumber(view, answer);

    while (flippedCard != 8)		//猜對完也即翻對牌次數達到8次，游戲結束
    {
        GetInput(&x1, &y1, &x2, &y2);
        CheckNumber(x1, y1, x2, y2, view, answer, &flippedCard, &IsMatch);
        PrintOutput(&x1, &y1, &x2, &y2, IsMatch, view);
    }

    End();
    system("pause");
}