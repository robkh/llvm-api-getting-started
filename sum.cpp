#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"

int main(int argc, char**argv) {

  llvm::LLVMContext Context;
  llvm::Module* Mod = new llvm::Module("my_module", Context);

  delete Mod;
  return 0;
}
