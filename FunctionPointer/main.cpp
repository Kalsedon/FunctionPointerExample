#include <iostream>
#include <vector>

struct Vector2
{
	float x, y;
};
struct Vector4
{
	float x, y, w, z;
	const Vector2& getVec2A()
	{
		return *(Vector2*)&x;
	}
	const Vector2& getVec2B()
	{
		return *(Vector2*)&y;
	}
};
void PrintVector2(const Vector2& vec, void(*func)(float))
{
	func(vec.x);
	func(vec.y);
}
template<typename T>
void PrintAnyThing(T& t)
{
	std::cout << t << std::endl;
}

void PrintSTDvector(std::vector<std::string>& vector, void(*func)(std::string&))
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

	auto newfunction = PrintSTDvector;
	newfunction(strings, PrintAnyThing); // alternatively Print(strings, newfunction), it does the same thing or -->
	PrintSTDvector(strings, [](std::string& s) {std::cout << s << std::endl; }); // passing a lambda (throwaway function)
	PrintSTDvector(strings, print);

	Vector4 newVec4{ 2.0f, 3.0f, 4.0f, 5.0f };
	//Print()
	std::cin.get();
}