#include <cassert>
#include <manim/animation/Transform.hpp> // esolv/anim/animation/Transform.hpp_in

typedef manim::animation::Transform THIS;

THIS::Transform(mobject::SS_Mobject src, mobject::SS_Mobject dst):
	_M_src(src),
	_M_dst(dst)
{
	assert(src);
	assert(dst);
}

