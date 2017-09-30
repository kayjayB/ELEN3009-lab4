#include "Employee.h"
#include "Fixed.h"
#include "Hourly.h"
#include "CommissionWorker.h"
#include "calculateTotalWages.h"
	
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("The total wages can be calculated for a vector of fixed employees")
{
	vector<shared_ptr<Employee>> employees;
	shared_ptr<Employee> employee1_ptr = make_shared<FixedRateWorker>("Ted", "Ramgasamy", 905.00);
	shared_ptr<Employee> employee2_ptr = make_shared<FixedRateWorker>("Louisa", "Mahlungu", 12.00);
	shared_ptr<Employee> employee3_ptr = make_shared<FixedRateWorker>("Kayla", "Butkow", 120.00);
	//shared_ptr<Employee> employee3_ptr = make_shared<CommissionWorker>("Kayla", "Butkow", 120.00, 11.00, 432);
	employees.push_back(employee1_ptr);
	employees.push_back(employee2_ptr);
	employees.push_back(employee3_ptr);
	
	double wages= calculateTotalWages(employees);
	
	double expected = 905.00+12.00+120.00;
	
	CHECK(wages==expected);
}

TEST_CASE("The total wages can be calculated for a vector of hourly employees")
{
	vector<shared_ptr<Employee>> employees;
	shared_ptr<Employee> employee1_ptr = make_shared<HourlyWorker>("Ted", "Ramgasamy", 905.00, 46);
	shared_ptr<Employee> employee2_ptr = make_shared<HourlyWorker>("Louisa", "Mahlungu", 12.00, 4);
	shared_ptr<Employee> employee3_ptr = make_shared<HourlyWorker>("Kayla", "Butkow", 120.00, 15);
	//shared_ptr<Employee> employee3_ptr = make_shared<CommissionWorker>("Kayla", "Butkow", 120.00, 11.00, 432);
	employees.push_back(employee1_ptr);
	employees.push_back(employee2_ptr);
	employees.push_back(employee3_ptr);
	
	double wages= calculateTotalWages(employees);
	
	double expected = (40 * 905.00 + (46 - 40) * 905.00 * 1.5)+12.00 * 4 + 120.00*15;
	
	CHECK(wages==expected);
}

TEST_CASE("The total wages can be calculated for a vector of commission employees")
{
	vector<shared_ptr<Employee>> employees;
	shared_ptr<Employee> employee1_ptr = make_shared<CommissionWorker>("Ted", "Ramgasamy", 905.00, 1.00, 46);
	shared_ptr<Employee> employee2_ptr = make_shared<CommissionWorker>("Louisa", "Mahlungu", 300.00, 12.00, 4);
	shared_ptr<Employee> employee3_ptr = make_shared<CommissionWorker>("Kayla", "Butkow", 120.00, 11.00, 432);
	employees.push_back(employee1_ptr);
	employees.push_back(employee2_ptr);
	employees.push_back(employee3_ptr);
	
	double wages= calculateTotalWages(employees);
	
	double expected = (905.00 + 1.00*46)+(300.00+12.00*4)+(120.00+11.00*432);
	
	CHECK(wages==expected);
}

TEST_CASE("The total wages can be calculated for a vector of mixed employees")
{
	vector<shared_ptr<Employee>> employees;
	shared_ptr<Employee> employee2_ptr = make_shared<FixedRateWorker>("Louisa", "Mahlungu", 120.00);
	shared_ptr<Employee> employee1_ptr = make_shared<HourlyWorker>("Ted", "Ramgasamy", 905.00, 46);
	shared_ptr<Employee> employee3_ptr = make_shared<CommissionWorker>("Kayla", "Butkow", 120.00, 11.00, 432);
	employees.push_back(employee1_ptr);
	employees.push_back(employee2_ptr);
	employees.push_back(employee3_ptr);
	
	double wages= calculateTotalWages(employees);
	
	double expected = 120+(40 * 905.00 + (46 - 40) * 905.00 * 1.5) +(120.00+11.00*432);
	
	CHECK(wages==expected);
}