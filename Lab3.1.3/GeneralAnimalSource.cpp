#include "GeneralAnimal.hpp"
#include <iostream>


char const* GeneralAnimal::name() 
{
	return name_;
}

char const* GeneralAnimal::greet() 
{
	return greet_;
}

char const* GeneralAnimal::menu() 
{
	return menu_;
}

GeneralAnimal::GeneralAnimal(std::string const & name, std::string const & greet, std::string const & menu):Animal()
{
	
	name_ = name.c_str();
	greet_ = greet.c_str();
	menu_ = menu.c_str();

	
}

