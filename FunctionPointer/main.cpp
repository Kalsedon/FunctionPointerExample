#include <iostream>
#include <vector>

template<typename T>
void PrintAnyThing(T& t)
{
	std::cout << t << std::endl;
}

void Print(std::vector<std::string>& vector, void(*func)(std::string&))
{
	for (std::string& value : vector)
		func(value);
}

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