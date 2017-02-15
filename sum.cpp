#include "llvm/Module.h"

int main(int argc, char**argv) {
  Module* Mod = makeLLVMModule();

  verifyModule(*Mod, PrintMessageAction);

  delete Mod;
  return 0;
}
