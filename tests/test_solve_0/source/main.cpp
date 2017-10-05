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

			equation_add(std::bind(&Foo::x_, this, std::placeholders::_1));
			equation_add(std::bind(&Foo::y_, this, std::placeholders::_1));
			equation_add(std::bind(&Foo::w_, this, std::placeholders::_1));

			guess_add("x", std::bind(&Foo::x_guess, this));
		}
		esolv::symbol::S_Operand	x_guess()
		{
			auto n = std::make_shared<esolv::number::Integral<float>>(1.0);
			return std::make_shared<esolv::quantity::Base>(n);
		}
		void		x_(esolv::symbol::SET_Operand & ret)
		{
			auto x = get("x");
			ret.insert(get("y") + 4.0f - x);
			ret.insert(get("z") - x);
		}
		void		y_(esolv::symbol::SET_Operand & ret)
		{
			ret.insert(std::make_shared<esolv::symbol::operation::unary::IntPower>(get("w"),1,2) - get("y"));
		}
		void		w_(esolv::symbol::SET_Operand & ret)
		{
			ret.insert(get("x") - get("w"));
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

	auto w = f->get("w");
	auto x = f->get("x");
	auto y = f->get("y");

	std::cout << "w=" << w->str() << std::endl;
	std::cout << "x=" << x->str() << std::endl;
	std::cout << "y=" << y->str() << std::endl;

	auto wl = w->variables();
	auto xl = x->variables();
	auto yl = y->variables();

	std::cout << "wl=" << wl.size() << std::endl;
	std::cout << "xl=" << xl.size() << std::endl;
	std::cout << "yl=" << yl.size() << std::endl;

	std::cout << "w=" << w->calc()->str() << std::endl;
	std::cout << "x=" << x->calc()->str() << std::endl;
	std::cout << "y=" << y->calc()->str() << std::endl;

}


