

#include <iostream>
using namespace std;

#include "addressType.h"


addressType::addressType() //constructor for the addressType class
{
	//initialize member variables
    firstName = " ";
    lastName = " ";
    streetAddress = " ";
    city = " ";
    state = " ";
    zip =0;
}

void addressType::setAll(string FName, string LName, string SAddress, string City, string State, int Zip)
{
	//set member variables to provided values
    firstName = FName;
    lastName = LName;
    streetAddress = SAddress;
    city = City;
    state = State;
    zip = Zip;
}

ostream& operator<<(ostream& os, const addressType& addr) 
{
	//print member variables in a formatted way
    os << addr.firstName << endl;
	os << addr.lastName << endl;
    os << addr.streetAddress << endl;
    os << addr.state << endl;
    os << addr.city << endl;
    os << addr.zip <<endl;
    return os;//return output stream object
}

bool addressType::operator>(const addressType& other) 
{
    if (lastName > other.lastName)
        return true;
       	//if last names are equal, compare first names 
    else if (lastName == other.lastName && firstName > other.firstName)
		 return true;
    else
        return false;
}

bool addressType::operator==(const addressType& other) 
{
	//check if all member variables are equal
    return (firstName == other.firstName) && (lastName == other.lastName) && 
           (streetAddress == other.streetAddress) && (city == other.city) &&
           (state == other.state) && (zip == other.zip);
}

bool addressType::operator!=(const addressType& other) 
{
	 //check if any member variable is not equal
    return (firstName != other.firstName) || (lastName != other.lastName) || (streetAddress != other.streetAddress)
           || (city != other.city) || (state != other.state) || (zip != other.zip);
}
