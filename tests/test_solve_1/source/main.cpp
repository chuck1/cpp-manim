#include <iostream>

#include <esolv/esolv.hpp>
#include <esolv/resolver/Base.hpp>

class Foo: public esolv::Storage
{
	public:
		void	init()
		{
			esolv::Storage::init();

			// TODO convert to equationd_add
			/*
			   option_add("x", std::bind(&Foo::x_0, this));
			   option_add("x", std::bind(&Foo::x_1, this));
			   option_add("y", std::bind(&Foo::y_0, this));
			   option_add("w", std::bind(&Foo::w_0, this));
			   */

			equation_add(std::bind(&Foo::equations, this, std::placeholders::_1));

			guess_add("x", std::bind(&Foo::x_guess, this));
		}
		esolv::symbol::S_Operand	x_guess()
		{
			auto n = std::make_shared<esolv::number::Integral<float>>(1.0);
			return std::make_shared<esolv::quantity::Base>(n);
		}
		void		equations(esolv::symbol::SET_Operand & ret)
		{
			auto x = get("x");
			auto y = get("y");

			ret.insert(y - x->log());
			ret.insert(y - x->intpower(-1,1));
		}
};
int main()
{
	esolv::System s;

	auto f = std::make_shared<Foo>();
	f->init();

	auto equations = f->get_equations();
	std::cout << "equations " << equations.size() << std::endl;
	esolv::solve::print_equations(f->root(), equations);

	//f->_M_resolver->_M_guess.set("x", std::make_shared<esolv::quantity::Base>(1.0));

	std::cout << "solve" << std::endl;
	esolv::solve::solve(f->symbol("x"), esolv::symbol::SET_Symbol());

	auto x = f->get("x");
	auto y = f->get("y");

	std::cout << "x=" << x->str() << std::endl;
	std::cout << "y=" << y->str() << std::endl;

	auto xl = x->variables();
	auto yl = y->variables();

	std::cout << "xl=" << xl.size() << std::endl;
	std::cout << "yl=" << yl.size() << std::endl;

	std::cout << "x=" << x->calc()->str() << std::endl;
	std::cout << "y=" << y->calc()->str() << std::endl;

}


