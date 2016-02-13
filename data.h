//
//  data.h
//  ECS_040_Program_05
//
//  Created by Justin Weich on 2/12/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#ifndef data_h
#define data_h

#include <iostream>
#include "word.h"

using namespace std;

class Data : public Word
{
private:
	int num;
public:
	Data(int myAdr);
	~Data();
	int& get();
	int get() const;
	int& operator=(const int& newNum);
};

#endif /* data_h */