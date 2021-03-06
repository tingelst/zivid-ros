// Copyright (c) 2020 Norwegian University of Science and Technology
// Copyright (c) 2019, Zivid AS
// Use of this source code is governed by the BSD 3-Clause license, see LICENSE

#ifndef ZIVID_CONVERSIONS__VISIBILITY_CONTROL_H_
#define ZIVID_CONVERSIONS__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ZIVID_CONVERSIONS_EXPORT __attribute__ ((dllexport))
    #define ZIVID_CONVERSIONS_IMPORT __attribute__ ((dllimport))
  #else
    #define ZIVID_CONVERSIONS_EXPORT __declspec(dllexport)
    #define ZIVID_CONVERSIONS_IMPORT __declspec(dllimport)
  #endif
  #ifdef ZIVID_CONVERSIONS_BUILDING_LIBRARY
    #define ZIVID_CONVERSIONS_PUBLIC ZIVID_CONVERSIONS_EXPORT
  #else
    #define ZIVID_CONVERSIONS_PUBLIC ZIVID_CONVERSIONS_IMPORT
  #endif
  #define ZIVID_CONVERSIONS_PUBLIC_TYPE ZIVID_CONVERSIONS_PUBLIC
  #define ZIVID_CONVERSIONS_LOCAL
#else
  #define ZIVID_CONVERSIONS_EXPORT __attribute__ ((visibility("default")))
  #define ZIVID_CONVERSIONS_IMPORT
  #if __GNUC__ >= 4
    #define ZIVID_CONVERSIONS_PUBLIC __attribute__ ((visibility("default")))
    #define ZIVID_CONVERSIONS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ZIVID_CONVERSIONS_PUBLIC
    #define ZIVID_CONVERSIONS_LOCAL
  #endif
  #define ZIVID_CONVERSIONS_PUBLIC_TYPE
#endif

#endif  // ZIVID_CONVERSIONS__VISIBILITY_CONTROL_H_
