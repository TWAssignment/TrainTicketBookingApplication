# TrainTicketBookingApplication
ThoughtWorks Developer Assignment

## UML Diagram
![Class Diagram](https://github.com/TWAssignment/TrainTicketBookingApplication/blob/main/TWTraingTicketAppUML.jpg)

## Design
- TicketBookingApplication
  - Provides abstract interface for the user.
- StationManager
  - Singleton class to store information about the stations.
- Ticket
  - Responsible for calculating info like basic fare, distance between source and destination, number of stops etc.
- TicketVendor
  - Responsible to create a new ticket and calculate fare using the strategy pattern.
- FareCalculatorFactory
  - Factory class which will instantiate objects based upon the age criteria
- IFareCalculator
  - Base class for strategy pattern responsible to calculate fare
  - Contains CalculateFare pure virtual method
  - InfantFareCalculator
    - Calculates the fare for infants upto the age of 3. Total exemption on fare
  - ChildFareCalculator
    - Calculates the fare for child upto the age of 10. Exemption of 25% of basic fare i.e. 0.75 * basic fare
  - AdultFareCalculator
    - Calculates the fare for adults. No exemption.
- Test.cpp
  - Unit testing file
    - StationManagerSuite
      - Test cases related to singleton station manager object
    - TicketSuite
      - Test case related to ticket creation and calculation of basic info
    - FareCalculatorSuite
      - Test cases related to fare calculation depending on the age criteria
