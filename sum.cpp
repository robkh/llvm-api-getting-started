#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"

int main(int argc, char**argv) {

  llvm::LLVMContext Ctx;
  llvm::Module* Mod = new llvm::Module("my_module", Ctx);

  llvm::Constant* Func = Mod->getOrInsertFunction("sum",
      llvm::Type::getInt32Ty(Ctx), llvm::Type::getInt32Ty(Ctx),
      llvm::Type::getInt32Ty(Ctx), NULL);

  delete Mod;
  return 0;
}
