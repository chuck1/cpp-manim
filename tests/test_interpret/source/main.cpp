#include <regex>
#include <iostream>

#include <esolv/esolv.hpp>
#include <esolv/symbol/Symbol.hpp> // esolv/symbol/Symbol.hpp.in

class Parser: public esolv::Storage
{
public:
	std::shared_ptr<esolv::symbol::Operand>		process_operand(std::string s);
	std::shared_ptr<esolv::symbol::Operand>		process_symbol(std::string s);
	std::shared_ptr<esolv::symbol::Operand>		process_number(std::string s);
	std::shared_ptr<esolv::symbol::Operand>		process_add(std::string s);
	std::shared_ptr<esolv::symbol::Operand>		process_sub(std::string s);
	int						process_line(std::string s);
	void						process_string(std::string s);
};


std::shared_ptr<esolv::symbol::Operand>		Parser::process_symbol(std::string s)
{
	//std::cout << "process_symbol(" << s << ")" << std::endl;

	std::shared_ptr<esolv::symbol::Operand> ret;

	std::regex re("[a-zA-z]\\w*");
	std::smatch match;

	std::regex_match(s, match, re);
	
	if(match.empty()) return ret;

	return symbol(s);
}
std::shared_ptr<esolv::symbol::Operand>		Parser::process_number(std::string s)
{
	//std::cout << "process_symbol(" << s << ")" << std::endl;

	std::shared_ptr<esolv::symbol::Operand> ret;

	std::regex re("\\d+");
	std::smatch match;

	std::regex_match(s, match, re);
	
	if(match.empty()) return ret;

	return std::make_shared<esolv::quantity::Base>(std::make_shared<esolv::number::Integral<float>>(stof(s)));
}
std::shared_ptr<esolv::symbol::Operand>		Parser::process_operand(std::string s)
{
	std::shared_ptr<esolv::symbol::Operand> x;

	x = process_add(s);
	if(x) return x;

	x = process_sub(s);
	if(x) return x;
	
	x = process_symbol(s);
	if(x) return x;

	x = process_number(s);
	if(x) return x;

	throw std::exception();

	return x;
}
std::shared_ptr<esolv::symbol::Operand>		Parser::process_add(std::string s)
{
	std::regex re("(.*)\\+(.*)");
	std::smatch match;

	std::regex_match(s, match, re);
	
	if(match.empty()) return std::shared_ptr<esolv::symbol::Operand>();

	auto s1 = match[1].str();
	auto s2 = match[2].str();

	/*
	std::cout << "addition" << std::endl;
	std::cout << s << std::endl;
	std::cout << "  " << s1 << std::endl;
	std::cout << "  " << s2 << std::endl;
	*/

	auto a1 = process_operand(s1);
	auto a2 = process_operand(s2);

	return (a1 + a2);
}
std::shared_ptr<esolv::symbol::Operand>		Parser::process_sub(std::string s)
{
	std::regex re("(.*)-(.*)");
	std::smatch match;

	std::regex_match(s, match, re);
	
	if(match.empty()) return std::shared_ptr<esolv::symbol::Operand>();

	auto s1 = match[1].str();
	auto s2 = match[2].str();

	/*
	std::cout << "addition" << std::endl;
	std::cout << s << std::endl;
	std::cout << "  " << s1 << std::endl;
	std::cout << "  " << s2 << std::endl;
	*/

	auto a1 = process_operand(s1);
	auto a2 = process_operand(s2);

	return (a1 - a2);
}
int						Parser::process_line(std::string s)
{
	std::regex re("(.*)=(.*)");
	
	std::smatch match;

	std::regex_match(s, match, re);

	if(match.empty()) return 1;
	
	std::cout << "equality" << std::endl;
	std::cout << s << std::endl;
	auto s1 = match[1].str();
	auto s2 = match[2].str();
	
	int ret;
	ret = process_line(s1);
	if(ret)
	{
		auto o1 = process_operand(s1);
		if(o1) std::cout << "process_operand -> " << o1->str() << std::endl;
	}
	
	ret = process_line(s2);
	if(ret)
	{
		process_add(s2);
	}

	return 0;
}
void			Parser::process_string(std::string s)
{
	std::cout << "string: '" << s << "'" << std::endl;
		
	std::regex re("([^;]+);(.*)");
	
	std::smatch match;

	std::regex_match(s, match, re);
	
	if(match.empty()) return;
	
	//process_line(match[1].str());
	auto o = process_operand(match[1].str());
	std::cout << "operand: " << o->str() << std::endl;
	std::cout << "         " << o->simplify_sub().second->str() << std::endl;

	process_string(match[2].str());
}
int main()
{
	auto s = std::make_shared<Parser>();
	
	//std::string str = "a+b=c;1+1+1+1=2+2=4;";
	std::string str = "a+b-c;1+1+1+1;";
	
	s->process_string(str);
	
	//auto match_begin = std::sregex_iterator(str.begin(), str.end(), re);
	//auto match_end = std::sregex_iterator();

	//auto a = s->symbol("a");

}

