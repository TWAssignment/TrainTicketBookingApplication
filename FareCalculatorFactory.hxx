#include "IFareCalculator.hxx"

class FareCalculatorFactory
{
public:
	
	/* Creates and returns FareCalculator object to check for additional discounts
	*/
	static IFareCalculator* GetFareCalculatorObject(int age);
};
