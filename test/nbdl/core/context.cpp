//
// Copyright Jason Rice 2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <assets/TestContext.hpp>
#include <nbdl/detail/make_create_path_type.hpp>
#include <nbdl/make_context.hpp>
#include <nbdl/make_def.hpp>
#include <nbdl/message.hpp>
#include <nbdl/null_store.hpp>

#include <boost/hana/equal.hpp>
#include <boost/hana/value.hpp>
#include <boost/mp11/list.hpp>
#include <catch.hpp>

namespace hana    = boost::hana;
namespace entity  = test_context::entity;
namespace message = nbdl::message;
namespace channel = nbdl::message::channel;
namespace action  = nbdl::message::action;
using namespace boost::mp11;

namespace test_context_
{
  struct my_context { };
}

namespace nbdl
{
  template <>
  struct make_def_impl<test_context_::my_context>
  {
    static constexpr auto apply()
    {
      return test_context_def::make(
        test_context::producer_tag<>{},
        test_context::producer_tag<>{},
        test_context::consumer_tag<>{},
        test_context::consumer_tag<>{},
        nbdl::null_store{}
      );
    }
  };
}

namespace
{
  struct check_message_equal_fn
  {
    template <typename MessageVariant, typename Orig>
    constexpr auto operator()(MessageVariant const& m, Orig const& o) const
    {
      bool result = false;
      m.match(
        [&](auto const& m)
          -> std::enable_if_t<std::is_same<std::decay_t<decltype(m)>, std::decay_t<Orig>>::value>
        {
          result = hana::equal(m.storage, o.storage);
        },
        [&](auto const&) { result = false; }
      );
      return result;
    }
  };

  constexpr struct check_message_equal_fn check_message_equal{};
}

TEST_CASE("Dispatch Downstream Read Message", "[context]")
{
  auto context = nbdl::make_unique_context<test_context_::my_context>();

  auto& producer0 = context->actor<0>();
  auto& producer1 = context->actor<1>();
  auto& consumer2 = context->actor<2>();
  auto& consumer3 = context->actor<3>();

  // Send downstream read to consumers.
  auto msg = message::make_downstream_read(
    test_context::path1(1, 2)
  , message::no_uid
  , entity::my_entity<1>{2, 1}
  );
  nbdl::apply_message(producer0.context, msg);

  CHECK(producer0.recorded_messages.size() == 0);
  CHECK(producer1.recorded_messages.size() == 0);
  CHECK(consumer2.recorded_messages.size() == 1);
  CHECK(consumer3.recorded_messages.size() == 1);

  // Both consumers got the downstream
  // read message from producer0
  CHECK(check_message_equal(consumer2.recorded_messages[0], msg));
  CHECK(check_message_equal(consumer3.recorded_messages[0], msg));
}

#if 0 // TODO need valid test for upstream_read (can't use null_store)
TEST_CASE("Dispatch Upstream Read Message", "[context]")
{
  auto context = nbdl::make_unique_context<test_context_::my_context>();

  auto& producer0 = context->actor<0>();
  auto& producer1 = context->actor<1>();
  auto& consumer2 = context->actor<2>();
  auto& consumer3 = context->actor<3>();

  // Send upstream read to producer0.
  auto msg = message::make_upstream_read(test_context::path1(1, 2));
  nbdl::apply_message(consumer2.context, msg);

  // producer1 should not receive the message.
  REQUIRE(producer0.recorded_messages.size() == 1);
  CHECK(producer1.recorded_messages.size() == 0);
  CHECK(consumer2.recorded_messages.size() == 0);
  CHECK(consumer3.recorded_messages.size() == 0);

  // producer0 should record an upstream read message.
  CHECK(check_message_equal(producer0.recorded_messages[0], msg));
}
#endif

