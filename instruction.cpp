// Author: Sean Davis
#include "instruction.h"
#include <iostream>
#include <cstring>


using namespace std;

Instruction::Instruction(const int adr) : Word(adr), info(NULL)
{
}  // Instruction()


Instruction::~Instruction()
{
  if(info)
    delete [] info;
}  // ~Instruction
  


const char* Instruction::getInfo() const
{
  return info;
} // get()



char Instruction::operator=(const char* information)
{
  info = new char[strlen(information) + 1];
	if (information[0] == ' ')
	{
		information++;
	}
  strcpy(info, information);
	return *info;
} // setInfo()

ostream& operator<<(ostream& output, const Instruction& instruction)
{
	output << instruction.info;
	return output;
}


