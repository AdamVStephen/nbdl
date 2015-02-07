#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <EntityTraits.hpp>
#include "Address.h"
#include "Food.h"

struct Account
{
	std::string nameFirst;
	std::string nameLast;
	std::string phoneNumber;
	unsigned int age;
	Address address;
	Food food;

};
namespace nbdl {
	NBDL_ENTITY(
		Account,
			nameFirst,
			nameLast,
			phoneNumber,
			age,
			address,
			food);
	NBDL_MEMBER_MINLENGTH(&Account::nameFirst, 2);
	NBDL_MEMBER_MINLENGTH(&Account::nameLast, 2);
	NBDL_MEMBER_MATCH(&Account::phoneNumber, "^[0-9]{10}$");
	NBDL_MEMBER_DEFAULT(&Account::phoneNumber, "7608675309");
	NBDL_MEMBER_MAXLENGTH(&Account::phoneNumber, 5000);
}//nbdl

#endif
