#pragma once

#include "Animal.hpp"
#include <string>


class GeneralAnimal :public Animal
{
public:

	virtual char const* name()  override;
	virtual char const* greet() override;
	virtual char const* menu()  override;

	virtual ~GeneralAnimal() = default;

protected:
	GeneralAnimal(std::string const& name, std::string const& greet, std::string const& menu);

private:
	char const*  name_;
	char const* greet_;
	char const* menu_;


};

