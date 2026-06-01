#pragma once
#include "GroupInfosList.h"
#include "KeyboardShortcut.h"

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct KeyboardHelperViewModel
    {
    private:
        winrt::Windows::Foundation::Collections::IObservableVector<GroupInfosList> m_textGroups =
            winrt::single_threaded_observable_vector<GroupInfosList>();

        winrt::Windows::Foundation::Collections::IObservableVector<GroupInfosList> m_viewGroups =
            winrt::single_threaded_observable_vector<GroupInfosList>();

        std::map<KeyboardShortcutHelperCategory, hstring> m_categoryText;

    public:
        KeyboardHelperViewModel();

        winrt::Windows::Foundation::Collections::IObservableVector<GroupInfosList>
            NoteTextEditShortcuts();

        winrt::Windows::Foundation::Collections::IObservableVector<GroupInfosList>
            NoteViewPanelControlShortcuts();

    private:
        void GenerateGrouped(
            std::vector<KeyboardShortcut> const& shortcuts,
            winrt::Windows::Foundation::Collections::IObservableVector<GroupInfosList> const& target);

        std::vector<KeyboardShortcut> GetTextShortcuts();
        std::vector<KeyboardShortcut> GetViewShortcuts();
    };
}
