#pragma once
#include "GeneralAnimal.hpp"
#include "myfactory.hpp"



class Tiger : public GeneralAnimal
{
public:
	static void* myCreator(std::string const& name);

	Tiger(std::string const& name);

	virtual ~Tiger() = default;

private:
	static int hreg;

};

