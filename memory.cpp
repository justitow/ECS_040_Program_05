//
//  memory.cpp
//  ECS_040_Program_05
//
//  Created by Justin Weich on 2/12/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#include "memory.h"

ListNode::ListNode(Word* myword, ListNode* listnode)
{
	word = myword;
	next = listnode;
}

Word& Memory::operator[](int adr)
{
	ListNode* node = head;
	Word* word = new Word(adr);
	
	if (node->word != NULL)
	{
		while ((node != NULL) && (*node->word < *word))
		{
			node = node->next;
		} //while

		if (!(*word < *node->word))
		{
			return *node->word;
		}// if not equal
	}

	Data* data = new Data(adr);
	insert(data);
	return *data;
	
}// operator[]

Word& Memory::operator[](const int adr) const
{
	ListNode* node = head;
	Word* word = new Word(adr);
	while (*node->word < *word)
	{
		node = node->next;
	} //while
	
	if (!(*word < *node->word))
	{
		return *node->word;
	}// if not equal
	
	else
	{
		//cout << "ya dun goofed";
		return *node->word;
	} // else

}// operator[]

void Memory::insert(Word* word)
{

	if (head != NULL)
	{
		ListNode* node = head;
		ListNode* prev = node;

		if (node->next != NULL)
		{
			if (*word < *node->word)
			{
				head = new ListNode(word, head);
			}
			else
			{
				while (*node->word < *word)
				{
					prev = node;
					node = node->next;
				} // while
				
				prev->next = new ListNode(word, node);
			}
		} // if

		else
		{

			if (*word < *node->word)
			{
				head = new ListNode(word, head);
			} // if

			else
			{
				head->next = new ListNode(word, NULL);
			} // else
		} //else
	} // if
	else
	{
		head = new ListNode(word, NULL);
	} // else

} //insert()

