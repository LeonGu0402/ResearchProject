
#include <iostream>

int main()
{
    const double pi = 3.14; //cannot change constant 

    //int x = 10; //two int devided eachother will return int
    double x = 10; //unless one side is a double or float
    int y = 3;
    double z = x / y;

    std::cout << z;

    int a = x++; //x = 11, a = 10
    int b = ++x; //x = 12(incremented in last line), b = 12


    return 0;
}

