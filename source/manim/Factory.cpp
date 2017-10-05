#include <cassert>
#include <typeinfo>
#include <iostream>

#include <manim/_Factory.hpp> // esolv/Factory.hpp_in

#include <manim/Factory.hpp> // esolv/Factory.hpp_in

typedef manim::Factory THIS;

std::shared_ptr<manim::_Factory>		THIS::_S_factory;

bool						THIS::is_python()
{
	assert(_S_factory);
	return _S_factory->is_python();
}
manim::animation::S_Transform		THIS::new_anim_transform(
		manim::mobject::SS_Mobject src,
		manim::mobject::SS_Mobject dst)
{
	assert(_S_factory);
	return _S_factory->new_anim_transform(src, dst);
}
manim::animation::S_TransformCopy		THIS::new_anim_transform_copy(
		manim::mobject::SS_Mobject src,
		manim::mobject::SS_Mobject dst)
{
	assert(_S_factory);
	return _S_factory->new_anim_transform_copy(src, dst);
}
manim::animation::S_Write			THIS::new_anim_write(
		manim::mobject::SS_Mobject obj)
{
	assert(_S_factory);
	return _S_factory->new_anim_write(obj);
}
manim::animation::S_Uncreate		THIS::new_anim_uncreate(
		manim::mobject::SS_Mobject obj,
		float run_time)
{
	assert(_S_factory);
	return _S_factory->new_anim_uncreate(obj, run_time);
}
manim::mobject::S_Mobject			THIS::new_anim_mobject(std::vector<manim::mobject::S_Mobject> l)
{
	assert(_S_factory);
	return _S_factory->new_anim_mobject(l);
}
manim::mobject::S_TexMobject		THIS::new_anim_texmobject(std::vector<std::string> l)
{
	assert(_S_factory);
	return _S_factory->new_anim_texmobject(l);
}




