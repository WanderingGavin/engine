// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_LIB_UI_PAINTING_VERTICES_H_
#define FLUTTER_LIB_UI_PAINTING_VERTICES_H_

#include "flutter/lib/ui/dart_wrapper.h"
#include "third_party/skia/include/core/SkVertices.h"
#include "third_party/tonic/typed_data/float32_list.h"
#include "third_party/tonic/typed_data/int32_list.h"

namespace tonic {
class DartLibraryNatives;
}  // namespace tonic

namespace blink {

class Vertices : public RefCountedDartWrappable<Vertices> {
  DEFINE_WRAPPERTYPEINFO();
  FML_FRIEND_MAKE_REF_COUNTED(Vertices);

 public:
  ~Vertices() override;

  static void RegisterNatives(tonic::DartLibraryNatives* natives);

  static fml::RefPtr<Vertices> Create();

  void init(SkVertices::VertexMode vertex_mode,
            const tonic::Float32List& positions,
            const tonic::Float32List& texture_coordinates,
            const tonic::Int32List& colors,
            const tonic::Int32List& indices);

  const sk_sp<SkVertices>& vertices() const { return vertices_; }

 private:
  Vertices();

  sk_sp<SkVertices> vertices_;
};

}  // namespace blink

#endif  // FLUTTER_LIB_UI_PAINTING_VERTICES_H_
