#include "Tiger.hpp"

int Tiger::hreg = myfactory::instance().registerCreator("Tiger", myCreator);

void* Tiger::myCreator(std::string const& name)
{
	return new Tiger(name);
}

Tiger::Tiger(std::string const& name)
	: GeneralAnimal(name, "Mijau!", "mlako mlijeko")
{

}
