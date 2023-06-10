#include <iostream>
#include "InquiryRefund.h" // InquiryRefund class definition

// InquiryRefund constructor initializes data members
InquiryRefund::InquiryRefund( ReservationDatabase &theReservationDatabase,
                                    FlightSchedule &theFlightSchedule )
   : reservationDatabase( theReservationDatabase ),
     flightSchedule( theFlightSchedule ),
     id( "" )
{
} // end InquiryRefund constructor

bool InquiryRefund::bookingInquiry( string id )
{
   if( reservationDatabase.empty() )
   {
      cout << "\nNo reservations!\n";
      return false;
   }

   if( !reservationDatabase.existReservation( id ) )
   {
      cout << "\nNo reservations!\n";
      return false;
   }

   reservationDatabase.display( id );

   return true;
}

void InquiryRefund::refundApplication( string id )
{
   if( !bookingInquiry( id ) )
      return;

   int choice;
   cout << "\nEnter your choice: ";
   cin >> choice;

   if( choice <= 0 )
      cout << "\nOut of range!\n";
   else
      reservationDatabase.cancelReservation( id, choice );
}