#pragma once
#include "Ticket.hxx"


class IFareCalculator
{
public:
	// Calculate Fare Base Implementation
	virtual void CalculateFare(Ticket* ticket) = 0;
};