
#pragma once
#include "KeyboardHelper.g.h"
#include "KeyboardHelperViewModel.h"
#include "BooleanToVisibilityConverter.h"

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct KeyboardHelper :
        KeyboardHelperT<KeyboardHelper>
    {
    private:
        KeyboardHelperViewModel m_viewModel;
    public:
        KeyboardHelper();
        KeyboardHelperViewModel ViewModel();
    };
}
namespace winrt::SamsungNotes::UI::Controls::factory_implementation
{
    struct KeyboardHelper :
        KeyboardHelperT<
        KeyboardHelper,
        implementation::KeyboardHelper>
    {
    };
}