//
//  memory.h
//  ECS_040_Program_05
//
//  Created by Justin Weich on 2/12/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#ifndef memory_h
#define memory_h

#include <iostream>

#include "word.h"
#include "data.h"

using namespace std;

class Memory;

class ListNode
{
	friend class Memory;
private:
	ListNode* next;
	Word* word;
public:
	ListNode(Word* word, ListNode* listnode);
	~ListNode();
	
};


class Memory
{
private:
	ListNode* head;
public:
	void insert(Word* word);
	Word& operator[](const int adr);
	Word& operator[](const int adr) const;
	
};




#endif 
