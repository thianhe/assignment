#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void convert(int num)
{
    int thousands=0,hundreds=0,tens=0,ones=0;
    ones=num%10;
    tens=(floor(num%100)-ones)/10;
    hundreds=(floor(num%1000)-tens*10-ones)/100;
    thousands=(floor(num/1000));
    switch(thousands)
    {
        case 1: printf("M"); break;
        case 2: printf("MM"); break;
        case 3: printf("MMM"); break;
    }

    switch(hundreds)
    {
        case 1:printf("C");         break;
        case 2:printf("CC");        break;
        case 3:printf("CCC");       break;
        case 4:printf("CD");        break;
        case 5:printf("D");         break;
        case 6:printf("DC");        break;
        case 7:printf("DCC");       break;
        case 8:printf("DCCC");      break;
        case 9:printf("CM");       break;
    }
    switch(tens)
    {
        case 1:printf("X");         break;
        case 2:printf("XX");        break;
        case 3:printf("XXX");       break;
        case 4:printf("XL");        break;
        case 5:printf("L");         break;
        case 6:printf("LX");        break;
        case 7:printf("LXX");       break;
        case 8:printf("LXXX");      break;
        case 9:printf("XC");       break;
    }

    switch(ones)
    {
    case 1:printf("I");             break;
    case 2:printf("II");            break;
    case 3:printf("III");           break;
    case 4:printf("IV");            break;
    case 5:printf("V");             break;
    case 6:printf("VI");            break;
    case 7:printf("VII");           break;
    case 8:printf("VIII");          break;
    case 9:printf("IX");
    }

}

int main()
{
    int num;
    scanf("%d",&num);
    convert(num);
}
