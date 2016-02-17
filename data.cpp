//
//  data.cpp
//  ECS_040_Program_05
//
//  Created by Justin Weich on 2/12/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#include "data.h"

Data::Data(int address) : Word(address)
{
	
}

Data::~Data()
{
	
}

int& Data::get()
{
	return num;
}

int Data::get() const
{
	return num;
}

int& Data::operator=(int newInt)
{
	num = newInt;
	return num;
}