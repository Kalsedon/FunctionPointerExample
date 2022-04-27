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

	std::vector<std::string> strings;
	strings.push_back("S");
	strings.push_back("e");
	strings.push_back("r");
	strings.push_back("h");
	strings.push_back("a");
	strings.push_back("t");
	
	auto print = [](std::string& s) -> void // return type can be specified like that
	{
		std::cout << s << std::endl;
	};

	auto newfunction = Print;
	newfunction(strings, PrintAnyThing); // alternatively Print(strings, newfunction), it does the same thing or -->
	Print(strings, [](std::string& s) {std::cout << s << std::endl; }); // passing a lambda (throwaway function)
	Print(strings, print);
	std::cin.get();
}