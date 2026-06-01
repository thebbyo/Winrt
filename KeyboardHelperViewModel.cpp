#include "pch.h"
#include "KeyboardHelperViewModel.h"

using namespace winrt;
using namespace Windows::Foundation::Collections;

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    KeyboardHelperViewModel::KeyboardHelperViewModel()
    {
        m_categoryText[KeyboardShortcutHelperCategory::General] = L"General";
        m_categoryText[KeyboardShortcutHelperCategory::TextEditShortcut] = L"Text Editing";
        m_categoryText[KeyboardShortcutHelperCategory::ViewControlShortcut] = L"View Controls";
        m_categoryText[KeyboardShortcutHelperCategory::PanelControlShortcut] = L"Panel Controls";

        GenerateGrouped(GetTextShortcuts(), m_textGroups);
        GenerateGrouped(GetViewShortcuts(), m_viewGroups);
    }

    IObservableVector<GroupInfosList>
    KeyboardHelperViewModel::NoteTextEditShortcuts()
    {
        return m_textGroups;
    }

    IObservableVector<GroupInfosList>
    KeyboardHelperViewModel::NoteViewPanelControlShortcuts()
    {
        return m_viewGroups;
    }

    void KeyboardHelperViewModel::GenerateGrouped(
        std::vector<KeyboardShortcut> const& shortcuts,
        IObservableVector<GroupInfosList> const& target)
    {
        std::map<KeyboardShortcutHelperCategory, GroupInfosList> groups;

        for (auto const& item : shortcuts)
        {
            auto cat = item.HelperCategory();

            if (!groups.contains(cat))
            {
                GroupInfosList g;
                g.Key(L"");
                groups.emplace(cat, g);
            }

            groups[cat].Add(item);
        }

        for (auto& [cat, group] : groups)
        {
            group.Key(m_categoryText[cat]);
            target.Append(group);
        }
    }

    std::vector<KeyboardShortcut> KeyboardHelperViewModel::GetTextShortcuts()
    {
        return
        {
            { L"Bold", L"Ctrl", L"B", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut },
            { L"Italic", L"Ctrl", L"I", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut },
            { L"Underline", L"Ctrl", L"U", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut }
        };
    }

    std::vector<KeyboardShortcut> KeyboardHelperViewModel::GetViewShortcuts()
    {
        return
        {
            { L"Zoom In", L"Ctrl", L"+", L"", L"", KeyboardShortcutHelperCategory::ViewControlShortcut },
            { L"Zoom Out", L"Ctrl", L"-", L"", L"", KeyboardShortcutHelperCategory::ViewControlShortcut }
        };
    }
}
