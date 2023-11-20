#include <iostream>
#include "PaymentCalc.h"
using namespace std;

Payment::Payment(string s, string n, string p, double sal, int year, int numb) //ініціалізація

{

    surname = s;
    name = n;
    patronymic = p;
    salary = sal;
    yearOfEnployment = year;
    numberOfWorkingDays = numb;

}

Payment::Payment()  // конструктор за замовчуванням
{
    name = "Name";
    surname = "Surname";
    patronymic = "Patronymic";
    salary = 500;
    numberOfWorkingDays = 20;
}

Payment::Payment(string s, string n, string p, double sal, int year, int numb, int accAm, int amWithh, int finalAm)  // конструктор який приймає всі параметри і заповнює усі поля об'єкту
{
    surname = s;
    name = n;
    patronymic = p;
    salary = sal;
    yearOfEnployment = year;
    numberOfWorkingDays = numb;
    accruedAmount = accAm;
    amountWitheld = amWithh;
    finalAmount = finalAm;
}

void Payment::read() //введення з клавіатури 
{
    cout << "Enter name of employee: ";
    cin >> name;
    cout << "Enter surname of employee: ";
    cin >> surname;
    cout << "Enter patronymic of employee: ";
    cin >> patronymic;
    cout << "Enter salary of employee: ";
    cin >> salary;
    cout << "Enter year of employment of employee: ";
    cin >> yearOfEnployment;
    cout << "Enter number of working days of employee: ";
    cin >> numberOfWorkingDays;


}

void Payment::display() // виведення результату обчислень на екран 
{
    cout << "Person: " << this->name << " " << this->surname << " " << this->patronymic << " has " << this->accruedAmount << " and amount witheld: " << this->amountWitheld << endl;
    cout << "In total he/she gots: " << this->finalAmount << endl;
}

double Payment::calculateAccuredAmount(Payment& a) // обчислення нарахованої суми. результат записується у поле accuredAmount
{
    return a.accruedAmount = a.numberOfWorkingDays * a.salary + (a.percentageOfAllowance * a.numberOfWorkingDays * a.salary);

}

double Payment::calculateAmountWitheld(Payment& a) // обчислення утриманої суми. результат записується у поле amountWitheld
{

    return a.amountWitheld = a.accruedAmount * 0.01 + a.accruedAmount * a.incomeTax;

}

double Payment::calculateFinalAmount(Payment& a) // обчислення суми на руки. результат записується у поле finalAmount
{

    return a.finalAmount = a.accruedAmount - a.amountWitheld;

}
int Payment::calculateExperience() //обчислення стажу роботи працівник
{
    int res;
    res = 2023 - this->yearOfEnployment;
    return res;
}
bool Payment::operator>(Payment& a) // перевантаження оператору порівняння > (метод порівнює значення полів finalAmount)
{
    if (this->finalAmount > a.finalAmount) {
        return true;
    }
    else {
        return false;
    }
}

bool Payment::operator<(Payment& a) // перевантаження оператору порівняння < (метод порівнює значення полів finalAmount)
{
    if (this->finalAmount < a.finalAmount) {
        return true;
    }
    else {
        return false;
    }
}

Payment Payment::operator=(Payment& a) // перевантаження оператору присвоєння(організація поелементного копіювання)
{
    this->name = a.name;
    this->surname = a.surname;
    this->patronymic = a.patronymic;
    this->salary = a.salary;
    this->yearOfEnployment = a.yearOfEnployment;
    this->percentageOfAllowance = a.percentageOfAllowance;
    this->incomeTax = incomeTax;
    this->numberOfWorkingDays = a.numberOfWorkingDays;
    this->accruedAmount = a.accruedAmount;
    this->amountWitheld = a.amountWitheld;
    this->finalAmount = a.finalAmount;
    return *this;

}
