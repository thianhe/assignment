#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#define MAX 10
using namespace std;
class Rectangle
{
    public:
        //the Constructor
        Rectangle()
        {
            cout << "Rectangle is called.\n";
            width = 5;
            height = 5;
        }
        Rectangle(double w, double h)
        {
            cout << "Rectangle(double, double) is called.\n";
            width = w;
            height = h;
        }
        ~Rectangle()		//the destructor
        {
            cout << "===============================\n";
        }
        void SetWidth(double w)
        {
            cout << "SetWidth(double) is called." << endl;
            width = w;
        }
        void SetHeight(double h)
        {
            cout << "SetHeight(double) is called." << endl;
            height = h;
        }
        void Area()
        {
            cout << "Area() is called" << endl;
            double area;
            area = width * height;
            cout << "Rectangle's area is " << area << ".\n";
        }
    private:
        double height;
        double width;
        double area;
};
