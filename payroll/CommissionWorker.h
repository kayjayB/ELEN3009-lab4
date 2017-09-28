#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h"

class CommissionWorker: public Employee
{
public:
	CommissionWorker(const string& first_name, const string& surname, double base_salary, double commission, 
	int number_of_items);
	~CommissionWorker();
	
	virtual double earnings() const override;
	virtual void print() const override;	
	void baseSalary(double base_salary);
	void commissionPerItem(double commission);
	void itemsSold(int number_of_items);
	
private:
double _base_salary;
double _commission;
int _number_of_items;
};

#endif // COMMISSION_H
