#pragma once

#include <string>
#include <vector>
#include <map>

class myfactory
{
public:
	typedef void* (*pFunCreator)(const std::string&);
	typedef std::map<std::string, pFunCreator> MyMap;
public:
	static myfactory &instance();
public:
	int registerCreator(const std::string &id, pFunCreator pfn);
public:
	void *create(const std::string &id, const std::string &arg);
	std::vector<std::string> getIds();
private:
	myfactory() = default;
	~myfactory() = default;
	myfactory(const myfactory&);
	MyMap creators_;
};


inline myfactory& myfactory::instance()
{
	static myfactory factory = myfactory();

	return factory;
}

inline int myfactory::registerCreator(std::string const& id, pFunCreator creator)
{
	creators_[id] = creator;
	return creators_.size();
}


inline void  *myfactory::create(const std::string &id, const std::string &arg) 
{
	return creators_.at(id)(arg);
}


inline std::vector<std::string> myfactory::getIds() 
{
	std::vector<std::string> ids = std::vector<std::string>();

	for (auto const&  id : creators_) {

		ids.push_back(id.first);
	}
	return ids;
}


