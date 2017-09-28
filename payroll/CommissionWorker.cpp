#include "CommissionWorker.h"

CommissionWorker::CommissionWorker(const string& first_name, const string& surname, double base_salary, 
double commission, int number_of_items): 
Employee(first_name, surname),  // call base-class constructor
_base_salary(base_salary),
_commission(commission),
_number_of_items(number_of_items)
{
}

CommissionWorker::~CommissionWorker()
{
}

void CommissionWorker::baseSalary(double base_salary)
{
	_base_salary=base_salary;
}
 
void CommissionWorker::commissionPerItem(double commission)
{
	_commission=commission;
}

void CommissionWorker::itemsSold(int number_of_items)
{
	_number_of_items=number_of_items;
}

double CommissionWorker::earnings() const
{
		return _base_salary + _commission*_number_of_items;
}

void CommissionWorker::print() const
{
	cout << "Commision worker: ";
	
   Employee::print();
}	