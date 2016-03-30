/*
 * User.h
 *
 *  Created on: Mar 30, 2016
 *      Author: Christopher
 */

#ifndef USER_H_
#define USER_H_

class User {
private:
	string name;
	string password;
	string nationality;
	int age;
	long id;
	Flight* flights;
public:
	User() {
	}
	virtual ~User();
};

#endif /* USER_H_ */

