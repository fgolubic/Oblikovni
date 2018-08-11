#include<iostream>

typedef int (*funptr)(void);

class B {
public:
	virtual int prva() = 0;
	virtual int druga() = 0;
};

class D : public B {
public:
	virtual int prva() { return 0; }
	virtual int druga() { return 42; }
};

void funkcija(B* pb) {
	funptr* vtable = (funptr*)((funptr*)pb)[0];
	std::cout << vtable[0]() << std::endl << vtable[1]() << std::endl;

}

int main() {
	B* p = new D;
	funkcija(p);
	system("pause");
}