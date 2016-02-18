//
//  data.cpp
//  ECS_040_Program_05
//
//  Created by Justin Weich on 2/12/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#include "data.h"

Data::Data(int adr) : Word(adr)
{
  
} // constructor

int& Data::get()
{
  return num;
} // get

int Data::get() const
{
  return num;
} // other get

int& Data::operator=(int newInt)
{
  num = newInt;
  return num;
} // operator= 
