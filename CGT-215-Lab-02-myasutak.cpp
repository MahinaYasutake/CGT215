#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float A;
    float B;

    cout << "Hello, my name is Mahina and I'm going to solve the equation:" << endl;
    cout << "Ax + B = 0" << endl;
    cout << "For x" << endl << endl;

    cout << "Please enter a value for A: ";
    cin >> A;

    cout << "Please enter a value for B: ";
    cin >> B;

    cout << endl << "Solving " << A << "x + " << B << "=0 for x..." << endl << endl;

    if (A == 0)
    {
        if (B == 0)
        {
            cout << "The answer is: infinitely many solutions" << endl;
        }
        else
        {
            cout << "The answer is: no solution" << endl;
        }
    }
    else
    {
        cout << "The answer is:" << endl;
        cout << "x=" << fixed << setprecision(5) << (-B / A) << endl;
    }

    return 0;
}
