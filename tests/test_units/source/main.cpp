#include <regex>
#include <iostream>

#include <esolv/esolv.hpp>
#include <esolv/symbol/Symbol.hpp> // esolv/symbol/Symbol.hpp.in


int main()
{
	auto & u_J = *esolv::unit::unit("J");
	auto & u_K = *esolv::unit::unit("K");
	auto & u_mole = *esolv::unit::unit("mole");
	auto & u_m = *esolv::unit::unit("m");
	
	auto & u_m2 = u_m * u_m;

	std::cout << u_m2.str() << std::endl;

	auto & u_m3 = u_m2 * u_m;

	auto & u1 = u_J / u_K;
	auto & u2 = u1 / u_mole;
	
	std::cout << u1.str() << std::endl;
	std::cout << u2.str() << std::endl;

	auto R = u2(8.3144598);

	auto P = (*esolv::unit::unit("Pa"))(100000);
	auto V = u_m3(1);
	auto n = u_mole(10);
	
	auto T = P * V / n / R;
	
	std::cout << R->str() << std::endl;
	//std::cout << n->str() << std::endl;
	//std::cout << P->str() << std::endl;
	//std::cout << V->str() << std::endl;
	std::cout << T->str() << std::endl;

	auto T2 = T->simplify_sub();
}

