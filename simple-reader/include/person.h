/*
 * person.h
 *
 *  Created on: 2015年9月30日
 *      Author: laolang
 */

#ifndef INCLUDE_PERSON_H_
#define INCLUDE_PERSON_H_

#include<string>

using std::string;

class Person {
public:

	Person();
	Person(string name, string phone, string email);
	~Person();

	string toString();

	const string& getEmail() const;
	void setEmail(const string& email);
	const string& getName() const;
	void setName(const string& name);
	const string& getPhone() const;
	void setPhone(const string& phone);

private:
	string name;
	string phone;
	string email;
};

#endif /* INCLUDE_PERSON_H_ */
