/*
* Class            : Computer Science And Information Engineering Year 2
* ID               : 105590050
* Name             : Lee Thian He
* Homework Number  : 6
* Date of homework : 26 / 10 / 2017
* Purpose          : To calculate the product of two-dimensional vector A and B.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Vector2D.h"

using namespace std;

void Input(int& x, int& y)
{
    try
    {
        char leftBlacket, rightBlacket, comma, enter;
        string isExit;
        leftBlacket = rightBlacket = comma = enter = '0';
        cin >> leftBlacket;

        if (leftBlacket == 'E')
        {
            //This might be exit command
            cin >> isExit;

            if (isExit != "xit")
            {
                throw "Input format incorrect. Please input again: ";
            }

            exit(0);
        }
        else if (leftBlacket == '(')
        {
            if (!(cin >> x))
            {
                throw "Input non-numeric. Please input again: ";
            }

            cin >> comma;

            if (!(cin >> y))
            {
                throw "Input non-numeric. Please input again: ";
            }

            cin >> rightBlacket;

            if (comma != ',' || rightBlacket != ')')
            {
                throw "Input format incorrect. Please input again:";
            }
        }
        else
        {
            throw "Input format incorrect. Please input again:";
        }
    }
    catch (const char* ERROR_MESSAGE)
    {
        cout << ERROR_MESSAGE << "\n";		//output error
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Input(x, y);
    }
}
int main()
{
    Vector2D vectorA, vectorB;;
    int x, y;

    while (1)
    {
        cout << "Please input vectorA: ";
        Input(x, y);			//check input validation
        vectorA.SetXY(x, y);	//set vectorA x and y
        cout << "Please input vectorB: ";
        Input(x, y);			//check input validation
        cout << endl;
        vectorB.SetXY(x, y);	//set vectorB x and y
        cout << "vectorA = " << "(" << vectorA.GetX() << "," << vectorA.GetY() << ") "
             << "vectorB = " << "(" << vectorB.GetX() << "," << vectorB.GetY() << ")\n"
             << "vectorA * vectorB = " << vectorA* vectorB << endl << endl << endl;
    }
}