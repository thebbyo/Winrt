#include "pch.h"
#include "KeyboardShortcut.h"
#include "KeyboardShortcut.g.cpp"

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    KeyboardShortcut::KeyboardShortcut(
        hstring const& funcName,
        hstring const& shortcutKey1,
        hstring const& shortcutKey2,
        hstring const& shortcutKey3,
        hstring const& shortcutKey4,
        KeyboardShortcutHelperCategory const& helperCategory
        )
        : m_funcName(funcName)
        , m_shortcutKey1(shortcutKey1)
        , m_shortcutKey2(shortcutKey2)
        , m_shortcutKey3(shortcutKey3)
        , m_shortcutKey4(shortcutKey4)
        , m_helperCategory(helperCategory)
    {
    }

    hstring KeyboardShortcut::FuncName()
    {
        return m_funcName;
    }

    void KeyboardShortcut::FuncName(hstring const& value)
    {
        m_funcName = value;
    }

    hstring KeyboardShortcut::ShortcutKey1()
    {
        return m_shortcutKey1;
    }

    void KeyboardShortcut::ShortcutKey1(hstring const& value)
    {
        m_shortcutKey1 = value;
    }

    hstring KeyboardShortcut::ShortcutKey2()
    {
        return m_shortcutKey2;
    }

    void KeyboardShortcut::ShortcutKey2(hstring const& value)
    {
        m_shortcutKey2 = value;
    }

    hstring KeyboardShortcut::ShortcutKey3()
    {
        return m_shortcutKey3;
    }

    void KeyboardShortcut::ShortcutKey3(hstring const& value)
    {
        m_shortcutKey3 = value;
    }

    hstring KeyboardShortcut::ShortcutKey4()
    {
        return m_shortcutKey4;
    }

    void KeyboardShortcut::ShortcutKey4(hstring const& value)
    {
        m_shortcutKey4 = value;
    }
    
    KeyboardShortcutHelperCategory KeyboardShortcut::HelperCategory()
    {
        return m_helperCategory;
    }
    
    void KeyboardShortcut::HelperCategory(KeyboardShortcutHelperCategory const& value)
    {
        m_helperCategory = value;
    }
}
