#include <iostream>
#include <limits>

using namespace std;

void printMenu(int& choice) {
    cout << "========================================" << endl;
    cout << "        Welcome to My Calculator        " << endl;
    cout << "========================================" << endl;
    cout << "Please select an operation:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "\nYour selection: ";

    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Please enter a number from 1 to 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void getChoices(float& firstValue, float& secondValue) {
    cout << "\nEnter the first value: ";
    while (!(cin >> firstValue)) {
        cout << "Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the second value: ";
    while (!(cin >> secondValue)) {
        cout << "Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void addition(float firstValue, float secondValue) {
    cout << "\n" << firstValue << " + " << secondValue << " = "
         << firstValue + secondValue << endl;
}

void subtraction(float firstValue, float secondValue) {
    cout << "\n" << firstValue << " - " << secondValue << " = "
         << firstValue - secondValue << endl;
}

void multiplication(float firstValue, float secondValue) {
    cout << "\n" << firstValue << " * " << secondValue << " = "
         << firstValue * secondValue << endl;
}

void division(float firstValue, float secondValue) {
    if (secondValue == 0) {
        cout << "\nDivision by zero is not allowed." << endl;
        return;
    }

    cout << "\n" << firstValue << " / " << secondValue << " = "
         << firstValue / secondValue << endl;
}

int main() {
    int choice;
    float firstValue;
    float secondValue;

    printMenu(choice);
    getChoices(firstValue, secondValue);

    if (choice == 1) {
        addition(firstValue, secondValue);
    } else if (choice == 2) {
        subtraction(firstValue, secondValue);
    } else if (choice == 3) {
        multiplication(firstValue, secondValue);
    } else if (choice == 4) {
        division(firstValue, secondValue);
    }

    return 0;
}
