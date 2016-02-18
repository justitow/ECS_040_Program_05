// Author: Sean Davis
#include <cstring>
#include <iostream>
#include <cstdlib>
#include "decoder.h"
#include "instruction.h"
#include "registers.h"
using namespace std;

void Decoder::addl(Registers *registers)
{
  *operand2 = *operand1 + *operand2;
   registers->setFlags(*operand2);
}  // addl()


void Decoder::andl(Registers *registers)
{
  *operand2 = *operand1 & *operand2;
  registers->setFlags(*operand2);
}  // andl()


void Decoder::call(Registers *registers, Memory& memory) const
{
	Data &data = dynamic_cast <Data&> (memory[*registers += -4]);
	data.get() = registers->get(Registers::eip);
  registers->set(Registers::eip, *operand1);
} // call()


void Decoder::cmpl(Registers *registers) const
{
  registers->setFlags(*operand2 - *operand1);
}  // cmpl()

void Decoder::decl(Registers *registers)
{
	*operand1 -= 1;
	registers->setFlags(*operand1);
}

void Decoder::execute(const Instruction &instruction,
                      Registers *registers, Memory& memory)
{
  const char *opcodes[] = { "addl", "andl", "leave", "movl", "pushl", "ret",
    "subl", "cmpl", "incl", "jg", "jle", "jmp", "leal", "call", "sall", "imull"
		"decl"};
  enum OpcodeNum 
    {ADDL, ANDL, LEAVE, MOVL, PUSHL, RET, SUBL, CMPL, INCL, JG,
      JLE, JMP, LEAL, CALL, SALL, IMULL, DECL
    };  // enum OpcodeNum
  int opcodeNum;
  
  for(opcodeNum = ADDL; 
    strcmp(opcode, opcodes[opcodeNum]) != 0 || opcodeNum > DECL;
    ++opcodeNum);
  
  switch (opcodeNum)
  {
    case ADDL: addl(registers); break;
    case ANDL: andl(registers); break;
		case DECL: decl(registers); break;
    case LEAVE: leave(registers, memory); break;
    case MOVL: movl(); break;
    case PUSHL: pushl(registers, memory); break;
    case RET: ret(registers, memory); break;
    case SUBL: subl(registers); break;
    case CMPL: cmpl(registers); break;
		case IMULL: imull(registers); break;
    case INCL: incl(registers); break;
    case JG: jg(registers); break;
    case JLE:  jle(registers); break;
    case JMP: jmp(registers); break;
    case LEAL: leal(&instruction, registers); break;
    case CALL: call(registers, memory); break;
    case SALL: sall(registers); break;
    default: cout << "Invalid opcode!\n";
  } // switch on oncodeNum
 
}  // execute()

void Decoder::imull(Registers *registers)
{
	*operand2 = *operand1 * *operand2;
	registers->setFlags(*operand2);
} // imull


void Decoder::incl(Registers *registers)
{
  registers->setFlags(++(*operand1));
}  // incl()


void Decoder::jg(Registers *registers) const
{
  if(!registers->getSF() && !registers->getZF())
    registers->set(Registers::eip, *operand1);
} // jg()


void Decoder::jle(Registers *registers) const
{
  if(registers->getSF() || registers->getZF())
    registers->set(Registers::eip, *operand1);
}  // jle()


void Decoder::jmp(Registers *registers) const
{
  registers->set(Registers::eip, *operand1);
}  // jmp()


void Decoder::leal(const Instruction *instruction, const Registers *registers)
{
  char *ptr, info[1000], *otherPtr;
	int regNum;
  strcpy(info, instruction->getInfo());
  strtok(info, " ");  // get past leal
	otherPtr = strchr(info, ',');
  ptr = strtok(NULL, " ");
	regNum = registers->stringToRegNum(ptr);
	*operand2 = atoi(ptr) + registers->get((Registers::RegName)regNum);
}  // leal()


void Decoder::leave(Registers *registers, const Memory& memory) const
{
	Data &data = dynamic_cast <Data&> (memory[registers->get(Registers::esp)]);
  registers->set(Registers::esp, registers->get(Registers::ebp));
  registers->set(Registers::ebp, data.get());
  registers->set(Registers::esp, registers->get(Registers::esp) + 4);
}  // leave()


void Decoder::movl()
{
  *operand2 = *operand1;
}  // movl()


void Decoder::parse(const Instruction &instruction, Registers *registers,
                    Memory& memory, const Labels &labels)
{
  char *ptr, info[1000];
  
  strcpy(info, instruction.getInfo());
  strcpy(opcode, strtok(info, " "));
  ptr = strtok(NULL, " ");
  if(ptr)
  {
    operand1 = registers->address(ptr, memory, labels);
    ptr = strtok(NULL, " ");
    
    if(ptr)
      operand2 = registers->address(ptr, memory, labels);
  } // if there is at least one operand
}  // parse()





void Decoder::pushl(Registers *registers, Memory& memory) const
{
	Data &data = dynamic_cast <Data&> (memory[*registers += -4]);
	
	data.get() = *operand1;
}  // pushl()




void Decoder::ret(Registers *registers, const Memory& memory) const
{

	Data &data = dynamic_cast <Data&> (memory[registers->get(Registers::esp)]);
  registers->set(Registers::eip, data.get());
  *registers += 4;
}  // ret()


void Decoder::sall(Registers *registers)
{
  *operand2 <<= *operand1;
  registers->setFlags(*operand2);
}  // sall()


void Decoder::subl(Registers *registers)
{
  *operand2 = *operand2 - *operand1;
  registers->setFlags(*operand2);
}  // subl()
