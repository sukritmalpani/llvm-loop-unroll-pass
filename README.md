# LLVM Loop Unroll Pass

This is a custom LLVM pass that performs static loop unrolling on simple `for` loops. It detects loops with known trip counts and replaces them with repeated bodies, reducing control overhead and enabling better instruction-level parallelism.

## 🔧 How it works

1. Compiles a simple input C program to LLVM IR.
2. Applies the custom loop unroll pass using `opt`.
3. Generates optimized LLVM IR with unrolled loops.

## 📦 Tech Stack

- LLVM (version 16+)
- C++
- CMake

## 🚀 Getting Started

### 1. Build the Pass

```bash
mkdir build && cd build
cmake ..
make
```

### 2. Run on Example

```bash
cd ../test
bash run.sh
```

## 📂 Example Input

```c
void loop() {
    for (int i = 0; i < 4; ++i)
        printf("Hello %d\n", i);
}
```

## ✅ Output (Unrolled Loop)

```llvm
call void @printf(...)
call void @printf(...)
call void @printf(...)
call void @printf(...)
```

## ✨ Future Work

- Support for nested loops
- Dynamic loop unrolling (using runtime info)
- Integration with MLIR

## 👨‍💻 Author

Sukrit Malpani — [GitHub](https://github.com/sukritmalpani)
