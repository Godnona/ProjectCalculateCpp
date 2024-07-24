#include <iostream>
#include <cmath>
#include <string>
#include <ctype.h>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;

// ============================= SimpleCalculate =============================

class SimpleCalculate
{
    public:
        SimpleCalculate();
        void Run(const string &chuoi);
    private:
        int Prioritize(char c);
        double Calculate(double a, double b, char c);
};

SimpleCalculate::SimpleCalculate()
{}

int SimpleCalculate::Prioritize(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    return 0;
}

double SimpleCalculate::Calculate(double a, double b, char c)
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
            return a / b;
            
        default:
            break;
    }
    return 0;
}

void SimpleCalculate::Run(const string &chuoi)
{
    stack <double> num;
    stack <char> ope;
    
    for(int i = 0; i < chuoi.length(); i++)
    {
        if(chuoi[i] == ' ') continue; // neu rong thi bo qua

        if(isdigit(chuoi[i])) // neu la so thi dua vo stack
        {
            double tmp = 0;
            while (i < chuoi.length() && isdigit(chuoi[i])) // tinh so co n chu so
            {
                tmp = (tmp * 10) + (chuoi[i] - '0');
                ++i;
            }
            num.push(tmp);
            i--;
        }
        else
        {
            while (!ope.empty() &&  Prioritize(ope.top()) >= Prioritize(chuoi[i]) )
            {
                double val2 = num.top();
                num.pop();
                double val1 = num.top();
                num.pop();
                char op = ope.top();
                ope.pop();

                num.push(Calculate(val1, val2, op));
            }
            
            ope.push(chuoi[i]);
        }
    }

    while (!ope.empty())
    {
        if(num.size() < 2)
            break;
        double val2 = num.top();
        num.pop();
        double val1 = num.top();
        num.pop();
        char op = ope.top();
        ope.pop();

        num.push(Calculate(val1, val2, op));
    }

    if(!num.empty())
        std::cout << "Ket qua: " << num.top() << std::endl;
    else std::cout << "Error" << std::endl;
    
}

// ===================================== Math-Pow-Sqrt ==================================================
class MyMath
{
    public:
        MyMath();
        void PhuongTrinhBac1();
        void PhuongTrinhBac2();
        void Tinhcan();
        void Tinhluythua();
};

MyMath::MyMath()
{}

void MyMath::Tinhcan()
{
    float n;
    std::cout << "Nhap so can khai can: " << std::endl;
    std::cin >> n;
    if(n>0)
    {
       std::cout << "Ket qua: " << sqrt(n) << std::endl; 
    }
}

void MyMath::Tinhluythua()
{
    float n;float somu;
    std::cout << "Nhap lan luot Co so va So mu: " << endl;
    std::cin >> n; std::cin >> somu;
    if(n!=0)
    {
      std::cout << "Ket qua: " << pow(n,somu);
    }
}

void MyMath::PhuongTrinhBac1()
{
    float a,b;
    std::cout<< "ax+b=0"<< std::endl;
    std::cout << "Nhap a: "; std::cin>>a;
    std::cout<<"Nhap b: "; std::cin>>b;
    if(a!=0)
    {
        std::cout << "X=" << -b/a;
    }
    else if (a==0)
        std::cout<<"ko tinh dc";

}

void MyMath::PhuongTrinhBac2()
{
    int a,b,c;
    long long delta;
    std::cout<<"ax^(2)+bx+c=0"<<std::endl;
    std::cout<<"Nhap a: "; std::cin>>a;
    std::cout<<"Nhap b: "; std::cin>>b;
    std::cout<<"Nhap c: "; std::cin >>c;
    
    delta = 1ll*b * b - 4ll * a*c;
    if (delta > 0)
    {
        double x1,x2;
        x1=((double)-b-sqrt(delta)) / (2*a);
        x2=((double)-b+sqrt(delta)) / (2*a);
        std::cout << "X1 = " << setprecision(5) << fixed << x1 << " X2 = "<< setprecision(5) << fixed << x2 << std::endl;
    }    
    else if(delta == 0)
        std::cout << "X = " << (double)-b / (2 * a);
    else if(delta < 0)
        std::cout<< "Khong tinh dc " << std::endl ;
    else if (a==0){
        std::cout << "X=" << -b/a;
    }
}   



// ===================================== Main ==================================================

int main()
{   
    int inp; // your choice
    string expression; // enter expression
    
    
    // Declare function
    SimpleCalculate calculateExpression;
    // test.Run("1+2+3+ 4/3 + 5"); // test eval()
    MyMath myMath;

    while (true)
    {
        std::cout << std::endl;
    
        std::cout << "================== May tinh Casio ===================" << endl;
        std::cout << "| Chon chuc nang :                                  |" << endl;
        std::cout << "|  1. Tinh gia tri bieu thuc:                       |" << endl;
        std::cout << "|  2. Giai phuong trinh bac 1:                      |" << endl;
        std::cout << "|  3. Giai phuong trinh bac 2:                      |" << endl;
        std::cout << "|  4. Tinh can bac 2:                               |" << endl;
        std::cout << "|  5. Tinh luy thua:                                |" << endl;
        std::cout << "|  6. Thoat                                         |" << endl;
        std::cout << "=====================================================" << endl;

        std::cout << "Nhap lua chon: "; std::cin >> inp;
        std::cin.ignore();

        switch (inp)
        {
            case 1:
                std::cout << "Nhap bieu thuc: ";
                getline(cin, expression);
                calculateExpression.Run(expression);
                break;
            case 2:
                myMath.PhuongTrinhBac1();
                break;
            case 3:
                myMath.PhuongTrinhBac2();
                break;
            case 4:
                myMath.Tinhcan();
                break;
            case 5:
                myMath.Tinhluythua();
                break;
                
            case 6:
                return 0;
            default:
                std::cout << "Nhap lai!" << endl;
                break;
        }
        std::cout << std::endl;
        std::cout << "=====================================================" << endl;
    }

    std::cout << std::endl;
    system("pause");
    return 0;
}