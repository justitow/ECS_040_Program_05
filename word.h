//
//  word.hpp
//  ECS_040_Program_05
//
//  Created by Justin Weich on 2/12/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#ifndef word_h
#define word_h

#include <iostream>

class Word
{
	
private:
	int address;
public:
	Word(int myAdr);
	virtual ~Word();
	friend bool operator<(const Word& L, const Word& R);
}; // class Word

#endif 