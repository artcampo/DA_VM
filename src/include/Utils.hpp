#pragma once
#include <string>
class ByteCode;

namespace VMUtils{
  class ASTVisitorCodeGenerator;
  
  void print(ByteCode const &byte_code);
  
  void      writeByteCode(ByteCode const &byte_code, 
                          std::string const &file_name);
  ByteCode* readByteCode(std::string const &file_name);
  
  //only useful for debugging/TESTING
  void printRaw(ByteCode const &byte_code);
};