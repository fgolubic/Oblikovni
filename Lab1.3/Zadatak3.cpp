#include<iostream>

class CoolClass {
public:
	virtual void set(int x) { x_ = x; };
	virtual int get() { return x_; };
private:
	int x_;
};
class PlainOldClass {
public:
	void set(int x) { x_ = x; };
	int get() { return x_; };
private:
	int x_;
};

int main(void)
{
	std::cout << sizeof(CoolClass) << std::endl << sizeof(PlainOldClass)<<std::endl;


	system("pause");

	return 0;
}