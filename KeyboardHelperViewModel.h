#pragma once
#include <winrt/Windows.Foundation.Collections.h>
#include "winrt/SamsungNotes.UI.Controls.h"
namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct KeyboardHelperViewModel
    {
    private:
        hstring m_header =
            L"Keyboard Shortcuts";
        winrt::Windows::Foundation::Collections::
            IObservableVector<
            winrt::SamsungNotes::UI::Controls::KeyboardShortcut>
            m_noteTextEditShortcuts
        {
            winrt::single_threaded_observable_vector<
            winrt::SamsungNotes::UI::Controls::KeyboardShortcut>()
        };
        winrt::Windows::Foundation::Collections::
            IObservableVector<
            winrt::SamsungNotes::UI::Controls::KeyboardShortcut>
            m_noteViewPanelControlShortcuts
        {
            winrt::single_threaded_observable_vector<
            winrt::SamsungNotes::UI::Controls::KeyboardShortcut>()
        };
    public:
        KeyboardHelperViewModel();
        hstring KeyboardHelperHeader();
        winrt::Windows::Foundation::Collections::
            IObservableVector<
            winrt::SamsungNotes::UI::Controls::KeyboardShortcut>
            NoteTextEditShortcuts();
        winrt::Windows::Foundation::Collections::
            IObservableVector<
            winrt::SamsungNotes::UI::Controls::KeyboardShortcut>
            NoteViewPanelControlShortcuts();
    };
}
