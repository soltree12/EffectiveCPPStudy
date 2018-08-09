#include "RealPerson.h"

std::string RealPerson::name() const
{
	return theName;
}
std::string RealPerson::birthDate() const
{
	return theBirthDate.getDate();
}
std::string RealPerson::address() const
{
	return theAddress.getAddress();
}
