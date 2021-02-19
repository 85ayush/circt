//===- FIRRTLAnnotations.h - FIRRTL Annotation ------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the annotations available to the MLIR implementation of
// FIRRTL.
//
//===----------------------------------------------------------------------===//

#ifndef CIRCT_DIALECT_FIRRTL_FIRRTLANNOTATIONS_H
#define CIRCT_DIALECT_FIRRTL_FIRRTLANNOTATIONS_H

#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "llvm/ADT/StringRef.h"

namespace circt {
namespace firrtl {

class Annotation : public mlir::Attribute::AttrBase<Annotation, mlir::Attribute,
                                                    mlir::AttributeStorage> {
public:
  using Base::Base;
};

class InlineAnnotation
    : public mlir::Attribute::AttrBase<InlineAnnotation, Annotation,
                                       mlir::AttributeStorage> {
  std::string className = "passes.InlineAnnotation";

public:
  using Base::Base;

  std::string getClassName() { return className; }
};

class NoDedupAnnotation
    : public mlir::Attribute::AttrBase<NoDedupAnnotation, Annotation,
                                       mlir::AttributeStorage> {
  std::string className = "transforms.NoDedupAnnotation";

public:
  using Base::Base;

  std::string getClassName() { return className; }
};

class RunFirrtlTransformAnnotation
    : public mlir::Attribute::AttrBase<RunFirrtlTransformAnnotation, Annotation,
                                       mlir::AttributeStorage> {
  std::string className = "stage.RunFirrtlTransformAnnotation";

public:
  using Base::Base;

  std::string getClassName() { return className; }
};

} // namespace firrtl
} // namespace circt

#endif // #ifndef CIRCT_DIALECT_FIRRTL_FIRRTLANNOTATIONS_H
