#include <iostream>

#include "TicketVendor.hxx"

#include "FareCalculatorFactory.hxx"
#include "StationManager.hxx"

/* ------------------------------------------------------------------------------------------------------------- */
Ticket* TicketVendor::CreateTicket(const string& source, const string& destination, bool isReturn)
{
    Ticket* ticket = new Ticket(source, destination, isReturn);
    return ticket;
}

/* ------------------------------------------------------------------------------------------------------------- */
void TicketVendor::CalculateFare(Ticket* ticket, int age)
{
    IFareCalculator* fareCalculatorObj = FareCalculatorFactory::GetFareCalculatorObject(age);
    fareCalculatorObj->CalculateFare(ticket);
}

/* ------------------------------------------------------------------------------------------------------------- */
void TicketVendor::BookTicket(const string& source, const string& destination, int age, bool isReturn)
{
    if (StationManager::GetInstance().IsRouteAvailable(source, destination))
    {
        Ticket* ticket = CreateTicket(source, destination, isReturn);
        CalculateFare(ticket, age);
        ticket->PrintTicket();
    }
    else
        cout << "No route available from " << source << " to " << destination << endl;
}
