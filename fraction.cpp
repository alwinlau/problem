// week 5 part 2
// Alwin Lau
// fraction class for problem

#include<iostream>
#include<stdio.h> // need for NULL
#include<stdlib.h> // need for rand
#include<ctime> // need for time
#include<conio.h> // need for _getch
using namespace std;

class Fraction
{
private:
    int num1, num2, num3, den1, den2, den3, n ,d;

public:
    void addFraction(int, int, int, int, int&, int&);
    int gcd(int, int);
    void lowest(int&, int&);
    int numerator();
    int denominator();
};

//Function to add two fractions 
void Fraction::addFraction(int num1, int den1, int num2, int den2, int& num3, int& den3)
{
    // Finding gcd of den1 and den2 
    den3 = gcd(den1, den2);

    // Denominator of final fraction obtained 
    // finding LCM of den1 and den2 
    // LCM * GCD = a * b  
    den3 = (den1 * den2) / den3;

    // Changing the fractions to have same denominator 
    // Numerator of the final fraction obtained 
    num3 = (num1) * (den3 / den1) + (num2) * (den3 / den2);

    // Calling function to convert final fraction 
    // into it's simplest form 
    lowest(den3, num3);
}

// Function to return gcd of a and b 
int Fraction::gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void Fraction::lowest(int& den3, int& num3)
{
    // Finding gcd of both terms 
    int common_factor = gcd(num3, den3);

    // Converting both terms into simpler  
    // terms by dividing them by common factor  
    den3 = den3 / common_factor;
    num3 = num3 / common_factor;
}

int Fraction::numerator()
{
    return rand() % 100 + 1;
}

int Fraction::denominator()
{
    return rand() % 100 + 1;
}

// tests the class
/* int main()
{
    Fraction sum, frac1, frac2, answer;
    int num1, num2, num3, den1, den2, den3, answerN, answerD;
    srand((unsigned)time(NULL));
    for (int x = 0; x < 5; x++)
    {
        system("cls");
        num1 = frac1.numerator();
        num2 = frac2.numerator();
        den1 = frac1.denominator();
        den2 = frac2.denominator();
        sum.addFraction(num1, den1, num2, den2, num3, den3);
        cout << num1 << "\t" << num2 << "\t" << endl;
        cout << "___" << "  +  " << "___" << "  = ? " << endl;
        cout << den1 << "\t" << den2 << "\t" << endl;
        cout << endl;
        cout << "What is your answer to the problem enter the numerator: ";
        answerN();
        cout << "What is your answer for the denominator: ";
        answerD();
        if (answerN() == num3 && answerD() == den3)
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
} */
