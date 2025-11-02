// Test4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cmath>
#include <cstdlib>
#include<ctime>

using namespace std;

int main()
{
    double roundDown = floor(1.2);

    double power = pow(2, 3);

    /*cout << roundDown << endl;
    cout << power << endl;*/

    auto fileSize = 900000l;
    auto isDead = true;
    auto word = "Hello World";



    long elapsedSeconds = time(nullptr); //Jan 1 1970
    srand(elapsedSeconds);
    double randomNum = rand() % 10;

    cout << elapsedSeconds << endl;
    cout << randomNum;

    return 0;
}