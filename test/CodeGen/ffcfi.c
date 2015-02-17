// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu %s -ffcfi -emit-llvm -o - | FileCheck %s

int f() { return 0; }
// CHECK: define i32 @f() unnamed_addr #0 {
// CHECK: attributes #0 = { jumptable {{.*}} }

