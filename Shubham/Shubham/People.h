#pragma once
#include <iostream>
#include <string>

/*
* RAII- Resource acqusition is intialization
*/

class People
{
	std::string m_Name;
	int *m_Age;
public:
	People();
	People(const std::string &name, int age);
	//rule of 3
	People(const People &obj);
	People& operator=(const People&);
	//Move sementics or rule of 5
	People(People&& obj) noexcept;
	static void showa(const People& obj);
	std::string getName() const;
	int getAge() const;
	void showDetails();
	~People();
};

extern People human;