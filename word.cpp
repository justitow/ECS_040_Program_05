//
//  word.cpp
//  ECS_040_Program_05
//
//  Created by Justin Weich on 2/12/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#include "word.h"
using namespace std;

Word::Word(int myAdr) : address(myAdr)
{
	
}

Word::~Word()
{
	
}

bool operator<(Word& l, Word& r)
{
	if (&l < &r)
		return true;
	else
		return false;
}

const int Word::getAdress() const
{
	return address;
}
