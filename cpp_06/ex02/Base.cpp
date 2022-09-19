#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
	srand(static_cast<unsigned int>(time(0)));
	int num = rand() % 3;
	if (num == 1) {
		std::cout << "Class A has been generated" << std::endl;
		return new A;
	} else if (num == 2) {
		std::cout << "Class B has been generated" << std::endl;
		return new B;
	} else {
		std::cout << "Class C has been generated" << std::endl;
		return new C;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A*" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B*" << std::endl; 
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C*" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& aRef = dynamic_cast<A&>(p);
		(void)aRef;
		std::cout << "A&" << std::endl;
	} catch (std::exception &e) {
		e.what();
	}
	try {
		B& bRef= dynamic_cast<B&>(p);
		(void)bRef;
		std::cout << "B&" << std::endl;
	} catch (std::exception &e) {
		e.what();
	}
	try {
		C& cRef = dynamic_cast<C&>(p);
		(void)cRef;
		std::cout << "C&" << std::endl;
	} catch (std::exception &e) {
		e.what();
	}
}