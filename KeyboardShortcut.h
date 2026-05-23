#pragma once
#include "KeyboardShortcut.g.h"

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct KeyboardShortcut : KeyboardShortcutT<KeyboardShortcut>
    {
    private:
        hstring m_funcName{};
        hstring m_shortcutKey1{};
        hstring m_shortcutKey2{};
        hstring m_shortcutKey3{};
        hstring m_shortcutKey4{};
        KeyboardShortcutHelperCategory m_helperCategory{};

    public:
        KeyboardShortcut() = default;
        
        KeyboardShortcut(hstring const& funcName, 
                        hstring const& shortcutKey1,
                        hstring const& shortcutKey2,
                        hstring const& shortcutKey3,
                        hstring const& shortcutKey4,
                        KeyboardShortcutHelperCategory const& helperCategory = {}
            );

        hstring FuncName();
        void FuncName(hstring const& value);
        
        hstring ShortcutKey1();
        void ShortcutKey1(hstring const& value);
        
        hstring ShortcutKey2();
        void ShortcutKey2(hstring const& value);
        
        hstring ShortcutKey3();
        void ShortcutKey3(hstring const& value);
        
        hstring ShortcutKey4();
        void ShortcutKey4(hstring const& value);
        
        KeyboardShortcutHelperCategory HelperCategory();
        void HelperCategory(KeyboardShortcutHelperCategory const& value);
    };
}

namespace winrt::SamsungNotes::UI::Controls::factory_implementation
{
    struct KeyboardShortcut : KeyboardShortcutT<KeyboardShortcut, implementation::KeyboardShortcut>
    {
    };
}
