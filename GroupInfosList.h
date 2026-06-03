#pragma once
#include "GroupInfosList.g.h"
#include "KeyboardShortcut.h"

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct GroupInfosList : GroupInfosListT<GroupInfosList>
    {
    private:
        hstring m_key{};
        Windows::Foundation::Collections::IVector<winrt::SamsungNotes::UI::Controls::KeyboardShortcut> m_items{};

    public:
        GroupInfosList();

        hstring Key();
        void Key(hstring const& value);

        Windows::Foundation::Collections::IVector<winrt::SamsungNotes::UI::Controls::KeyboardShortcut> Items();

        void Add(winrt::SamsungNotes::UI::Controls::KeyboardShortcut const& item);
        void RemoveAt(uint32_t index);
        void Clear();
        uint32_t Size();
    };
}

namespace winrt::SamsungNotes::UI::Controls::factory_implementation
{
    struct GroupInfosList : GroupInfosListT<GroupInfosList, implementation::GroupInfosList>
    {
    };
}
