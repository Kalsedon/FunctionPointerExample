#include <iostream>
#include <vector>

void HelloWorld()
{
	std::cout << "Hello World";
}
int main()
{
	auto function = HelloWorld;
	//now the type of function is -- void(*)() like void(*function)()
	void(*newfunction)() = HelloWorld;
	newfunction();
	std::cin.get();
}