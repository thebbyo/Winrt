#include "pch.h"
#include "KeyboardHelper.xaml.h"
#include "KeyboardHelper.g.cpp"
#include "winrt/SamsungNotes.UI.Controls.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace winrt::SamsungNotes::UI::Controls;

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    KeyboardHelper::KeyboardHelper()
    {
        // Register the BooleanToVisibilityConverter as a resource
        auto converter = winrt::make<winrt::SamsungNotes::UI::Controls::implementation::BooleanToVisibilityConverter>();
        this->Resources().Insert(winrt::box_value(L"BooleanToVisibilityConverter"), converter);

        InitializeComponent();
        m_viewModel = KeyboardHelperViewModel();

        OutputDebugString(L"=== KeyboardHelper Constructor Start ===\n");

        // ===== Left column: Note Text Edit Shortcuts =====
        auto noteTextGroups = winrt::single_threaded_observable_vector<GroupInfosList>();
        auto noteTextShortcuts = m_viewModel.NoteTextEditShortcuts();

        OutputDebugString(L"NoteTextEditShortcuts flat count: ");
        OutputDebugString(std::to_wstring(noteTextShortcuts.Size()).c_str());
        OutputDebugString(L"\n");

        KeyboardShortcutHelperCategory categories[] = {
            KeyboardShortcutHelperCategory::General,
            KeyboardShortcutHelperCategory::NoteEditShortcut,
            KeyboardShortcutHelperCategory::TextEditShortcut
        };
        hstring categoryHeaders[] = {
            L"",
            L"Editing shortcuts",
            L"Text shortcuts"
        };

        for (int i = 0; i < 3; i++)
        {
            GroupInfosList group;
            group.Key(categoryHeaders[i]);

            for (uint32_t j = 0; j < noteTextShortcuts.Size(); j++)
            {
                auto item = noteTextShortcuts.GetAt(j);
                if (item.HelperCategory() == categories[i])
                {
                    group.Add(item);
                }
            }

            OutputDebugString(L"Group '");
            OutputDebugString(categoryHeaders[i].c_str());
            OutputDebugString(L"' - Key='");
            OutputDebugString(group.Key().c_str());
            OutputDebugString(L"', Size=");
            OutputDebugString(std::to_wstring(group.Size()).c_str());
            OutputDebugString(L", Items count=");
            OutputDebugString(std::to_wstring(group.Items().Size()).c_str());
            OutputDebugString(L"\n");

            // Log each item in the group
            for (uint32_t j = 0; j < group.Items().Size(); j++)
            {
                auto item = group.Items().GetAt(j);
                OutputDebugString(L"  Item: ");
                OutputDebugString(item.FuncName().c_str());
                OutputDebugString(L" | ");
                OutputDebugString(item.ShortcutKey1().c_str());
                if (!item.ShortcutKey2().empty()) { OutputDebugString(L" + "); OutputDebugString(item.ShortcutKey2().c_str()); }
                if (!item.ShortcutKey3().empty()) { OutputDebugString(L" + "); OutputDebugString(item.ShortcutKey3().c_str()); }
                if (!item.ShortcutKey4().empty()) { OutputDebugString(L" + "); OutputDebugString(item.ShortcutKey4().c_str()); }
                OutputDebugString(L"\n");
            }

            if (group.Size() > 0)
            {
                noteTextGroups.Append(group);
            }
        }

        OutputDebugString(L"noteTextGroups total groups: ");
        OutputDebugString(std::to_wstring(noteTextGroups.Size()).c_str());
        OutputDebugString(L"\n");

        NoteTextGroupsControl().ItemsSource(noteTextGroups);

        // ===== Right column: View Panel Control Shortcuts =====
        auto viewPanelGroups = winrt::single_threaded_observable_vector<GroupInfosList>();
        auto viewPanelShortcuts = m_viewModel.NoteViewPanelControlShortcuts();

        OutputDebugString(L"ViewPanelControlShortcuts flat count: ");
        OutputDebugString(std::to_wstring(viewPanelShortcuts.Size()).c_str());
        OutputDebugString(L"\n");

        KeyboardShortcutHelperCategory vpCategories[] = {
            KeyboardShortcutHelperCategory::ViewControlShortcut,
            KeyboardShortcutHelperCategory::PanelControlShortcut
        };
        hstring vpCategoryHeaders[] = {
            L"Editing shortcuts",
            L"Settings shortcuts"
        };

        for (int i = 0; i < 2; i++)
        {
            GroupInfosList group;
            group.Key(vpCategoryHeaders[i]);

            for (uint32_t j = 0; j < viewPanelShortcuts.Size(); j++)
            {
                auto item = viewPanelShortcuts.GetAt(j);
                if (item.HelperCategory() == vpCategories[i])
                {
                    group.Add(item);
                }
            }

            OutputDebugString(L"Group '");
            OutputDebugString(vpCategoryHeaders[i].c_str());
            OutputDebugString(L"' - Key='");
            OutputDebugString(group.Key().c_str());
            OutputDebugString(L"', Size=");
            OutputDebugString(std::to_wstring(group.Size()).c_str());
            OutputDebugString(L", Items count=");
            OutputDebugString(std::to_wstring(group.Items().Size()).c_str());
            OutputDebugString(L"\n");

            // Log each item in the group
            for (uint32_t j = 0; j < group.Items().Size(); j++)
            {
                auto item = group.Items().GetAt(j);
                OutputDebugString(L"  Item: ");
                OutputDebugString(item.FuncName().c_str());
                OutputDebugString(L" | ");
                OutputDebugString(item.ShortcutKey1().c_str());
                if (!item.ShortcutKey2().empty()) { OutputDebugString(L" + "); OutputDebugString(item.ShortcutKey2().c_str()); }
                if (!item.ShortcutKey3().empty()) { OutputDebugString(L" + "); OutputDebugString(item.ShortcutKey3().c_str()); }
                if (!item.ShortcutKey4().empty()) { OutputDebugString(L" + "); OutputDebugString(item.ShortcutKey4().c_str()); }
                OutputDebugString(L"\n");
            }

            if (group.Size() > 0)
            {
                viewPanelGroups.Append(group);
            }
        }

        OutputDebugString(L"viewPanelGroups total groups: ");
        OutputDebugString(std::to_wstring(viewPanelGroups.Size()).c_str());
        OutputDebugString(L"\n");

        ViewPanelGroupsControl().ItemsSource(viewPanelGroups);

        OutputDebugString(L"=== KeyboardHelper Constructor End ===\n");
    }

    KeyboardHelperViewModel KeyboardHelper::ViewModel()
    {
        return m_viewModel;
    }
}
