#include <iostream>

#include <esolv/esolv.hpp>
#include <esolv/resolver/Base.hpp>

void	test(esolv::symbol::S_Symbol x, esolv::symbol::S_Operand f, bool expect_failure, bool & failed)
{
	std::cout << f->str() << std::endl;
	
	esolv::symbol::S_Operand l, r;

	auto ret = esolv::util::Util::isolate(x, f, l, r);

	if(!ret)
	{
		std::cout << "FAILED" << std::endl;
		if(!expect_failure) failed = true;
	}

	std::cout << "    " << l->str() << std::endl;
	std::cout << "    " << r->str() << std::endl;
}
int main()
{
	esolv::Factory::_S_factory.reset(new esolv::_Factory);

	esolv::System s;

	auto f = std::make_shared<esolv::Storage>();
	f->init();
	
	bool failed = false;

	auto x = f->symbol("x");
	auto a = f->symbol("a");
	auto b = f->symbol("b");
	auto c = f->symbol("c");
	auto d = f->symbol("d");
	auto e = f->symbol("d");

	esolv::util::Util::_level_static = 0;
	esolv::symbol::Operand::_level_static = 0;
	
	test(x, x / (x - a) - b, true, failed);
	test(x, a * (b * x / (x + d))->exp() - e, true, failed);

	test(x, a * x + b - c * x, false, failed);
	
	esolv::symbol::S_Operand y = x - d;
	test(x, a * y + b - c * y, true, failed);

        y = (x / a)->log();
        test(x, y * b + y * c - d, true, failed);

	test(x, a - ((b + c) / (d * x)), true, failed);

	assert(!failed);
}







