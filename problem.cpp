// week 5 part 2
// Alwin Lau
// problem class for a teacher

#include<iostream>
#include<stdio.h> // need for NULL
#include<stdlib.h> // need for rand
#include<ctime> // need for time
#include<conio.h> // need for _getch
#include"Fraction.cpp"
using namespace std;

class Problem: public Fraction
{
private:
	bool isNumeratorOne;
	bool isDenominatorSame;
	bool isSumLessThanOne;
	Fraction operand1;
	Fraction operand2;
	Fraction sum;
	Fraction answer;

public:
    void askProblem(bool = 0, bool = 0, bool = 0);
};

void Problem::askProblem(bool iNO, bool iDS, bool iSLTO)
{
    isNumeratorOne = iNO;
    isDenominatorSame = iDS;
    isSumLessThanOne = iSLTO;
    int num1, num2, num3, den1, den2, den3, n, d;
    srand((unsigned)time(NULL));
    for (int x = 0; x < 5; x++)
    {
        system("cls");
        if (isNumeratorOne == 1)
        {
            num1 = 1;
            num2 = 1;
        }
        else
        {
            num1 = operand1.numerator();
            num2 = operand2.numerator();
        }
        if (isDenominatorSame == 1)
        {
            den1 = operand1.denominator();
            den2 = den1;
        }
        else
        {
            den1 = operand1.denominator();
            den2 = operand2.denominator();
        }
        if (isSumLessThanOne == 1)
        {
            while (num1 * den2 + num2 * den1 >= den1 * den2)
            {
                num1 = operand1.numerator();
                num2 = operand2.numerator();
            }
        }
        sum.addFraction(num1, den1, num2, den2, num3, den3);
        cout << num1 << "\t" << num2 << "\t" << endl;
        cout << "___" << "  +  " << "___" << "  = ? " << endl;
        cout << den1 << "\t" << den2 << "\t" << endl;
        cout << endl;
        cout << "What is your answer to the problem enter the numerator: ";
        cin >> n; 
        cout << "What is your answer for the denominator: ";
        cin >> d;
        if (n == num3 && d == den3)
        {
            cout << "You are correct! The answer is: " << endl;
            cout << num3 << endl;
            cout << "___" << endl;
            cout << den3 << endl;
            cout << endl;
        }
        else
        {
            cout << "You are wrong! The correct answer is: " << endl;
            cout << num3 << endl;
            cout << "___" << endl;
            cout << den3 << endl;
            cout << endl;
        }
        cout << "Press any key to continue";
        _getch();
    }
}

int main()
{
    Problem p;
    bool iNO, iDS, iSLTO;
    cout << "Choose at least one of the three options:" << endl;
    cout << "Would you like to sum fractions where the numerators are 1? Type 1 for yes or 0 for no ";
    cin >> iNO;
    cout << "Would you like to sum fractions where the denominators are the same? Type 1 for yes on 0 for no ";
    cin >> iDS;
    cout << "Would you like to sum fractions where the answer is less than one? Type 1 for yes or 0 for no ";
    cin >> iSLTO;
    p.askProblem(iNO, iDS, iSLTO);
    return 0;
}
