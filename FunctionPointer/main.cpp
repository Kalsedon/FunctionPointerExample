#include <iostream>
#include <vector>

struct Vector2
{
	float x, y;
};
struct Vector4
{
	union 
	{
		struct 
		{
			float x, y, w, z;
		};
		struct // vec1 is sharing same memory with a and b, vec2 ->> w, z
		{	   // this is an easier method for getting Vector2 type out of Vector4
			Vector2 vec1, vec2;
		};
	};
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
	PrintVector2(newVec4.vec1, [](float f) { std::cout << f; });
	PrintVector2(newVec4.vec2, [](float f) { std::cout << f; });
	std::cin.get();
}