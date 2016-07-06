#include "VM.h"
#include "ByteCode.h"
#include "IRCodification.h"
#include <iostream>

int main(){
  std::unique_ptr<ByteCode> bc(new ByteCode());
  
  using namespace IRCodification;
  using namespace IRBuilder;
  bc->stream = std::vector<uint32_t> {
    Load( IR_REG0, 12),
    Load( IR_REG1, 15),   
    Add ( IR_REG0, IR_REG1, IR_REG2),
    Stop()
  };
  
  
  if(!checkIRCodification()){
    std::cout << "IR sizes invalid\n";
    return 1;
  }
//   std::cout << "test1 - started" << std::endl;
//   for(auto it : bc->stream)
//     std::cout << it <<", ";
  
  std::unique_ptr<VirtualMachine> vm(new VirtualMachine(*bc) );
  vm->ExecProcess();
  vm->DumpExecutionContext();
  
  return 0;
}