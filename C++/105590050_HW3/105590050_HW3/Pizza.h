#include <iostream>
#include <string>
#include <cstdlib>
#include <ctype.h>
#define MAX 30
using namespace std;
class Pizza
{
    public:
        int inputType = 0;
        int inputSize = 0;
        int inputTopping[MAX] = { 0 };
        string Type[4] =
        {
            "", "Deep dish", "Hand tossed", "Pan"
        };
        string Size[4] =
        {
            "", "Small", "Medium", "Large"
        };
        string Topping[10] =
        {
            "", "Pepperoni", "Pepperoni(NY Style)", "Asiago", "Bocconcini",
            "Cheddar", "Feta", "Goat Cheese", "Mozzarella", "Parmsesan"
        };

        int computePrice()
        {
            int price = 0, totaltoppings = 0;

            for (int i = 0; i < MAX; i++)		//check every toppings that input legal value
            {
                if (inputTopping[i] != 0)
                    totaltoppings++;
            }

            switch (inputSize)
            {
                case 1:
                    price = 10;
                    break;

                case 2:
                    price = 14;
                    break;

                case 3:
                    price = 17;
                    break;
            }

            price += totaltoppings * 2;
            return price;
        }

        void outputDescription()
        {
            int totalTopping = 0;

            for (int i = 0; i < MAX; i++)		//check every toppings that input legal value
            {
                if (inputTopping[i] != 0)
                    totalTopping++;
            }

            cout << "Your order : \n"
                 << "Type : " << Type[inputType] << endl
                 << "Size : " << Size[inputSize] << endl
                 << "Toppings : ";

            if (totalTopping == 0)
                cout << "None\n" << endl;
            else
            {
                cout << Topping[inputTopping[0]];

                if (totalTopping > 1)						//output more toppings when user chooses more than 1 topping
                {
                    for (int i = 1; i < totalTopping; i++)
                        cout << " & " << Topping[inputTopping[i]];
                }

                cout << "\n\n";
            }

            int price = computePrice();
            cout << "Your Pizza's price: $" << price << "\n"
                 << "Thank you for your coming!\n\n";
        }
};
