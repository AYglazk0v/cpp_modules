#include "Base.hpp"

int main() {
	Base *ptr;

	ptr = generate();
	identify(ptr);
	Base& ref = *ptr;
	identify(ref);

	delete ptr;
}