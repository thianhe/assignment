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
				   coor[1] < '1' || coor[1] > '4' || coor[3] < '1' || coor[3] > '4'       //���x��������ݔ��

using namespace std;

void Get50Spaces()			//����ʮ��
{
    for (int i = 0; i < 50; i++)
        cout << endl;
}
void ShuffleNumber(int answer[][5])			//��ϴ�ơ�
{
    srand(time(NULL));		//ÿ�ε��S�C������ͬ

    for (int x = 1; x <= 4; x++)
    {
        for (int y = 1; y <= 4; y++)
        {
            int i = rand() % 4 + 1;				//��C����1��4
            int j = rand() % 4 + 1;
            swap(answer[x][y], answer[i][j]);			//��������ж��c�S�C������н��Qλ��һ��
        }
    }
}
void SetNumber(int view[][5], int answer[][5])				//�u�ɔ��֣��ɽM����1��8
{
    int index = 1;

    for (int x = 1; x <= 4; x++)			//һ�S���
    {
        for (int y = 1; y <= 4; y++)		//���S���
        {
            view[x][y] = 0;					//0 �����ǡ�*��
            answer[x][y] = index;
            index++;

            if (index > 8)				//��һ�M1��8�������꣬����һ�M1��8
                index = 1;
        }
    }

    ShuffleNumber(answer);				//������ăɽM1��8̖�ŵ�ϴ��function
    /*cout << "-------- TESTING CHEAT SHEET --------\n"; ��
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
void GetInput(int* x1, int* y1, int* x2, int* y2)			//ݔ��ɂ������c
{
    char coor[100];		//����

    try
    {
        cout << "Please enter the coordinate1 : ";
        cin >> coor;

        if (VALIDATION)				//���ʹ����ݔ�������涨�x�ķ������ִ���ݔ���e�`ӍϢ�K��ʾʹ��������ݔ��
        {
            throw "Incorrect input.Please try again.";
        }

        *x1 = coor[1] - '0';		//char�D�Q��int
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

        if (*x1 == *x2 && *y1 == *y2)			//�ɂ������c������ͬ
            throw "Two coordinate must be different.Please try again.";
    }
    catch (const char* ERROR_MESSAGE)
    {
        cout << ERROR_MESSAGE << endl;
        GetInput(x1, y1, x2, y2);			//�ٴκ���ݔ��funtion
    }
}
void CheckNumber(int x1, int y1, int x2, int y2, int view[][5], int answer[][5], int* flippedCard, bool* IsMatch)			//�z��ʹ�����Ƿ��
{
    view[x1][y1] = answer[x1][y1];			//���������ơ����@ʾ̖�a
    view[x2][y2] = answer[x2][y2];

    if (answer[x1][y1] == answer[x2][y2])		//�����
    {
        *flippedCard = *flippedCard + 1;		//����+1
        *IsMatch = true;
    }

    if (*IsMatch == false)
    {
        *IsMatch = false;
        Get50Spaces();
    }
}
void PrintOutput(int* x1, int* y1, int* x2, int* y2, bool IsMatch, int view[][5])			//ݔ���Y��
{
    cout << "(" << *x1 << "," << *y1 << ") " << "(" << *x2 << "," << *y2 << ")";

    if (IsMatch)			//��������Ùz��̖�afuntion�������ݔ��һ�ӣ����eݔ�����һ��
        cout << " is Match!!\n" << endl;
    else
        cout << " is Not Match!!\n" << endl;

    cout << "\t[1]\t[2]\t[3]\t[4]" << endl;			//�[��P��ʽ

    for (int y = 1; y <= 4; y++)
    {
        cout << "[" << y << "]\t";

        for (int x = 1; x <= 4; x++)
        {
            if (view[x][y] == 0)			//���w�����ơ�
                cout << " *\t";
            else
                cout << " " << view[x][y] << "\t";
        }

        cout << endl;
    }

    cout << endl;

    if (!IsMatch)		//���e��̖�a�¾֌��w��ȥ��׃�����ǡ�*����
        view[*x1][*y1] = view[*x2][*y2] = 0;
}
void End()			//�Α�Y��
{
    cout << "Congratulation!!You win!!";
}
int main()
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;			//�Ă������c
    int view[5][5] = {}, answer[5][5] = {};		//������к��Ƶ����
    int flippedCard = 0;
    bool IsMatch = false;
    SetNumber(view, answer);

    while (flippedCard != 8)		//����Ҳ�������ƴΔ��_��8�Σ��Α�Y��
    {
        GetInput(&x1, &y1, &x2, &y2);
        CheckNumber(x1, y1, x2, y2, view, answer, &flippedCard, &IsMatch);
        PrintOutput(&x1, &y1, &x2, &y2, IsMatch, view);
    }

    End();
    system("pause");
}