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


class Data : public Word
{
private:
	int num;
public:
	Data(int);
	int get() const;
	int& get();
	int& operator=(int);
};

#endif 