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

int GetCalculation(int feet, int inch)		// Ӌ�������w�� //
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
        if (firstName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)// �z�� firstname �Ƿ�ݔ�����_��ĸ
        {
            cout << "First name input error" << endl;
            break;
        }

        inputStream >> lastName;

        if (lastName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)	// �z�� lasttname �Ƿ�ݔ�����_��ĸ
        {
            cout << "Last name input error" << endl;
            break;
        }

        if (!(inputStream >> feet))		// feet ���ǔ��֕rݔ�� error
        {
            cout << "Feet input error\n" << endl;
            break;
        }

        if (!(inputStream >> inch))		// inch ���ǔ��֕rݔ�� error
        {
            cout << "Inch input error" << endl;
            break;
        }

        if (inch >= 12 || inch < 0)		// inch ݔ�� 12 ��С� 0 �r�@ʾ error
        {
            cout << firstName << " "
                 << lastName << endl;
            cout << "Inch input Error\n" << endl;
            break;
        }

        if (feet < 0)		// feet ݔ��С� 0 �r�@ʾ error
        {
            cout << firstName << " "
                 << lastName << endl;
            cout << "Feet input error\n" << endl;
            break;
        }

        idealWeight = GetCalculation(feet, inch);

        if (feet == 0)		// ݔ�� 0 feet �r ֻ�@ʾ inch
        {
            cout << firstName << " "
                 << lastName << endl;
            cout << "Height: " << inch << " inch" << endl;
            cout << "Ideal Weight: " << idealWeight << " pounds\n" << endl;
            continue;
        }

        if (inch == 0)		// ݔ�� 0 inch �r ֻ�@ʾ feet
        {
            cout << firstName << " "
                 << lastName << endl;
            cout << "Height: " << feet << " feet" << endl;
            cout << "Ideal Weight: " << idealWeight << " pounds\n" << endl;
            continue;
        }

        cout << firstName << " "		//ݔ�����ֺ��w��
             << lastName << endl;
        cout << "Height: " << feet << " feet and " << inch << " inches" << endl;
        cout << "Ideal Weight: " << idealWeight << " pounds\n" << endl;		//ݔ�������w��
    }

    inputStream.close();
    system("pause");
    return 0;
}