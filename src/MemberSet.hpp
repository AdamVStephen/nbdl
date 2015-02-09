#ifndef MEMBERSET_HPP
#define MEMBERSET_HPP

#include<type_traits>
#include "EntityTraits.hpp"
#include "Member.hpp"

namespace nbdl {
namespace detail {
template<uintptr_t p1, uintptr_t... pN>
struct NumberSet : NumberSet<pN...>
{
	template<uintptr_t t, int i = 0, bool passed = false> 
	constexpr static int indexOf()
	{
		return (t != p1) ? NumberSet<pN...>::template indexOf<t, i + 1, (t == p1 || passed)>() : i;
	}

	constexpr static uintptr_t at(int i)
	{
		return (i == 0) ? p1 : NumberSet<pN...>::at(i - 1);
	}

	constexpr static int size()
	{
		return sizeof...(pN) + 1;
	}
};

template<uintptr_t p>
struct NumberSet<p>
{
	template<uintptr_t t, int i = 0, bool passed = false> 
	constexpr static int indexOf()
	{
		static_assert((t == p || passed), "Not in set");
		return i;
	}

	constexpr static uintptr_t at(int i)
	{
		//out of range elements 
		//just assume the last member
		return p;
	}

	constexpr static int size()
	{
		return 1;
	}
};
}//detail

template<typename... Mn>
struct MemberSet
{
	template<typename NameFormat, typename Binder, typename OwnerType>
	static void bindMembers(Binder &binder, OwnerType &owner)
	{}
};
template<typename M1, typename... Mn>
struct MemberSet<M1, Mn...>
{
	using Member = M1;
	using Next = MemberSet<Mn...>;
	using Offsets = detail::NumberSet<M1::offset, Mn::offset...>;

	template<typename M>
	static constexpr int indexOf()
	{
		return Offsets::template indexOf<M::offset>();
	}
};

template<class Mset, class = void>
struct MemberSetIsLast : std::true_type {};

template<class Mset>
struct MemberSetIsLast<Mset, typename Void<typename Mset::Next>::type>
	: std::false_type {};

} //nbdl

#endif
