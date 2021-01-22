/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TNT_FILAMENT_FG2_RENDERTARGET_H
#define TNT_FILAMENT_FG2_RENDERTARGET_H

#include "fg2/Texture.h"

#include <backend/DriverEnums.h>

#include <filament/Viewport.h>

namespace filament::fg2 {

/**
 * RenderTarget is used to draw into a Texture resource. These are transient objects that
 * exist inside a pass only.
 */
struct RenderTarget {
    struct Attachments {
        FrameGraphId<Texture> color[4] = {};
        FrameGraphId<Texture> depth{};
        FrameGraphId<Texture> stencil{};
    };

    struct Descriptor {
        Attachments attachments{};
        Viewport viewport{};
        math::float4 clearColor{};
        uint8_t samples = 0; // # of samples (0 = unset, default)
        backend::TargetBufferFlags clearFlags{};
    };

    Attachments attachments{};
    uint32_t id = 0;
};

} // namespace filament::fg2

#endif //TNT_FILAMENT_FG2_RENDERTARGET_H
