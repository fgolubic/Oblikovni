#pragma once

#include "GeneralAnimal.hpp"
#include "myfactory.hpp"



class Parrot : public GeneralAnimal
{
public:
	static void* myCreator(std::string const& name);

	Parrot(std::string const& name);

	virtual ~Parrot() = default;

private:
	static int hreg;

};

