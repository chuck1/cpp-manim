#include <cassert>
#include <manim/animation/TransformCopy.hpp> // esolv/anim/animation/Transform.hpp_in

typedef manim::animation::TransformCopy THIS;

THIS::TransformCopy(mobject::SS_Mobject src, mobject::SS_Mobject dst):
	_M_src(src),
	_M_dst(dst)
{
	assert(src);
	assert(dst);
}

