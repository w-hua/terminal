/*++
Copyright (c) Microsoft Corporation
Licensed under the MIT license.

Module Name:
- IRenderer.hpp

Abstract:
- This serves as the entry point for console rendering activities.

Author(s):
- Michael Niksa (MiNiksa) 17-Nov-2015
--*/

#pragma once

#include "FontInfoDesired.hpp"
#include "IRenderEngine.hpp"
#include "IRenderTarget.hpp"
#include "../types/inc/viewport.hpp"

namespace Microsoft::Console::Render
{
    class IRenderer : public IRenderTarget
    {
    public:
        [[nodiscard]] virtual HRESULT PaintFrame() = 0;
        virtual void TriggerSystemRedraw(const RECT* const prcDirtyClient) = 0;
        virtual void TriggerFontChange(const int iDpi, const FontInfoDesired& FontInfoDesired, _Out_ FontInfo& FontInfo) = 0;
        virtual void UpdateSoftFont(const gsl::span<const uint16_t> bitPattern, const SIZE cellSize, const size_t centeringHint) = 0;
        [[nodiscard]] virtual HRESULT GetProposedFont(const int iDpi, const FontInfoDesired& FontInfoDesired, _Out_ FontInfo& FontInfo) = 0;
        virtual bool IsGlyphWideByFont(const std::wstring_view glyph) = 0;
        virtual void EnablePainting() = 0;
        virtual void WaitForPaintCompletionAndDisable(const DWORD dwTimeoutMs) = 0;
        virtual void WaitUntilCanRender() = 0;
        virtual void AddRenderEngine(_In_ IRenderEngine* const pEngine) = 0;
    };
}
