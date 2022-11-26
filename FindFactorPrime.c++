#include <iostream>
#include <math.h>
using namespace std;

void ClearFunct()
{
    system("cls");
}

// Variable globe
bool checkPrime = true; // Prime flag

bool CheckPrimeFact(int num)
{

    while (num % 2 == 0)
    {
        cout << "\t";
        num = num / 2;
        if (num % 2 == 0)
        {
            checkPrime = false;
            break;
        }
    }
    return true;

    for (int x = 3; x <= sqrt(num); x = x + 2)
    {
        while (x % 2 == 0)
        {
            cout << x;
            num = num / x;
            if (num % x == 0)
            {
                checkPrime = false;
                break;
            }
        }
    }
    return true;

    if (num > 2)
    {
        cout << num << "\t";
    }
}

int main()
{
    // Call function clear screen
    ClearFunct();

    int number;
    char choose;

    do
    {
        // input prime factor
        cout << "Enter your Prime Factor : ";
        cin >> number;

        // Value of the prime factor
        cout << "This is the value of Prime Factor : " << number << " are : ";
        CheckPrimeFact(number);

        // Check that prime factor true / false
        if (checkPrime)
            cout << "This is not prime factor";
        else
            cout << "This is Prime Factor";

        // Check user want to enter a new prime factor
        cout << "\nWould you like to try again? Y/N || y/n : ";
        cin >> choose;

    } while (choose == 'Y' || choose == 'y');
    // if user don't want to enter a new prime factor
    cout << "Thanks for enter prime factor";

    return 0;
}