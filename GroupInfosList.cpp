#include "pch.h"
#include "GroupInfosList.h"
#include "GroupInfosList.g.cpp"

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    GroupInfosList::GroupInfosList()
    {
        m_items = winrt::single_threaded_vector<winrt::SamsungNotes::UI::Controls::KeyboardShortcut>();
    }

    hstring GroupInfosList::Key()
    {
        return m_key;
    }

    void GroupInfosList::Key(hstring const& value)
    {
        m_key = value;
    }

    Windows::Foundation::Collections::IVector<winrt::SamsungNotes::UI::Controls::KeyboardShortcut> GroupInfosList::Items()
    {
        return m_items;
    }

    void GroupInfosList::Add(winrt::SamsungNotes::UI::Controls::KeyboardShortcut const& item)
    {
        m_items.Append(item);
    }

    void GroupInfosList::RemoveAt(uint32_t index)
    {
        m_items.RemoveAt(index);
    }

    void GroupInfosList::Clear()
    {
        m_items.Clear();
    }

    uint32_t GroupInfosList::Size()
    {
        return m_items.Size();
    }
}
