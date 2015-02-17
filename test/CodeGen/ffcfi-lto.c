// RUN: touch %t.o
//
// RUN: %clang -target x86_64-unknown-linux -### %t.o -ffcfi -flto 2>&1 | FileCheck %s
// CHECK: "-plugin" "{{.*}}/LLVMgold.so"
// CHECK: "-plugin-opt=-fcfi"

