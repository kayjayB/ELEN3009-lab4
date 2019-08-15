#include "CommissionWorker.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("A commission worker can be created and initialised")
{
		//CommissionWorker worker(Kayla-Jade, Butkow, 500.00, 50.00, 12);
		shared_ptr <CommissionWorker> comPtr = make_shared<CommissionWorker>("Kayla-Jade", "Butkow", 500.00, 50.00, 12);
		
		CHECK(comPtr->first_name()== "Kayla-Jade");
		CHECK(comPtr->surname()== "Butkow");
}

TEST_CASE("A commission worker's base salary can be set")
{
		shared_ptr <CommissionWorker> comPtr = make_shared<CommissionWorker>("Kayla-Jade", "Butkow", 500.00, 50.00, 12);
		
		comPtr->baseSalary(10000.00);
		
		CHECK(comPtr->earnings() == 10600.00);
}

TEST_CASE("A commission worker's commission per item sold can be set")
{
		shared_ptr <CommissionWorker> comPtr = make_shared<CommissionWorker>("Kayla-Jade", "Butkow", 500.00, 50.00, 12);
		
		comPtr->commissionPerItem(20.00);
		
		CHECK(comPtr->earnings() == 740.00);
}

TEST_CASE("A commission worker's total number of items sold per week can be set")
{
		shared_ptr <CommissionWorker> comPtr = make_shared<CommissionWorker>("Kayla-Jade", "Butkow", 500.00, 50.00, 12);
		
		comPtr->itemsSold(200);
		
		CHECK(comPtr->earnings() == 10500.00);
}

