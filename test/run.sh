clang -O0 -emit-llvm -S input.c -o input.ll
opt -load-pass-plugin ../build/pass/libLoopUnrollPass.so -passes=loop-unroll -S input.ll -o output.ll
cat output.ll
