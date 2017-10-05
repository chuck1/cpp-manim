#include <typeinfo>
#include <iostream>

/*
#include <esolv/symbol/operation/unary/unary.hpp> // esolv/symbol/operation/unary/unary.hpp
#include <esolv/symbol/except.hpp> // esolv/symbol/except.hpp.in
#include <esolv/symbol/Symbol.hpp> // esolv/symbol/Symbol.hpp.in
#include <esolv/util/util.hpp> // esolv/util/util.hpp.in

#include <esolv/number/Integral.hpp> // esolv/number/Integral.hpp_in
#include <esolv/number/operations.hpp>
#include <esolv/quantity/Error.hpp> // esolv/quantity/Error.hpp_in
#include <esolv/ScopedPush.hpp>

#include <esolv/symbol/Unity.hpp> // esolv/symbol/Operand.hpp_in
#include <esolv/symbol/operation/array/Mul.hpp> // esolv/symbol/Operand.hpp_in
#include <esolv/symbol/operation/array/Add.hpp> // esolv/symbol/Operand.hpp_in
*/
//#include <esolv/except/except.hpp>
#include <manim/animation/animation.hpp>
#include <manim/mobject/TexMobject.hpp>

#include <manim/_Factory.hpp> // esolv/Factory.hpp_in

typedef manim::_Factory THIS;

bool						THIS::is_python() const
{
	return false;
}
manim::animation::S_Transform		THIS::new_anim_transform(
		manim::mobject::SS_Mobject src,
		manim::mobject::SS_Mobject dst) const
{
	if(is_python()) throw std::exception();
	return std::make_shared<manim::animation::Transform>(src, dst);
}
manim::animation::S_TransformCopy		THIS::new_anim_transform_copy(
		manim::mobject::SS_Mobject src,
		manim::mobject::SS_Mobject dst) const
{
	if(is_python()) throw std::exception();
	return std::make_shared<manim::animation::TransformCopy>(src, dst);
}
manim::animation::S_Write			THIS::new_anim_write(
		manim::mobject::SS_Mobject obj) const
{
	if(is_python()) throw std::exception();
	return std::make_shared<manim::animation::Write>(obj);
}
manim::animation::S_Uncreate		THIS::new_anim_uncreate(
		manim::mobject::SS_Mobject obj,
		float run_time) const
{
	if(is_python()) throw std::exception();
	return std::make_shared<manim::animation::Uncreate>(obj, run_time);
}
manim::mobject::S_Mobject			THIS::new_anim_mobject(std::vector<manim::mobject::S_Mobject> l) const
{
	if(is_python()) throw std::exception();
	return manim::mobject::S_Mobject();
}
manim::mobject::S_TexMobject		THIS::new_anim_texmobject(std::vector<std::string> l) const
{
	if(is_python()) throw std::exception();
	return manim::mobject::S_TexMobject();
}




