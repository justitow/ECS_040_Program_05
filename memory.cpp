//
//  memory.cpp
//  ECS_040_Program_05
//
//  Created by Justin Weich on 2/12/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#include "memory.h"

Word& Memory::operator[](const int adr)
{
	ListNode* node = head;
	Word* word(adr);
	while (node->word < word)
	{
		node = node->next;
	} //while

	if (!(word < node->word))
	{
		return &node->word;
	}// if not equal

	else
	{
		Data data = new Data(adr);
		insert(data);
		return &data;
	} //else
	
}// operator[]

Word& Memory::operator[](const int adr) const
{
	ListNode* node = head;
	Word* word(adr);
	while (*node->word < *word)
	{
		node = node->next;
	} //while
	
	if (!(*word < *node->word))
	{
		return &node->word;
	}// if not equal
	
	else
	{
		cout << "ya dun goofed";
	} // else

}// operator[]

void Memory::insert(Word* word)
{
	ListNode* node = head;
	ListNode* prev = node;

	while (*node->word < *word)
	{
		prev = node;
		node = node->next;
	} //while ()

	ListNode* newNode = new ListNode(word, node);
	prev->next = newNode;

} //insert()

