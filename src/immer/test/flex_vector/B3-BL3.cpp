//
// immer: immutable data structures for C++
// Copyright (C) 2016, 2017, 2018 Juan Pedro Bolivar Puente
//
// This software is distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt
//

#include <immer/flex_vector.hpp>
#include <immer/vector.hpp>

template <typename T>
using test_flex_vector_t =
    immer::flex_vector<T, immer::default_memory_policy, 3u, 3u>;

template <typename T>
using test_vector_t = immer::vector<T, immer::default_memory_policy, 3u, 3u>;

#define FLEX_VECTOR_T test_flex_vector_t
#define VECTOR_T test_vector_t
#include "generic.ipp"
