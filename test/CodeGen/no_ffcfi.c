// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu %s -emit-llvm -o - | FileCheck %s

int f() { return 0; }
// CHECK-NOT: define i32 @f() unnamed_addr #0 {
// CHECK-NOT: attributes #0 = { jumptable {{.*}} }

