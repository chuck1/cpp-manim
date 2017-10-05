#include <cassert>
//#include <esolv/stacktrace.hpp>
#include <manim/Factory.hpp>
#include <manim/mobject/Mobject.hpp> // esolv/anim/mobject/Pointer.hpp_in

#include <manim/mobject/Pointer.hpp> // esolv/anim/mobject/Pointer.hpp_in

typedef manim::mobject::Pointer THIS;

THIS::Pointer():
	_M_ptr(new manim::mobject::S_Mobject),
	_M_s(0),
	_M_e(0)
{}
void					THIS::load(manim::mobject::S_Mobject mobj)
{
	assert(_M_s);
	assert(_M_e);
	
	(*_M_ptr) = manim::Factory::new_anim_mobject(mobj->submobjects(*_M_s, *_M_e));
	assert((*_M_ptr));
}
manim::mobject::S_Mobject		THIS::object()
{
	assert(_M_ptr);
	auto o = *_M_ptr;
	return o;
}
manim::mobject::S_Mobject		THIS::object() const
{
	assert(_M_ptr);
	auto o = *_M_ptr;
	return o;
}
void					THIS::set(unsigned int i)
{
	_M_s = new unsigned int;
	_M_e = new unsigned int;
	*_M_s = i;
	*_M_e = i + 1;
}
void					THIS::set(unsigned int s, unsigned int e)
{
	_M_s = new unsigned int;
	_M_e = new unsigned int;
	*_M_s = s;
	*_M_e = e;
}
void					THIS::start(unsigned int s)
{
	_M_s = new unsigned int;
	*_M_s = s;
}
void					THIS::end(unsigned int e)
{
	_M_e = new unsigned int;
	*_M_e = e;
}


