#include "Parrot.hpp"

int Parrot::hreg = myfactory::instance().registerCreator("Parrot", myCreator);

void* Parrot::myCreator(std::string const& name)
{
	return new Parrot(name);
}

Parrot::Parrot(std::string const& name)
	: GeneralAnimal(name, "Sto mu gromova!", "brazilske orahe")
{
	
}
