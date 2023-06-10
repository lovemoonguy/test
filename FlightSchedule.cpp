// FlightSchedule.cpp
// Member-function definitions for class FlightSchedule.
#include <iostream>
#include <fstream>
#include "FlightSchedule.h" // FlightSchedule class definition

// FlightSchedule default constructor loads flight schedule from the file Flight Schedule.dat
FlightSchedule::FlightSchedule()
{
   loadFlightSchedule();
}

FlightSchedule::~FlightSchedule()
{
}

int FlightSchedule::getDepartureAirport( string flightNo )
{
   vector< Flight >::iterator it = getFlight( flightNo );

   if( it != flights.end() )
      return it->getDepartureAirport();

   return 0;
}

int FlightSchedule::getArrivalAirport( string flightNo )
{
   vector< Flight >::iterator it = getFlight( flightNo );

   if( it != flights.end() )
      return it->getArrivalAirport();

   return 0;
}

string FlightSchedule::getDepartureTime( string flightNo )
{
   vector< Flight >::iterator it = getFlight( flightNo );

   return it->getDepartureTime();
}

string FlightSchedule::getArrivalTime( string flightNo )
{
   vector< Flight >::iterator it = getFlight( flightNo );

   return it->getArrivalTime();
}

bool FlightSchedule::exist( string flightNo, int departureAirport, int arrivalAirport )
{
    for (vector< Flight >::iterator it = flights.begin(); it != flights.end(); ++it)
    {
        if (flightNo == it->getFlightNo() && departureAirport == it->getDepartureAirport()
            && arrivalAirport == it->getArrivalAirport())
            return true;
    }
    return false;

}

void FlightSchedule::display( int departureAirport, int arrivalAirport, string date )
{
   cout << airportName[ departureAirport ] << " to " << airportName[ arrivalAirport ]
      << " / Depart date: " << date << ".\n\n";
   cout << "Flight   Departure   Arrival   Fare\n";

   for( vector< Flight >::iterator it = flights.begin(); it != flights.end(); ++it )
      if( it->getDepartureAirport() == departureAirport &&
          it->getArrivalAirport() == arrivalAirport )
         it->display( date );
}

vector< Flight >::iterator FlightSchedule::getFlight( string flightNo )
{
	for (vector< Flight >::iterator it = flights.begin(); it != flights.end(); ++it)
		if (it->getFlightNo() == flightNo)
			return it;
		return flights.end();
}

void FlightSchedule::loadFlightSchedule()
{
	ifstream  input("Flight Schedule.dat", ios::binary);
	if (!input)
	{
		cerr << "File could not be opened.(loadFlightSchedules)" << endl;
		system("pause");
		exit(1);
	}
	input.seekg(0, ios::end);
	int numFlights = input.tellg() / sizeof(flights);
	input.seekg(0, ios::beg);
	Flight flight;
	for (int i = 0; i <= numFlights; ++i)
	{
		input.read(reinterpret_cast<char*>(&flight), sizeof(flight));
		flights.push_back(flight);
	}
	input.close();
}