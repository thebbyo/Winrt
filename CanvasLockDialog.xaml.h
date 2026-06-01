#pragma once

#include "CanvasLockDialog.g.h"

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct CanvasLockDialog : CanvasLockDialogT<CanvasLockDialog>
    {
        CanvasLockDialog();
    };
}

namespace winrt::SamsungNotes::UI::Controls::factory_implementation
{
    struct CanvasLockDialog : CanvasLockDialogT<CanvasLockDialog, implementation::CanvasLockDialog>
    {
    };
}
