#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.value = 42;
	data.name = "Test Object";
	data.price = 19.99;

	std::cout << "Original Data object:" << std::endl;
	std::cout << "Address: " << &data << std::endl;
	std::cout << "Value: " << data.value << std::endl;
	std::cout << "Name: " << data.name << std::endl;
	std::cout << "Price: " << data.price << std::endl;
	std::cout << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized value: " << serialized << std::endl;
	std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data object:" << std::endl;
	std::cout << "Address: " << deserialized << std::endl;
	std::cout << "Value: " << deserialized->value << std::endl;
	std::cout << "Name: " << deserialized->name << std::endl;
	std::cout << "Price: " << deserialized->price << std::endl;
	std::cout << std::endl;

	if (&data == deserialized)
	{
		std::cout << "SUCCESS: Original pointer and deserialized pointer are equal" << std::endl;
	}
	else
	{
		std::cout << "FAILURE: Pointers are not equal" << std::endl;
	}

	return 0;
}
