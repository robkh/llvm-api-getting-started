#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/IRPrintingPasses.h"
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

  Function::arg_iterator args = Sum->arg_begin();
  Value* x = cast<Value>(args++);
  Value* y = cast<Value>(args++);

  // Create BB
  BasicBlock* block = BasicBlock::Create(Ctx, "entry", Sum);
  IRBuilder<> builder(block);

  // Create Add
  Value* tmp = builder.CreateAdd(x, y, "tmp");
  builder.CreateRet(tmp);

  // Verify Module
  verifyModule(*Mod);

  legacy::PassManager PM;
  PM.add(createPrintModulePass(outs()));
  PM.run(*Mod);

  delete Mod;
  return 0;
}
