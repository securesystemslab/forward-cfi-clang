// REQUIRES: shell
//
// RUN: cd %S
// RUN: rm -rf %t
// RUN: mkdir %t
// RUN: %clang_cc1 -cc1 -fmodule-name=relative-dep-gen -emit-module -x c++ Inputs/relative-dep-gen.modulemap -dependency-file %t/build.d -MT mod.pcm -o %t/mod.pcm
// RUN: %clang_cc1 -cc1 -fmodule-map-file=Inputs/relative-dep-gen.modulemap -fmodule-file=%t/mod.pcm -dependency-file %t/use-explicit.d -MT use.o relative-dep-gen.cpp -fsyntax-only
// RUN: %clang_cc1 -cc1 -fmodule-map-file=Inputs/relative-dep-gen.modulemap -dependency-file %t/use-implicit.d relative-dep-gen.cpp -MT use.o -fsyntax-only
//
// RUN: FileCheck --check-prefix=CHECK-BUILD %s < %t/build.d
// RUN: FileCheck --check-prefix=CHECK-USE %s < %t/use-explicit.d
// RUN: FileCheck --check-prefix=CHECK-USE %s < %t/use-implicit.d

#include "Inputs/relative-dep-gen-1.h"

// CHECK-BUILD: mod.pcm: Inputs/relative-dep-gen-1.h Inputs/relative-dep-gen-2.h
// CHECK-USE: use.o: relative-dep-gen.cpp Inputs/relative-dep-gen-1.h
