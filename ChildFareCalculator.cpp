#include "ChildFareCalculator.hxx"

/* ------------------------------------------------------------------------------------------------------------- */
void ChildFareCalculator::CalculateFare(Ticket* ticket)
{
	double fare = ticket->GetFare();
	ticket->SetFare(fare * 0.75);
}
