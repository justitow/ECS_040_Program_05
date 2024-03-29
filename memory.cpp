//
//  memory.cpp
//  ECS_040_Program_05
//
//  Created by Justin Weich on 2/12/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#include "memory.h"
#include "registers.h"


ListNode::ListNode(Word* myword, ListNode* listnode)
{
  word = myword;
  next = listnode;
} // constructor

ListNode::~ListNode()
{
  delete word;
} // destructor

Memory::Memory() : head(NULL)
{

} // constructor

Memory::~Memory()
{
  ListNode* ptr = head;
  ListNode* prev = NULL;

  while (ptr->next != NULL)
  {
    prev = ptr;
    ptr = ptr->next;
    delete prev;
  } // while
} // destructor

Word& Memory::operator[](int adr)
{

  ListNode* node = head;
  Word* word = new Word(adr);
  while (node != NULL && *node->word < *word)
  {
    node = node->next;
  } //while

  if (node != NULL && !(*word < *node->word))
  {
    return *node->word;
  }// if not equal

  else // this happened
  {
    Data* data = new Data(adr);
    insert(data);
    return *data;
  } // else
  }// operator[]

Word& Memory::operator[](const int adr) const
{
  ListNode* node = head;
  Word* word = new Word(adr);
  while (node != NULL && *node->word < *word)
  {
    node = node->next;
  } //while

  if (node != NULL && !(*word < *node->word))
  {
    return *node->word;
  }// if not equal

  else // its not good
  {
    //cout << "ya dun goofed";
    return *node->word;
  } // else

}// operator[]

void Memory::insert(Word* word)
{

  ListNode *ptr, *prev = NULL;

  for (ptr = head; ptr && (*ptr->word < *word); ptr = ptr->next)
  {
    prev = ptr;

  } // for

  if(prev)
    prev->next = new ListNode(word, ptr);
      else // this happened?
        head = new ListNode(word, ptr);

} //insert()

const Instruction& Memory::fetch(Registers *registers) const
{
  Instruction& instruction =
  dynamic_cast<Instruction&>((*this)[registers->get(Registers::eip)]);
  registers->set(Registers::eip, registers->get(Registers::eip) + 4);
  return instruction;
} // fetch()

istream& operator>> (istream &is, Memory &memory)
{
  char line[256], *ptr;
  int c_address = 100;

  while(is.getline(line, 256))
  {
    for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
      *ptr = ' ';  // replace all tabs with space characters

    for(ptr = line; *ptr == ' '; ptr++);  // get past leading spaces

    if(*ptr != '.' && *ptr != '_' && !strstr(line, "main:") &&
       !strchr(line, ':'))
    {
      Instruction* instruction = new Instruction(c_address);
      *instruction = line;
      memory.insert(instruction);
      c_address += 4;

    } // if not directive, nor main:
  }  // while more in file

  return is;
}  // operator>>
