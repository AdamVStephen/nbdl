//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef NBDL_FWD_GET_PATH_HPP
#define NBDL_FWD_GET_PATH_HPP

namespace nbdl
{
  struct get_path_fn
  {
    template<typename Store, typename Path>
    constexpr decltype(auto) operator()(Store&&, Path&&) const;
  };

  // get_path - not to be confused with nbdl::message::get_path
  constexpr get_path_fn get_path{};
}

#endif
