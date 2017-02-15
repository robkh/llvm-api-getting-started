#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
using namespace llvm;

int main(int argc, char**argv) {

  LLVMContext Ctx;

  // Create module
  Module* Mod = new Module("my_module", Ctx);

  // Create function
  Constant* Con = Mod->getOrInsertFunction("sum",
      Type::getInt32Ty(Ctx), Type::getInt32Ty(Ctx),
      Type::getInt32Ty(Ctx), NULL);

  Function* Sum = cast<Function>(Con);
  Sum->setCallingConv(llvm::CallingConv::C);

  // Create BB
  BasicBlock* block = BasicBlock::Create(Ctx, "entry", Sum);

  delete Mod;
  return 0;
}
