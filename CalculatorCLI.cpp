#include <iostream>
#include <string>

using namespace std;

// addition
float add(float a, float b)
{
    return a + b;
}

// subtraction
float subtract(float a, float b)
{
    return a - b;
}

// multiplication 
float multiply(float a, float b)
{
    return a * b;
}

// divide
float divide(float a, float b)
{

    if (b == 0)
    {
        cout << "Error! Cannot divide by zero.\n";
        return 0;
    }
    return a / b;
}

// modulus
int mod(int a, int b)
{
    if (b == 0)
    {
        cout << "Error! Cannot do modulus with zero" << endl;
        return 0;
    }
    return a % b;
}

// input validation
float getValidInput(string prompt)
{
    float value;

    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid!, Enter a number.\n";
        }
        else
        {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

// display menu
float displayMenu()
{
    cout << "===============================" << endl;
    cout << "   Welcome to CLI Calculator" << endl;
    cout << "===============================" << endl;

    float a = getValidInput("Enter first number: ");

    char op;
    cout << "\nEnter operation(+, -, *, /, %(Modulus)): ";
    cin >> op;
    cin.ignore(1000, '\n');

    float b = getValidInput("\nEnter second number: ");

    switch (op)
    {
    case '+':
        return add(a, b);
    case '-':
        return subtract(a, b);
    case '*':
        return multiply(a, b);
    case '/':
        return divide(a, b);
    case '%':
        return mod(int(a), int(b));
    default:
        cout << "Invalid operator!\n";
        return 0;
    }
}

int main()
{
    char choice;
    do
    {
        float result = displayMenu();
        cout << "\nResult: " << result << endl;

        cout << "\nDo you want to continue?(y/n): ";
        cin >> choice;
        cin.ignore(1000, '\n');

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank You for using CLI Calculator" << endl;

    return 0;
}