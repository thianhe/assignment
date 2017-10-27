/*Class: Computer Science And Information Engineering Year 2
 *ID : 105590050
 *Name : Lee Thian He
 *Homework Number : 4
 *Date of homework : 12 / 10 / 2017
 *Purpose : To evaluate rectangle area by entering the width and height of rectangle.
 *          Enter 'R' to construct a default rectangle,enter 'R' and "weight","height"to construct a specific rectangle.
 *			If didn't construct at first, the program won't be running until user constructs.
 *          Enter 'W' to set weight.
 *			Enter 'H' to set height.
 *			Enter 'Next' to reconstruct rectangle.
 *			Enter 'End' to exit.
 *TA,if the strtok function can't run on VS2015,please go to project options -> C/C++ -> Preprocessor -> added _CRT_SECURE_NO_WARNINGS to the list of Preprocessor Definitions
 */
#include "Rectangle.h"
void input(string& command, double& inputWidth, double& inputHeight, bool IsBuilt)
{
    //isZero is to allow user to key in 0 value
    int isZero;
    string inputLine;
    cout << "> ";
    //Get user input(whole line until end of line, EOL)
    getline(cin, inputLine);
    //Get first char of the inputLine, this should be the command
    command = inputLine[0];
    //R, H, W, A, Next, End, 0-9, .
    size_t isValidInput = inputLine.find_first_not_of("0123456789edntxAHRNW .");
    //First word of inputLine must be a command (R, H, W, A, E, N )
    size_t isValidCommand = command.find_first_not_of("AEHRWN");

    try
    {
        if (isValidInput != string::npos && isValidCommand != string::npos)
        {
            //Throw when inputLine & command contain invalid char
            throw - 1;
        }

        //Split inputLine
        char inputLine_char[MAX];
        //inputLine(string) convert to char* and paste to inputLine_char
        strcpy(inputLine_char, inputLine.c_str());
        //*splited
        char* splited = strtok(inputLine_char, " ");
        command = splited;

        if (command == "End")
        {
            splited = strtok(NULL, " ");

            if (splited != NULL)
            {
                //Got something after End
                throw - 1;
            }
        }
        else if (command == "R")
        {
            splited = strtok(NULL, " ");

            if (splited == NULL)
            {
                //Nothing after splited, R is the only input
                command = "R_default";
            }
            else
            {
                //char* to float convertion
                inputWidth = atof(splited);
                isZero = splited[0] - '0';

                if (inputWidth == 0 && isZero != 0)
                {
                    //Invalid input (non-number)
                    throw - 1;
                }

                splited = strtok(NULL, " ");

                if (splited == NULL)
                {
                    //Nothing after splited, Only 1 value
                    throw - 1;
                }

                inputHeight = atof(splited);
                isZero = splited[0] - '0';

                if (inputHeight == 0 && isZero != 0)
                {
                    //Invalid input (non-number)
                    throw - 1;
                }
            }
        }
        else if (command == "W")
        {
            splited = strtok(NULL, " ");

            if (splited == NULL) //No Value after W
            {
                throw - 1;
            }

            inputWidth = (float)atof(splited);
            isZero = splited[0] - '0';

            if (inputWidth == 0 && isZero != 0)
            {
                //Invalid input (non-number)
                throw - 1;
            }

            if (!IsBuilt)
            {
                throw 0;
            }
        }
        else if (command == "H")
        {
            splited = strtok(NULL, " ");

            if (splited == NULL) //No Value after H
            {
                throw - 1;
            }

            inputHeight = (float)atof(splited);
            isZero = splited[0] - '0';

            if (inputHeight == 0 && isZero != 0) //Invalid input (non-number)
            {
                throw - 1;
            }

            if (!IsBuilt)
            {
                throw 0;
            }
        }
        else if (command == "A")
        {
            splited = strtok(NULL, " ");

            if (splited != NULL) //Got something after A
            {
                throw - 1;
            }

            if (!IsBuilt)
            {
                throw 0;
            }
        }
        else if (command == "Next")
        {
            splited = strtok(NULL, " ");

            if (splited != NULL) //Got something after Next
            {
                throw - 1;
            }
        }
        else
        {
            //Throw when no command found above
            throw - 1;
        }
    }
    catch (int value)
    {
        if (value == -1)
        {
            cout << "Wrong input format. Please enter again.\n";
            input(command, inputWidth, inputHeight, IsBuilt);
        }

        if (value == 0)
        {
            cout << "You have no contruct a rectangle.\n";
            input(command, inputWidth, inputHeight, IsBuilt);
        }
    }
}
int main()
{
    string command = "";
    bool IsBuilt = false;
    double inputWidth, inputHeight;

    while (1)
    {
        Rectangle* _rectangle = 0;
        IsBuilt = false;

        while (command != "Next")
        {
            input(command, inputWidth, inputHeight, IsBuilt);

            if (command == "End")
            {
                exit(0);
            }
            else if (command == "R_default")
            {
                _rectangle = new Rectangle();
                IsBuilt = true;
            }
            else if (command == "R")
            {
                _rectangle = new Rectangle(inputWidth, inputHeight);
                IsBuilt = true;
            }
            else if (command == "W")
            {
                _rectangle->SetWidth(inputWidth);
            }
            else if (command == "H")
            {
                _rectangle->SetHeight(inputHeight);
            }
            else if (command == "A")
            {
                _rectangle->Area();
            }
            else if (command == "Next")
            {
                delete _rectangle;
            }
        }

        command = '0';
    }
}