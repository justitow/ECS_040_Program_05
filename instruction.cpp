// Author: Sean Davis
#include "instruction.h"
#include <iostream>
#include <cstring>



Instruction::Instruction(int adr) : info(NULL), Word(adr)
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



char& Instruction::operator=(const char* information)
{
  info = new char[strlen(information) + 1];
  strcpy(info, information);
	return *info;
} // setInfo()

ostream& operator<<(ostream& output, Instruction& instruction)
{
	output << instruction.getInfo();
	return output;
}

void Instruction::fetch(Registers *registers) const
{
	int pos;
	
	for(pos = 0; lines[pos].getAddress() != registers->get(Registers::eip);
			pos++);
	
	instruction->setInfo(lines[pos].getInfo());
	registers->set(Registers::eip, registers->get(Registers::eip) + 4);
} // fetch()

