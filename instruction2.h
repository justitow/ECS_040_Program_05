//
//  instruction2.hpp
//  ECS_040_Program_05
//
//  Created by Justin Weich on 2/17/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#ifndef instruction2_h
#define instruction2_h

class Instruction2
{
  int address;
  char *info;
public:
  Instruction2();
  ~Instruction2();
  int getAddress() const;
  const char* getInfo() const;
  void setAddress(int addr);
  void setInfo(const char* information);

}; //class Instruction

#endif
