//
// Copyright Jason Rice 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef NBDL_TRAITS_IMPORT_HPP
#define NBDL_TRAITS_IMPORT_HPP

#include "VFUNC.hpp"

#define NBDL_TRAITS_IMPORT(TYPENAME_, ...) \
  static constexpr auto TYPENAME_##_inst_ = ::boost::hana::unpack( \
      TYPENAME_{}, ::boost::hana::make_map);  \
  NBDL_TRAITS_IMPORT_(TYPENAME_##_inst_, __VA_ARGS__)           \

#define NBDL_TRAITS_IMPORT_(...) VFUNC(NBDL_TRAITS_IMPORT, __VA_ARGS__)

#define NBDL_TRAITS_IMPORT63(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT62(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT62(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT61(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT61(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT60(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT60(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT59(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT59(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT58(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT58(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT57(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT57(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT56(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT56(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT55(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT55(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT54(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT54(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT53(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT53(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT52(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT52(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT51(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT51(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT50(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT50(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT49(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT49(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT48(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT48(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT47(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT47(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT46(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT46(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT45(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT45(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT44(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT44(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT43(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT43(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT42(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT42(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT41(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT41(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT40(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT40(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT39(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT39(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT38(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT38(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT37(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT37(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT36(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT36(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT35(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT35(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT34(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT34(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT33(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT33(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT32(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT32(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT31(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT31(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT30(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT30(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT29(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT29(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT28(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT28(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT27(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT27(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT26(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT26(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT25(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT25(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT24(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT24(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT23(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT23(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT22(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT22(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT21(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT21(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT20(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT20(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT19(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT19(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT18(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT18(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT17(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT17(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT16(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT16(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT15(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT15(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT14(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT14(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT13(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT13(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT12(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT12(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT11(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT11(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT10(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT10(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  NBDL_TRAITS_IMPORT9(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT9(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME)  \
  NBDL_TRAITS_IMPORT8(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT8(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME)  \
  NBDL_TRAITS_IMPORT7(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT7(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME)  \
  NBDL_TRAITS_IMPORT6(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT6(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME)  \
  NBDL_TRAITS_IMPORT5(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT5(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME)  \
  NBDL_TRAITS_IMPORT4(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT4(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME)  \
  NBDL_TRAITS_IMPORT3(NAME, __VA_ARGS__)
#define NBDL_TRAITS_IMPORT3(NAME, MNAME, ...) NBDL_TRAITS_IMPORT2(NAME, MNAME)  \
  NBDL_TRAITS_IMPORT2(NAME, __VA_ARGS__)

#define NBDL_TRAITS_IMPORT2(NAME, MNAME) \
  using MNAME = typename decltype(NAME[BOOST_HANA_STRING(#MNAME)])::type;

#endif
