#include "IFareCalculator.hxx"

class AdultFareCalculator : public IFareCalculator
{
public:
	// Adult Fare calculation implementation
	void CalculateFare(Ticket* ticket) override;
};