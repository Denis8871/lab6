#pragma once
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

#include <string>
using namespace std;

class Payment
{

	string surname; //прізвище
	string name; //ім'я
	string patronymic; //по-батькові
	double salary; // щоденний оклад
	int yearOfEnployment; // рік прийняття на роботу 
	double percentageOfAllowance = 0.03; // відсоток надбавки
	int incomeTax = 0.13; // прибутковий податок
	int numberOfWorkingDays; // кількість відпрацьованих днів за місяць
	double accruedAmount; // нарахована сума 
	double amountWitheld; // утримана сума
	double finalAmount; // додаткова змінна для запису суми на руки
public:
	MYDLL_API Payment(string s, string n, string p, double sal, int year, int numb); // конструктор з параметрами необхідними для розрахунків
	MYDLL_API Payment(); // конструктор за замовчуванням
	MYDLL_API Payment(string s, string n, string p, double sal, int year, int numb, int accAm, int ammWithh, int finalAm); // конструктор який приймає всі параметри і заповнює усі поля об'єкту
	MYDLL_API void read(); // введеня з клавіатури
	MYDLL_API void display(); //виведення на екран
	MYDLL_API double calculateAccuredAmount(Payment& a); //метод обчислення нарахованої суми. в якості аргументу використовується посилання на об'єкт типу Payment
	MYDLL_API double calculateAmountWitheld(Payment& a); //метод обчислення утриманої суми. в якості аргументу використовується посилання на об'єкт типу Payment
	MYDLL_API double calculateFinalAmount(Payment&); //метод обчислення суми на руки. в якості аргументу використовується посилання на об'єкт типу Payment
	MYDLL_API int calculateExperience(); //метод обчислення стажу працівника
	MYDLL_API bool operator>(Payment& a); // перевантаження оператору порівняння >
	MYDLL_API bool operator<(Payment& a); // перевантаження оператору порівняння <
	MYDLL_API Payment operator=(Payment& a); // перевантаження оператору присвоєння(організація поелементного копіювання)



};
