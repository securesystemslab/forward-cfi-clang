// RUN: %clang -target x86_64-unknown-linux-gnu -### -S -ffcfi %s 2>&1 | FileCheck  %s
// Make sure the driver passes down the ffcfi option.
// CHECK: "-ffcfi"

