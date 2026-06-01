#pragma once
#include "KeyboardHelper.g.h"
#include "KeyboardHelperViewModel.h"

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct KeyboardHelper : KeyboardHelperT<KeyboardHelper>
    {
        KeyboardHelper();

        KeyboardHelperViewModel ViewModel();

    private:
        KeyboardHelperViewModel m_viewModel;
    };
}

namespace winrt::SamsungNotes::UI::Controls::factory_implementation
{
    struct KeyboardHelper : KeyboardHelperT<KeyboardHelper, implementation::KeyboardHelper> {};
}
