#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main() {
	struct Data data;
	data.char_ = 'F';
	data.int_ = 42;
	data.str_ = "\t42 - the answer to the main question of life,\n\
	the universe and all that.42 - the answer to the main\n\
	question of life, the universe and all that.";

	Data *ptr = &data;
	std::cout << "before: " << ptr << "\n" << data;
	
	uintptr_t ser = serialize(ptr);
	Data *newData = deserialize(ser);

	std::cout << "after: " << newData << "\n" << *newData;
}