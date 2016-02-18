#ifndef INSTRUCTION_H
#define	INSTRUCTION_H
// Author: Sean Davis

#include "word.h"

class Instruction : public Word
{
  char *info;
public:
  Instruction(const int adr);
  virtual ~Instruction();
  const char* getInfo() const;
  char operator=(const char* information);
	friend std::ostream& operator<<(std::ostream&, const Instruction&);
  
}; //class Instruction

#endif	// INSTRUCTION_H 

