/*
    Class: Computer Science And Information Engineering Year 2
	ID : 105590050
	Name : Lee Thian He
	Homework Number : 1
	Date of homework : 22 / 9 / 2017
	Purpose : To calculate ideal weight by given correct data.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int GetCalculation(int feet, int inch)		// 計算理想體重 //
{
    int idealWeight;

    if (feet >= 5)
    {
        inch = inch + (feet - 5) * 12;
        idealWeight = 110 + (inch * 5);
    }
    else
    {
        idealWeight = 110;
    }

    return idealWeight;
}

int main()
{
    int feet, inch, idealWeight = 0;
    string firstName;
    string lastName;
    fstream inputStream;
    inputStream.open("weight.txt");

    while (inputStream >> firstName)
    {
        if (firstName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)// 檢查 firstname 是否輸入正確字母
        {
            cout << "First name input error" << endl;
            break;
        }

        inputStream >> lastName;

        if (lastName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)	// 檢查 lasttname 是否輸入正確字母
        {
            cout << "Last name input error" << endl;
            break;
        }

        if (!(inputStream >> feet))		// feet 不是數字時輸入 error
        {
            cout << "Feet input error\n" << endl;
            break;
        }

        if (!(inputStream >> inch))		// inch 不是數字時輸入 error
        {
            cout << "Inch input error" << endl;
            break;
        }

        if (inch >= 12 || inch < 0)		// inch 輸入 12 或小於 0 時顯示 error
        {
            cout << firstName << " "
                 << lastName << endl;
            cout << "Inch input Error\n" << endl;
            break;
        }

        if (feet < 0)		// feet 輸入小於 0 時顯示 error
        {
            cout << firstName << " "
                 << lastName << endl;
            cout << "Feet input error\n" << endl;
            break;
        }

        idealWeight = GetCalculation(feet, inch);

        if (feet == 0)		// 輸入 0 feet 時 只顯示 inch
        {
            cout << firstName << " "
                 << lastName << endl;
            cout << "Height: " << inch << " inch" << endl;
            cout << "Ideal Weight: " << idealWeight << " pounds\n" << endl;
            continue;
        }

        if (inch == 0)		// 輸入 0 inch 時 只顯示 feet
        {
            cout << firstName << " "
                 << lastName << endl;
            cout << "Height: " << feet << " feet" << endl;
            cout << "Ideal Weight: " << idealWeight << " pounds\n" << endl;
            continue;
        }

        cout << firstName << " "		//輸出名字和體重
             << lastName << endl;
        cout << "Height: " << feet << " feet and " << inch << " inches" << endl;
        cout << "Ideal Weight: " << idealWeight << " pounds\n" << endl;		//輸出理想體重
    }

    inputStream.close();
    system("pause");
    return 0;
}