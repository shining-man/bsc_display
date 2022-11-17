// Copyright (c) 2022 Tobias Himmler
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT


#include "data.h"


static struct data_s data;

struct data_s * getData()
{
  return &data;
}
