/*
 *  Copyright 2008-2011 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


#pragma once

#include <thrust/detail/config.h>
#include <thrust/detail/backend/cpp/reduce.h>
#include <thrust/detail/backend/dereference.h>

namespace thrust
{
namespace detail
{
namespace backend
{
namespace cpp
{


template<typename InputIterator, 
         typename OutputType,
         typename BinaryFunction>
  OutputType reduce(tag,
                    InputIterator begin,
                    InputIterator end,
                    OutputType init,
                    BinaryFunction binary_op)
{
  // initialize the result
  OutputType result = init;

  while(begin != end)
  {
    result = binary_op(result, backend::dereference(begin));
    begin++;
  } // end while

  return result;
}


} // end namespace cpp
} // end namespace backend
} // end namespace detail
} // end namespace thrust

