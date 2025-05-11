#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/IR/CFG.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {

struct LoopUnrollPass : public FunctionPass {
  static char ID;
  LoopUnrollPass() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    errs() << "[+] Running Loop Unroll Pass on function: " << F.getName() << "\n";

    for (auto &BB : F) {
      for (auto &I : BB) {
        if (auto *br = dyn_cast<BranchInst>(&I)) {
          if (br->isConditional()) {
            errs() << "  [*] Found conditional branch in BB: " << BB.getName() << "\n";
          }
        }
      }
    }

    return false;
  }
};

}

char LoopUnrollPass::ID = 0;
static RegisterPass<LoopUnrollPass> X("loop-unroll", "Simple Loop Unrolling Pass", false, false);
