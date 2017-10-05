#include <regex>
#include <iostream>

#include <esolv/esolv.hpp>
#include <esolv/symbol/Symbol.hpp> // esolv/symbol/Symbol.hpp.in

int main()
{
	auto s = std::make_shared<esolv::Storage>();

	auto a = s->symbol("a");
	auto b = s->symbol("b");
	auto c = s->symbol("c");
	auto d = s->symbol("d");

	esolv::symbol::S_Operand e = a + b + c + d;

	std::cout << e->str() << std::endl;

	e->simplify_sub();

	std::cout << e->str() << std::endl;

	e = a - b + c - d;

	std::cout << e->str() << std::endl;

	e->simplify_sub();

	std::cout << e->str() << std::endl;

	e = a * b * c * d;

	std::cout << e->str() << std::endl;
	
	e->simplify_sub();
	
	std::cout << e->str() << std::endl;

	e = a / b * c / d;

	std::cout << e->str() << std::endl;

	e->simplify_sub();

	std::cout << e->str() << std::endl;

	e = (a + b) * c * d;

	std::cout << e->str() << std::endl;
	e->simplify_sub();
	//e = e->expand();
	e->simplify_sub();
	std::cout << e->str() << std::endl;

}

