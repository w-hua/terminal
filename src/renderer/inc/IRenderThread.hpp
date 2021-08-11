/*++
Copyright (c) Microsoft Corporation
Licensed under the MIT license.

Module Name:
- IRenderThread.hpp

Abstract:
- an abstraction for all the actions a render thread needs to perform.

Author(s):
- Mike Griese (migrie) 16 Jan 2019
--*/

#pragma once
namespace Microsoft::Console::Render
{
    class IRenderThread
    {
    public:
        constexpr IRenderThread() = default;
        virtual ~IRenderThread(){};

        IRenderThread(const IRenderThread&) = delete;
        IRenderThread& operator=(const IRenderThread&) = delete;

        IRenderThread(IRenderThread&&) = default;
        IRenderThread& operator=(IRenderThread&&) = default;

        virtual void NotifyPaint() = 0;
        virtual void EnablePainting() = 0;
        virtual void DisablePainting() = 0;
        virtual void WaitForPaintCompletionAndDisable(const DWORD dwTimeoutMs) = 0;
    };
}
