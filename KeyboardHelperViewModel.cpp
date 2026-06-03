
#include "pch.h"
#include "KeyboardHelperViewModel.h"
#include "winrt/SamsungNotes.UI.Controls.h"
using namespace winrt::SamsungNotes::UI::Controls;
namespace winrt::SamsungNotes::UI::Controls::implementation
{
    KeyboardHelperViewModel::KeyboardHelperViewModel()
    {
        // ===== Note Text Edit Shortcuts (left column) =====
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Select next button", L"Tab", L"", L"", L"", KeyboardShortcutHelperCategory::General));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Select previous button", L"Shift", L"Tab", L"", L"", KeyboardShortcutHelperCategory::General));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Add page", L"Ctrl", L"N", L"", L"", KeyboardShortcutHelperCategory::NoteEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Create new note", L"Ctrl", L"N", L"", L"", KeyboardShortcutHelperCategory::NoteEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Create text box", L"Ctrl", L"Shift", L"T", L"", KeyboardShortcutHelperCategory::NoteEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Strikethrough", L"Ctrl", L"/", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Bold", L"Ctrl", L"B", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Italic", L"Ctrl", L"I", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Underline", L"Ctrl", L"U", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Align center", L"Ctrl", L"E", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Align left", L"Ctrl", L"L", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Align right", L"Ctrl", L"R", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Numbered list", L"Ctrl", L"Shift", L"7", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Bullets", L"Ctrl", L"Shift", L"8", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"To-do", L"Ctrl", L"Shift", L"C", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Decrease font size", L"Ctrl", L"[", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Increase font size", L"Ctrl", L"]", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Indent", L"Ctrl", L"M", L"", L"", KeyboardShortcutHelperCategory::TextEditShortcut));
        m_noteTextEditShortcuts.Append(KeyboardShortcut(L"Outdent", L"Ctrl", L"Shift", L"M", L"", KeyboardShortcutHelperCategory::TextEditShortcut));

         //===== View Panel Control Shortcuts (right column) =====
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Zoom In", L"Ctrl", L"+", L"", L"", KeyboardShortcutHelperCategory::ViewControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Zoom Out", L"Ctrl", L"-", L"", L"", KeyboardShortcutHelperCategory::ViewControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Zoom In/Out", L"Ctrl", L"Mouse wheel scroll", L"", L"", KeyboardShortcutHelperCategory::ViewControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Pen settings lock", L"Ctrl", L"Alt", L"L", L"", KeyboardShortcutHelperCategory::ViewControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Switch to editing mode", L"Enter", L"", L"", L"", KeyboardShortcutHelperCategory::ViewControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Read only mode on/off", L"Alt", L"Enter", L"", L"", KeyboardShortcutHelperCategory::ViewControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Full screen view on/off", L"Alt", L"F", L"", L"", KeyboardShortcutHelperCategory::ViewControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Show pen settings", L"Ctrl", L"T", L"", L"", KeyboardShortcutHelperCategory::PanelControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Open/Close page settings", L"Alt", L"P", L"", L"", KeyboardShortcutHelperCategory::PanelControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Expand/Shrink audio controls", L"Alt", L"R", L"", L"", KeyboardShortcutHelperCategory::PanelControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Play/Pause audio file", L"Ctrl", L"'", L"", L"", KeyboardShortcutHelperCategory::PanelControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Jump back 10 seconds", L"Ctrl", L",", L"", L"", KeyboardShortcutHelperCategory::PanelControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Jump forward 10 seconds", L"Ctrl", L".", L"", L"", KeyboardShortcutHelperCategory::PanelControlShortcut));
        m_noteViewPanelControlShortcuts.Append(KeyboardShortcut(L"Print note", L"Ctrl", L"Shift", L"P", L"", KeyboardShortcutHelperCategory::PanelControlShortcut));
    }

    hstring KeyboardHelperViewModel::KeyboardHelperHeader()
    {
        return m_header;
    }

    winrt::Windows::Foundation::Collections::
        IObservableVector<
        KeyboardShortcut>
        KeyboardHelperViewModel::NoteTextEditShortcuts()
    {
        return m_noteTextEditShortcuts;
    }

    winrt::Windows::Foundation::Collections::
        IObservableVector<
        KeyboardShortcut>
        KeyboardHelperViewModel::NoteViewPanelControlShortcuts()
    {
        return m_noteViewPanelControlShortcuts;
    }
}