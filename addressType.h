// ---------------------------------------------------------------------------
// Name: Christelle Mbemba
// Course-Section: CS255-02
// Assignment: Project 8
// Date due: 04/09/2023
// Description:  implementation of an address class with overloaded operators for comparison and output.
// ---------------------------------------------------------------------------
#include <iostream>
using namespace std;

class addressType
{
	private:
		
	    string firstName ;
	    string lastName ;
	    string streetAddress ;
	    string city ;
	    string state;
	    int zip ;	
		
	public:
		addressType() ;
		void setAll(string FName, string LName, string SAddress, string City, string State, int Zip);
		friend ostream& operator<<(ostream& os, const addressType& addr);
		bool operator>(const addressType& other);
	
		bool operator==(const addressType& other) ;
		bool operator!=(const addressType& other) ;
				
};