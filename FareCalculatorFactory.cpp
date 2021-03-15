#include "FareCalculatorFactory.hxx"

#include "AdultFareCalculator.hxx"
#include "ChildFareCalculator.hxx"
#include "InfantFareCalculator.hxx"

/* ------------------------------------------------------------------------------------------------------------- */
IFareCalculator* FareCalculatorFactory::GetFareCalculatorObject(int age)
{
	IFareCalculator* fareCalculatorObj = nullptr;
	if (age < 3)
		fareCalculatorObj = new InfantFareCalculator();
	else if (age < 10)
		fareCalculatorObj = new ChildFareCalculator();
	else
		fareCalculatorObj = new AdultFareCalculator();
	return fareCalculatorObj;
}
