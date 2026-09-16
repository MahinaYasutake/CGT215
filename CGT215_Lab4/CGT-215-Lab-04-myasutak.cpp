#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Clears invalid input and asks again until the user enters a valid number.
double getNumber(const string& prompt) {
    double value;

    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return value;
}

// Gets a positive whole number for factorial and series element counts.
int getPositiveWholeNumber(const string& prompt) {
    double input;

    cout << prompt;
    while (!(cin >> input) || input <= 0 || floor(input) != input) {
        cout << "Invalid input. Please enter a positive whole number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return static_cast<int>(input);
}

void printMenu() {
    cout << "\nPlease Select which operation to perform:" << endl;
    cout << "\t1. Factorial" << endl;
    cout << "\t2. Arithmetic Series" << endl;
    cout << "\t3. Geometric Series" << endl;
    cout << "\t4. Exit" << endl;
}

void factorial() {
    int number = getPositiveWholeNumber("\nEnter a positive whole number: ");
    unsigned long long result = 1;

    cout << number << "! = ";
    for (int term = 1; term <= number; ++term) {
        result *= static_cast<unsigned long long>(term);
        cout << term;
        if (term < number) {
            cout << " * ";
        }
    }
    cout << " = " << result << endl;
}

void arithmetic() {
    double difference = getNumber("\nEnter the difference: ");
    double firstTerm = getNumber("Enter the starting number: ");
    int elements = getPositiveWholeNumber("Enter the number of elements: ");
    double sum = 0;

    cout << "\n";
    for (int index = 0; index < elements; ++index) {
        double term = firstTerm + index * difference;
        sum += term;
        cout << term;
        if (index < elements - 1) {
            cout << " + ";
        }
    }
    cout << " = " << sum << endl;
}

void geometric() {
    double ratio = getNumber("\nEnter the ratio (r): ");
    double firstTerm = getNumber("Enter the starting number (a): ");
    int elements = getPositiveWholeNumber("Enter the number of elements: ");
    double sum = 0;
    double term = firstTerm;

    cout << "\n";
    for (int index = 0; index < elements; ++index) {
        sum += term;
        cout << term;
        if (index < elements - 1) {
            cout << " + ";
        }
        term *= ratio;
    }
    cout << " = " << sum << endl;
}

int main() {
    int choice;
    char again;

    do {
        printMenu();
        choice = static_cast<int>(getPositiveWholeNumber("Your Selection: "));

        if (choice == 1) {
            factorial();
        } else if (choice == 2) {
            arithmetic();
        } else if (choice == 3) {
            geometric();
        } else if (choice == 4) {
            return 0;
        } else {
            cout << "Invalid selection. Please choose 1, 2, 3, or 4." << endl;
        }

        cout << "Go Again? [Y/N] ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
