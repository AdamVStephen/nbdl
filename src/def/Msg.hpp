//
// Copyright Jason Rice 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef NBDL_DEF_MSG_HPP
#define NBDL_DEF_MSG_HPP

namespace nbdl_ddl {
namespace def {

/*
 * DOWNSTREAM only messages:
 *  Read
 *  NotFound
 *  Error ??
 * 
 * UPSTREAM only messages:
 *  ReadRequest
 *  CreateUpstreamOnly 
 *  UpdateUpstreamOnly
 *  DeleteUpstreamOnly
 *  AccessControlError
 *
 * UPSTREAM/DOWNSTREAM:
 *  Create
 *  Update
 *  Delete  
 */

/*
 * Msg
 *
  ((
    MsgType
    Path,
    Entity,
  ), Storage)
 */
template<typename Action, typename AccessPoint>
auto buildMsgStorage(Action action, AccessPoint access_point)
{
  auto path = path(access_point);
  return hana::make_tuple(
    path, 
    uuid, // (Uuid|!)
    entityStorage(access_point),  // (Entity|Diff)
    create_info); // (CreateInfo|!)
    
}

template<typename Action, typename AccessPoint>
auto buildMsg(Action action, AccessPoint access_point)
{
  return hana::make_pair(
    hana::make_tuple(action,  path(access_point)),
    buildMsgStorage(action, access_point));
}

//messages that go upstream
template<typename T>
auto upstreamMsgs(T access_point)
{
  hana::unpack(
    meta::findByTag(access_point, tag::Actions),
    [](auto... actions) {
        return hana::transform(
          hana::filter(
            hana::make_tuple(something_that_returns_an_optional(actions)...)
            hana::is_just), 
          hana::from_just);
    });

}

template<typename T>
constexpr auto downstreamMsgs(T access_point)
{
  
}

}//def
}//nbdl_ddl
