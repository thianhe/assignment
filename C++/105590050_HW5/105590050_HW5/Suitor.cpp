#include "Suitor.h"

bool Suitor::IsValidInput()
{
    string tempInput;
    cout << "How many suitors are there?\n";

    while (1)
    {
        cin >> tempInput;
        bool inputType = true;

        for (int i = 0; i < size(tempInput); i++)
        {
            if (isdigit(tempInput[i]) == false)				//check valid input number 1 by 1
            {
                inputType = false;
            }
        }

        if (inputType)
        {
            break;
        }

        cout << "Wrong input. Please input again: " << endl;
    }

    _manAmount = stoi(tempInput);

    if (_manAmount == 0)
    {
        return false;
    }

    return true;
}

void Suitor::SetVector(vector<int>& suitor)
{
    for (int i = 1; i <= _manAmount; i++)				//push all of the man amount into vector
    {
        suitor.push_back(i);
    }
}

void Suitor::CalculateSuitor()
{
    vector<int> suitor;
    SetVector(suitor);

    if (suitor.size() == 1 || suitor.size() == 2)
    {
        cout << "\nThe lucky winner is.... Number "
             << suitor[suitor.size() - 1] << " !\n";
        return;
    }

    for (int i = 2; suitor.size() > 1; i = (i + 2) % suitor.size())
    {
        suitor.erase(suitor.begin() + i);		//erase the third man

        for (int j = 0; j < suitor.size(); j++)
        {
            if (suitor.size() == 1)			// output when only one man left
            {
                cout << "\nThe lucky winner is.... Number "
                     << suitor[j] << " !\n";
            }
        }
    }

    cout << endl;
}