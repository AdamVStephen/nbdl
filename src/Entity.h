#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "ValidatorInt.h"
#include "ValidatorIntUnsigned.h"
#include "ValidatorString.h"
#include "BackEnd.h"

#include<iostream>
class Entity
{
	public:

	typedef std::unordered_map<std::string, std::string> ValueMap;
	typedef std::unordered_map<std::string, std::vector<std::string>> ErrorList;

	Entity(/*Builder &builder,*/ std::unique_ptr<BackEnd> backEnd) :
		//builder(builder),
		backEnd(std::move(backEnd)) {}
	Entity(Entity&&); //move constructor
	virtual ~Entity() { }

	int getId() { return id; }
	bool save();

	inline void set(const std::string name, const std::string value) { changedValues[name] = value; }
	const std::string get(const std::string &name);
	const ErrorList getErrors() { return errors; }

	protected:

	friend class Validator;

	void addError(const std::string &name, const std::string &error);

	inline ValidatorIntUnsigned &validateIntUnsigned(const std::string name) { return validate<ValidatorIntUnsigned>(name); }
	inline ValidatorInt &validateInt(const std::string name) { return validate<ValidatorInt>(name); }
	inline ValidatorString &validateString(const std::string name) { return validate<ValidatorString>(name); }

	virtual void validate() = 0;

	//Builder &builder;
	std::unique_ptr<BackEnd> backEnd;

	private:

	void flushValidatedValues();

	ValueMap values;
	ValueMap changedValues;
	ValueMap validatedValues;
	Validator *currentValidator;
	std::vector<std::unique_ptr<Validator> > validators;
	ErrorList errors;
	//std::unordered_map<std::string, std::vector<std::string>> errors;
	bool has_errors;
	int id;

	template<class V>
	V &validate(const std::string &name)
	{
		V *v = new V(*this, name);
		validators.push_back(std::unique_ptr<Validator>(v));
		//return reference for idiom
		return *v;
	}

};

#endif

/*
client.createContact()
	.setName("blah")
	.setEmail("blah@bah.com")
	.save();

client.getContact(5)
	.setName("blah")
	.setEmail("blah@bah.com")
	.save();

Contact Client::createContact()
{
	Contact contact = Contact();
	contact.setClientId(getId());
	return contact;
}

bool Contact::validate()
{
	validateEmail("Email");
	validateString("NameFirst")
		.required()
		.matches("^[A-Za-z'\\-]*$")
		.max(50)
		.min(2)
		;
	validatePhoneNumber("Phone");
	validateIntUnsigned("ClientId")
		.required()
		.min(1)
		;
	validateIntUnsigned("Age")
		.min(18)
		.max(150)
		;
	normalize();
}
*/