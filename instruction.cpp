// Author: Sean Davis
#include "instruction.h"
#include <iostream>
#include <cstring>


using namespace std;

Instruction::Instruction(int adr) : Word(adr), info(NULL)
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
  strcpy(info, information+1);
	return *info;
} // setInfo()

ostream& operator<<(ostream& output, const Instruction& instruction)
{
	output << instruction.info;
	return output;
}


