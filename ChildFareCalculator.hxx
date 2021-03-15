#include "IFareCalculator.hxx"

class ChildFareCalculator : public IFareCalculator
{
public:
	// Child Fare calculation implementation
	void CalculateFare(Ticket* ticket) override;
};