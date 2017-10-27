/*Class: Computer Science And Information Engineering Year 2
 *ID : 105590050
 *Name : Lee Thian He
 *Homework Number : 5
 *Date of homework : 19 / 10 / 2017
 *Purpose : To help princess Eve to determine which suitor she would marry.
*/
#include "Suitor.h"

int main()
{
    Suitor suitor;

    while (suitor.IsValidInput())			//check valid input
    {
        suitor.CalculateSuitor();			//count answer
    }

    return 0;
}
