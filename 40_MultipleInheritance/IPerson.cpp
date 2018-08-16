#include "Cperson.h"
#include "IPerson.h"

std::shared_ptr<IPerson> IPerson::makePerson(DatabaseID personIdentifier, std::string name)
{
	return std::shared_ptr<IPerson>(new CPerson(personIdentifier, name));
}

