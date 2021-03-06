//
// Copyright Jason Rice 2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef NBDL_FWD_APPLY_ACTION_HPP
#define NBDL_FWD_APPLY_ACTION_HPP

#include<boost/hana/core/when.hpp>

namespace nbdl
{
  namespace hana = boost::hana;

  template<typename T, typename = void>
  struct apply_action_impl : apply_action_impl<T, hana::when<true>> { };

  struct apply_action_fn
  {
    // returns true if the state changed in any way
    template<typename Store, typename Message>
    constexpr auto operator()(Store&&, Message&&) const;
  };

  constexpr apply_action_fn apply_action{};
} // nbdl

#endif
