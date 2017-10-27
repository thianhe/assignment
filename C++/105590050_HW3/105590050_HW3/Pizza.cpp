/*
 *Class: Computer Science And Information Engineering Year 2
 *ID : 105590050
 *Name : Lee Thian He
 *Homework Number : 3
 *Date of homework : 05 / 10 / 2017
 *Purpose : To order pizza by select given types,sizes and toppings selection.User can choose multiple toppings but cannot have duplicate choices.
 *		   Choosen order and the price will be represented after finish input, and then the program will runs next order until user enter "-1".
 */
#include"Pizza.h"

void getTypeInput(Pizza& pizza)
{
    try
    {
        char input[MAX];
        cout << "Choose pizza's type : \n";

        for (int i = 1; i <= 3; i++)							//print pizza type list
        {
            cout << i << ". " << pizza.Type[i] << endl;
        }

        cin >> input;

        if (input[0] == '-'  && input[1] == '1')
        {
            throw - 1;
        }

        if (!isdigit(input[0]) || input[0] > '3' || input[0] < '0')  				//print error when input non-numerical or out of range
        {
            throw "Invalid input. Please input again : ";
        }

        int temp = input[0] - '0';
        pizza.inputType = temp;
    }
    catch (const char* ERROR_MESSAGE)
    {
        cout << ERROR_MESSAGE << endl;
        getTypeInput(pizza);
    }
    catch (const int value)				//program terminates when input -1
    {
        exit(0);
    }
}

void getSizeInput(Pizza& pizza)
{
    try
    {
        char input[MAX];
        cout << "\nChoose pizza's size : \n";

        for (int i = 1; i <= 3; i++)			//print pizza size list
        {
            cout << i << ". " << pizza.Size[i] << endl;
        }

        cin >> input;
        cout << endl;

        if (input[0] == '-'  && input[1] == '1')
        {
            throw - 1;
        }

        if (!isdigit(input[0]) || input[0] > '3' || input[0] < '0')  		//print error when input non-numerical or out of range
        {
            throw "Invalid input. Please input again : ";
        }

        int temp = input[0] - '0';
        pizza.inputSize = temp;
    }
    catch (const char* ERROR_MESSAGE)
    {
        cout << ERROR_MESSAGE << endl;
        getSizeInput(pizza);
    }
    catch (const int value)			//program terminates when input -1
    {
        exit(0);
    }
}
void getToppingInput(Pizza& pizza)
{
    try
    {
        bool IsDuplicatedToppings = false;
        int i, j, input_INT = -1;
        char input[MAX];

        for (i = 0; input_INT != 0; i++)		//print pizza topping list
        {
            if (IsDuplicatedToppings == false)
            {
                cout << "Choose pizza's topping : \n";

                for (int i = 1; i <= 9; i++)
                    cout << i << ". " << pizza.Topping[i] << endl;
            }

            IsDuplicatedToppings = false;
            cin >> input;
            cout << endl;

            if (input[0] == '-'  && input[1] == '1')		//print error if inputs illegal number
                throw - 1;

            if ((!isdigit(input[0])) || input[0] > '9' || input[0] < '0')
                throw "Invalid input. Please input again : ";

            //Convert char_input into int_input
            input_INT = input[0] - '0';

            for (j = 0; j < MAX; j++)
            {
                if (pizza.inputTopping[j] == input_INT && input_INT != 0)		//check every input topping whether it's duplicate or not
                {
                    cout << "You already choose this topping. Please choose again.\n";
                    IsDuplicatedToppings = true;
                    i--;
                    break;
                }
            }

            if (IsDuplicatedToppings == false)
            {
                pizza.inputTopping[i] = input_INT;
            }
        }
    }
    catch (const char* ERROR_MESSAGE)
    {
        cout << ERROR_MESSAGE << endl;
        getToppingInput(pizza);
    }
    catch (const int value)		//program terminates when input -1
    {
        exit(0);
    }
}

int main()
{
    while (1)
    {
        Pizza pizza;
        getTypeInput(pizza);
        getSizeInput(pizza);
        getToppingInput(pizza);
        pizza.outputDescription();
    }

    system("pause");
}