TEST_CASE("Dispatch Downstream Create Message", "[context]")
{
  hana::for_each(hana::make_tuple(
    hana::make_pair(hana::type_c<test_context::path<0>>, hana::type_c<entity::my_entity<1>>),
    hana::make_pair(hana::type_c<test_context::path<1>>, hana::type_c<entity::my_entity<1>>),
    hana::make_pair(hana::type_c<test_context::path<2>>, hana::type_c<entity::my_entity<2>>),
    hana::make_pair(hana::type_c<test_context::path<3>>, hana::type_c<entity::my_entity<3>>),
    hana::make_pair(hana::type_c<test_context::path<4>>, hana::type_c<entity::my_entity<4>>)
  ), [](auto types)
  {
    using Path = typename decltype(+hana::first(types))::type;
    using Entity = typename decltype(+hana::second(types))::type;

    auto context = nbdl::make_unique_context<test_context_::my_context>();

    auto& producer0 = context->actor<0>();
    auto& producer1 = context->actor<1>();
    auto& consumer2 = context->actor<2>();
    auto& consumer3 = context->actor<3>();

    // Send downstream create to consumers.
    auto msg = message::make_downstream_create(
      Path(1, 2)
    , message::no_uid
    , Entity{2, 1}
    , message::no_is_confirmed
    );
    nbdl::apply_message(producer0.context, msg);

    CHECK(producer0.recorded_messages.size() == 0);
    CHECK(producer1.recorded_messages.size() == 0);
    CHECK(consumer2.recorded_messages.size() == 1);
    CHECK(consumer3.recorded_messages.size() == 1);

    // Both consumers got the downstream
    // create message from producer0
    CHECK(check_message_equal(consumer2.recorded_messages[0], msg));
    CHECK(check_message_equal(consumer3.recorded_messages[0], msg));
  });
}

TEST_CASE("Dispatch Upstream Create Message", "[context]")
{
  // root1
  hana::for_each(hana::make_tuple(
    hana::make_pair(hana::type_c<test_context::path<0>>, hana::type_c<entity::my_entity<1>>)
  ), [](auto types)
  {
    using Path = typename decltype(+hana::first(types))::type;
    using Entity = typename decltype(+hana::second(types))::type;

    auto context = nbdl::make_unique_context<test_context_::my_context>();

    auto& producer0 = context->actor<0>();
    auto& producer1 = context->actor<1>();
    auto& consumer2 = context->actor<2>();
    auto& consumer3 = context->actor<3>();

    // Send upstream create to producer0.
    auto msg = message::make_upstream_create(
      message::make_create_path<mp_second<Path>>(hana::tuple<mp_first<Path>>{1})
    , message::no_uid
    , Entity{2, 1}
    );
    nbdl::apply_message(consumer2.context, msg);

    // producer1 should not receive the message.
    CHECK(producer0.recorded_messages.size() == 1);
    CHECK(producer1.recorded_messages.size() == 0);
    CHECK(consumer2.recorded_messages.size() == 0);
    CHECK(consumer3.recorded_messages.size() == 0);

    // producer0 should record an upstream create message.
    CHECK(check_message_equal(producer0.recorded_messages[0], msg));
  });

  // root2
  hana::for_each(hana::make_tuple(
    hana::make_pair(hana::type_c<test_context::path<1>>, hana::type_c<entity::my_entity<1>>),
    hana::make_pair(hana::type_c<test_context::path<2>>, hana::type_c<entity::my_entity<2>>),
    hana::make_pair(hana::type_c<test_context::path<3>>, hana::type_c<entity::my_entity<3>>),
    hana::make_pair(hana::type_c<test_context::path<4>>, hana::type_c<entity::my_entity<4>>)
  ), [](auto types)
  {
    using Path = typename decltype(+hana::first(types))::type;
    using Entity = typename decltype(+hana::second(types))::type;

    auto context = nbdl::make_unique_context<test_context_::my_context>();

    auto& producer0 = context->actor<0>();
    auto& producer1 = context->actor<1>();
    auto& consumer2 = context->actor<2>();
    auto& consumer3 = context->actor<3>();

    // Send upstream create to producer0.
    auto msg = message::make_upstream_create(
      message::make_create_path<mp_second<Path>>(hana::tuple<mp_first<Path>>{1})
    , message::no_uid
    , Entity{2, 1}
    );
    nbdl::apply_message(consumer2.context, msg);

    // producer0 should not receive the message.
    CHECK(producer0.recorded_messages.size() == 0);
    CHECK(producer1.recorded_messages.size() == 1);
    CHECK(consumer2.recorded_messages.size() == 0);
    CHECK(consumer3.recorded_messages.size() == 0);

    // producer1 should record an upstream create message.
    CHECK(check_message_equal(producer1.recorded_messages[0], msg));
  });
}

