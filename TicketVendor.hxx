#include "Ticket.hxx"

class TicketVendor
{
private:

	/* Creates a ticket for the given source and destination.
	* Also, computes the fare.
	* source      [I] : From location
	* destination [I] : To location
	* isReturn    [I] : Requirement of a return ticket
	*/
	Ticket* CreateTicket(const string& source, const string& destination, bool isReturn);

	/* Calculates the basic for all the users.
	*/
	void CalculateFare(Ticket* ticket, int age);

public:

	/* Allows user to book a ticket
	* source      [I] : From location
	* destination [I] : To location
	* age         [I] : For rebate on fare
	* isReturn    [I] : Requirement of a return ticket
	*/
	void BookTicket(const string& source, const string& destination, int age, bool isReturn);

};
