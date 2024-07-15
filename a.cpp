#include <iostream>
#include <cmath>
#include <string>
#include <ctype.h>
#include <stack>
#include <vector>
using namespace std;

// ============================= SimpleCalculate =============================

class SimpleCalculate
{
    public:
        SimpleCalculate();
        void Run(const string &chuoi);
    private:
        int Prioritize(char c);
        double Calculate(long long a, long long b, char c);
};

SimpleCalculate::SimpleCalculate()
{
    cout << "Start calculating..." << endl;
}

int SimpleCalculate::Prioritize(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    return 0;
}

double SimpleCalculate::Calculate(long long a, long long b, char c)
{
    switch (c)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if(b != 0)
                return a / b;
    }
    return 0;
}

void SimpleCalculate::Run(const string &chuoi)
{
    stack<long long> values;
    stack<char> operators;
    int i;
    for(int i = 0; i < chuoi.length(); i++)
    {
        if(chuoi[i] == ' ') continue;

        if(isdigit(chuoi[i]))
        {
            long long val = 0;
            while (i < chuoi.length() && isdigit(chuoi[i]))
            {
                val = (val * 10) + (chuoi[i] - '0');
                ++i;
            }
            values.push(val);
            --i;
        }
        else
        {
            while (!operators.empty() && Prioritize(operators.top()) >= Prioritize(chuoi[i]))
            {
                int a = values.top();
                values.pop();
                int b = values.top();
                values.pop();
                char c = operators.top();
                operators.pop();
                values.push(Calculate(a, b, c));
            }
            operators.push(chuoi[i]);
            
        }
    }

    while (!operators.empty())
    {
        long long a = values.top();
        values.pop();
        long long b = values.top();
        values.pop();
        char c = operators.top();
        operators.pop();
        values.push(Calculate(a, b, c));
    }
    if (!values.empty())
        cout << values.top() << endl;
    else
        cout << "No result to display!" << endl;
}


// ===================================== Main ==================================================

int main()
{
    cout << "===================== Calculate =====================" << endl;
    cout << "| Select function :                                 |" << endl;
    cout << "|  1. Simple calculate                              |" << endl;
    cout << "|  2. Solve a quadratic equation with one unknown   |" << endl;
    cout << "=====================================================" << endl;

    cout << endl;
    int inp;
    cout << "Input your choice: "; cin >> inp;
    cin.ignore();
    string s;
    SimpleCalculate calculate;
    switch (inp)
    {
        case 1:
            cout << "Enter the expression: ";
            getline(cin, s);
            calculate.Run(s);
            break;
        case 2:
            cout << "nothing";
            break;
        default:
            cout << "Pleas enter again" << endl;
            break;
    }

    cout << endl;
    system("pause");
    return 0;
}

