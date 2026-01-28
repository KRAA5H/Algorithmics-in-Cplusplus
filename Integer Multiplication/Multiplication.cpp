#include <iostream>
#include <cmath>
#include <string>

int recursiveMult(int x, int y);
int karatsuba(int x, int y);

int main() {

    int x; // x = 56 * 10^(n/2) + 78 
    std::cin >> x;
    int y; // y = 12 * 10^(n/2) +  34
    std::cin >> y;
    int recursiveResult = recursiveMult(x, y);
    int karatsubaResult = karatsuba(x, y);
    std::cout << "Recursive Multiplication: " << recursiveResult << std::endl;
    std::cout << "Karatsuba Multiplication: " << karatsubaResult << std::endl;
    
    return 0;
}

int recursiveMult(int x, int y) {

    int lengthX = std::to_string(x).length(); // int lengthX = log10(x) + 1;
    int splitConstant = (pow(10, (lengthX / 2)));
    int a = x / splitConstant;
    int b = x % splitConstant;

    // int lengthY = std::to_string(y).length(); (assuming length is equal) // int lengthY = log10(y) + 1;
    int c = y / splitConstant;
    int d = y % splitConstant;

    int result = a * c * pow(10, lengthX) + (((a * d) + (b * c)) * pow(10, lengthX / 2)) + (b * d);

    return result;
}

int karatsuba(int x, int y) {

    int lengthX = std::to_string(x).length();
    int splitConstant = (pow(10, (lengthX / 2)));
    int a = x / splitConstant;
    int b = x % splitConstant;

    int c = y / splitConstant;
    int d = y % splitConstant;

    int ac = a*c;
    int bd = b*d;

    int step4 = ((a+b) * (c+d)) - ac - bd; 
    int result = ac * pow(10, lengthX) + (step4 * pow(10, lengthX / 2)) + bd; 

    return result;
}
