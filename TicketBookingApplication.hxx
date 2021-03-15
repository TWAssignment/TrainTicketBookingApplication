#include "StationManager.hxx"
#include "TicketVendor.hxx"

using namespace std;

class TicketBookingApplication
{
private:
	TicketVendor* m_ticketVendor;

public:

	// TicketBookingApplication default constructor
	TicketBookingApplication();

	/* Allows user to book a ticket
	* source      [I] : From location
	* destination [I] : To location
	* age         [I] : For rebate on fare
	* isReturn    [I] : Requirement of a return ticket
	*/
	void BookTicket(const string& source, const string& destination, int age, bool isReturn = false);

	/* Initializes all the train stations */
	void InitializeStations();

};
