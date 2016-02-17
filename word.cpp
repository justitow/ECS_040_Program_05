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

bool operator<(const Word& l, const Word& r)
{
	if (l.address < r.address)
	{
		return true;
	}
	else
	{
		return false;
	}
}
