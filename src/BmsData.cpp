// Copyright (c) 2022 Tobias Himmler
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "BmsData.h"


static struct bmsData_s bmsData;

struct bmsData_s * getBmsData()
{
  return &bmsData;
}
