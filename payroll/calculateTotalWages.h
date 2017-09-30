#include "Employee.h"

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::make_shared;

double calculateTotalWages(vector<shared_ptr<Employee>> &employees)
{
	double totalWages=0;
		for (auto &element:employees)
		{
			totalWages+=element->earnings();
		}
		return totalWages;
}
