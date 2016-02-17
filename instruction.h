#ifndef INSTRUCTION_H
#define	INSTRUCTION_H
// Author: Sean Davis

#include "word.h"

class Instruction : public Word
{
  char *info;
public:
  Instruction(int adr);
  virtual ~Instruction();
  const char* getInfo() const;
  char& operator=(const char* information);
	friend ostream& operator<<(ostream&, Instruction&);
  
}; //class Instruction

#endif	// INSTRUCTION_H 

