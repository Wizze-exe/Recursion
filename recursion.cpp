#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int sizeArray = 100;

unsigned long long factorialRecursion(unsigned long long n);
unsigned long long factorial(unsigned long long n);
int fibonacci(int n);
int power(int num, int n);
int sumArray(int array[], int n);
void fillArray(int list[], int listLength);

int main()
{
    int num, pow;
    int array[sizeArray];
    
    cout << "Input num: ";
    cin >> num;
    cout << "Input power of num: ";
    cin >> pow;

    //Рекурсивный факториал:
    unsigned int startTime = clock();
    cout << "\nRecursion factorial: " << factorialRecursion(num) << endl;
    unsigned int endTime = clock();
    cout << "Time of rec fact: " << endTime - startTime << endl;

    //Итерационный факториал
    startTime = clock();
    cout << "Factorial: " << factorial(num) << endl;
    endTime = clock();
    cout << "Time of fact: " << endTime - startTime << endl;


    cout << "\nFibonacci: " << fibonacci(num) << endl;
    cout << "Power of num: " << power(num, pow) << endl;

    fillArray(array, sizeArray);
    cout << "Sum of nums in array: " << sumArray(array, sizeArray);

    return 0;
}

unsigned long long factorialRecursion(unsigned long long n) {
    if (n > 1)
        return n * factorial(n - 1);
    return 1;
}

unsigned long long factorial(unsigned long long n) {
    unsigned long long result = 1;
    if (n > 1) {
        while (n != 0) {
            result *= n;
            n--;
        }
        return result;
    }
    return 1;
}

int fibonacci(int n) {
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int power(int num, int n) {
    if (num == 1 || n == 0)
        return 1;
    if (n == 1)
        return num;
    return num * power(num, n - 1);
}

int sumArray(int array[], int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return array[0];
    return sumArray(array, n - 1) + array[n - 1];
}

void fillArray(int list[], int listLength) {
    srand(time(0));
    for (int i = 0; i < listLength; i++) {
        list[i] = rand() % 100;
    }
}
