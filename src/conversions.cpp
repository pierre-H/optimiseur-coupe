#include <iostream>
#include <string>
#include "conversions.h"

using namespace std;
/*
int main ()
{
    cout <<conversion (12, (string)"yard")<< endl;
    return 0;
}
*/
float conversion (float number, string unit)
{
    if (unit == "mm")
        return number;
    if (unit == "cm")
        return number * 10;
    else if (unit == "m")
        return number * 1000;
    else if (unit == "inches")
        return number * 25.4;
    else if (unit == "foot")
        return number * 304.8;
    else if (unit ==  "yard")
        return number * 914.4;
    else
    {
        cout << "unité : mauvais format" << endl;
        return -1.0;
    }
}