TEST_CASE("Dispatch Downstream Update Message", "[context]")
{
  hana::for_each(hana::make_tuple(
    hana::make_pair(hana::type_c<test_context::path<0>>, hana::type_c<entity::my_entity<1>>),
    hana::make_pair(hana::type_c<test_context::path<1>>, hana::type_c<entity::my_entity<1>>),
    hana::make_pair(hana::type_c<test_context::path<2>>, hana::type_c<entity::my_entity<2>>),
    hana::make_pair(hana::type_c<test_context::path<3>>, hana::type_c<entity::my_entity<3>>),
    hana::make_pair(hana::type_c<test_context::path<4>>, hana::type_c<entity::my_entity<4>>)
  ), [](auto types)
  {
    using Path = typename decltype(+hana::first(types))::type;
    using Entity = typename decltype(+hana::second(types))::type;

    auto context = nbdl::make_unique_context<test_context_::my_context>();

    auto& producer0 = context->actor<0>();
    auto& producer1 = context->actor<1>();
    auto& consumer2 = context->actor<2>();
    auto& consumer3 = context->actor<3>();

    // Send downstream update to consumers.
    auto msg = message::make_downstream_update(
      Path(1, 2)
    , message::no_uid
    , Entity{2, 1}
    , message::no_is_confirmed
    );
    nbdl::apply_message(producer0.context, msg);

    CHECK(producer0.recorded_messages.size() == 0);
    CHECK(producer1.recorded_messages.size() == 0);
    CHECK(consumer2.recorded_messages.size() == 1);
    CHECK(consumer3.recorded_messages.size() == 1);

    // Both consumers got the downstream
    // update message from producer0
    CHECK(check_message_equal(consumer2.recorded_messages[0], msg));
    CHECK(check_message_equal(consumer3.recorded_messages[0], msg));
  });
}

TEST_CASE("Dispatch Upstream Update Message", "[context]")
{
  // root1
  hana::for_each(hana::make_tuple(
    hana::make_pair(hana::type_c<test_context::path<0>>, hana::type_c<entity::my_entity<1>>)
  ), [](auto types)
  {
    using Path = typename decltype(+hana::first(types))::type;
    using Entity = typename decltype(+hana::second(types))::type;

    auto context = nbdl::make_unique_context<test_context_::my_context>();

    auto& producer0 = context->actor<0>();
    auto& producer1 = context->actor<1>();
    auto& consumer2 = context->actor<2>();
    auto& consumer3 = context->actor<3>();

    // Send upstream update to producer0.
    auto msg = message::make_upstream_update(
      Path(1, 2)
    , message::no_uid
    , Entity{2, 1}
    );
    nbdl::apply_message(consumer2.context, msg);

    // producer1 should not receive the message.
    CHECK(producer0.recorded_messages.size() == 1);
    CHECK(producer1.recorded_messages.size() == 0);
    CHECK(consumer2.recorded_messages.size() == 0);
    CHECK(consumer3.recorded_messages.size() == 0);

    // producer0 should record an upstream update message.
    CHECK(check_message_equal(producer0.recorded_messages[0], msg));
  });

  // root2
  hana::for_each(hana::make_tuple(
    hana::make_pair(hana::type_c<test_context::path<1>>, hana::type_c<entity::my_entity<1>>),
    hana::make_pair(hana::type_c<test_context::path<2>>, hana::type_c<entity::my_entity<2>>),
    hana::make_pair(hana::type_c<test_context::path<3>>, hana::type_c<entity::my_entity<3>>),
    hana::make_pair(hana::type_c<test_context::path<4>>, hana::type_c<entity::my_entity<4>>)
  ), [](auto types)
  {
    using Path = typename decltype(+hana::first(types))::type;
    using Entity = typename decltype(+hana::second(types))::type;

    auto context = nbdl::make_unique_context<test_context_::my_context>();

    auto& producer0 = context->actor<0>();
    auto& producer1 = context->actor<1>();
    auto& consumer2 = context->actor<2>();
    auto& consumer3 = context->actor<3>();

    // Send upstream update to producer0.
    auto msg = message::make_upstream_update(
      Path(1, 2)
    , message::no_uid
    , Entity{2, 1}
    );
    nbdl::apply_message(consumer2.context, msg);

    // producer0 should not receive the message.
    CHECK(producer0.recorded_messages.size() == 0);
    CHECK(producer1.recorded_messages.size() == 1);
    CHECK(consumer2.recorded_messages.size() == 0);
    CHECK(consumer3.recorded_messages.size() == 0);

    // producer1 should record an upstream update message.
    CHECK(check_message_equal(producer1.recorded_messages[0], msg));
  });
}
