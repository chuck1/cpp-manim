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
			auto n = std::make_shared<esolv::number::Integral<float>>(1);
			return std::make_shared<esolv::quantity::Base>(n);
		}
		void		equations(esolv::symbol::SET_Operand & ret)
		{
			auto x = get("x");
			auto y = get("y");
			auto C = get("C");

			//ret.insert(y - (1. - (-a * (1. - (-x)->exp()))->exp()) / a);

			auto a = (-x*(1-C))->exp();

			ret.insert(y - (1. - a) / (1. - C * a));
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

	f->set("C", esolv::quantity::Error::create(0.3, 0.03));
	f->set("y", esolv::quantity::Error::create(0.9, 0.09));
	
	auto C = f->symbol("C");
	auto x = f->symbol("x");
	auto y = f->symbol("y");

	std::cout << "solve" << std::endl;
	
	//esolv::solve::solve(f->symbol("x"), {});
	//x->calc();
	esolv::util::Util::try_numerical(x);

	std::cout << "x=" << x->str() << std::endl;
	std::cout << "y=" << y->str() << std::endl;

	esolv::symbol::SET_Symbol xl, yl;
	x->variables(xl);
	y->variables(yl);

	std::cout << "xl=" << xl.size() << std::endl;
	std::cout << "yl=" << yl.size() << std::endl;

	std::cout << "x=" << x->calc()->str() << std::endl;
	std::cout << "y=" << y->calc()->str() << std::endl;

	if(0)
	{
	for(auto o : f->get_equations(x))
	{
		std::cout << o->str() << std::endl;

		for(auto v : o->variables())
		{
			std::cout << std::endl;
			std::cout << "    " << v->str() << std::endl;
			auto d = o->derivative(v);
			std::cout << "        " << d->str() << std::endl;
			auto p = d->simplify_sub();
			while(p)
			{
				d = p;
				std::cout << "        " << d->str() << std::endl;
				p = d->simplify_sub();
			}
			std::cout << std::endl;
		}
	}
	}
	
	auto l_e = f->get_equations(x);
	auto o = *l_e.begin();
	o = o->derivative(x);
	std::cout << std::endl << o->str() << std::endl << std::endl;
	
	auto b = (-x * (1 - C))->exp();
	auto a = o->factor(b);
	
	if(a)
	{	
		std::cout << std::endl << o->str() << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl << "could not factor " << b->str() << std::endl << std::endl;
	}

	std::cout << "C error " << C->calc_rss()->str() << std::endl;
	std::cout << "y error " << y->calc_rss()->str() << std::endl;
	std::cout << "x error " << x->calc_rss()->str() << std::endl;
}







