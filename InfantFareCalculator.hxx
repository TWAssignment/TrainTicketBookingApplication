#include "IFareCalculator.hxx"

class InfantFareCalculator : public IFareCalculator
{
public:
	// Infant Fare calculation implementation
	void CalculateFare(Ticket* ticket) override;
};