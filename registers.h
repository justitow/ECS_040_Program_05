#ifndef REGISTERS_H
#define  REGISTERS_H
// Author: Sean Davis

#include <iostream>
#include "labels.h"
#include "memory.h"
using namespace std;


class Registers
{
  int regs[8];
  static const int ZF = 0x40;
  static const int SF = 0x80;
public:
  int stringToRegNum(const char *regString) const;
  typedef enum {eax, ebp, esp, eip, edx, ebx, ecx, flags} RegName;
  Registers();
  int* address(char *ptr, Memory &memory, const Labels &labels);
  int get(Registers::RegName regName) const;
  bool getSF() const;
  bool getZF() const;

  int operator+= (int change);
  friend ostream& operator<< (ostream &os, const Registers &registers);
  int* scaledIndexMode(char *operand, Memory &memory) const;
  void set(Registers::RegName regName, int value);
  void setFlags(int value);
}; // class Registers

#endif  // REGISTERS_H
