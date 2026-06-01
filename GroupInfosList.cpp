#pragma once
#include "GroupInfosList.g.h"
#include "KeyboardShortcut.h"

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct GroupInfosList : GroupInfosListT<GroupInfosList>
    {
    private:
        hstring m_key{};
        Windows::Foundation::Collections::IVector<KeyboardShortcut> m_items =
            winrt::single_threaded_vector<KeyboardShortcut>();

    public:
        GroupInfosList();

        hstring Key();
        void Key(hstring const& value);

        Windows::Foundation::Collections::IVector<KeyboardShortcut> Items();

        void Add(KeyboardShortcut const& item);
    };
}
