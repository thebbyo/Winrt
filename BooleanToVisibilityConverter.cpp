#include "pch.h"
#include "BooleanToVisibilityConverter.h"

using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Interop;
using namespace winrt::Windows::Foundation;

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    winrt::Windows::Foundation::IInspectable BooleanToVisibilityConverter::Convert(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language)
    {
        // Handle string values: non-empty string -> Visible, empty string -> Collapsed
        auto stringVal = value.try_as<hstring>();
        if (stringVal)
        {
            bool hasContent = !stringVal->empty();
            Visibility visibility = hasContent ? Visibility::Visible : Visibility::Collapsed;
            return winrt::box_value(visibility);
        }

        // Handle boolean values (original behavior)
        bool flag = winrt::unbox_value_or<bool>(value, false);
        Visibility visibility = flag ? Visibility::Visible : Visibility::Collapsed;
        return winrt::box_value(visibility);
    }

    winrt::Windows::Foundation::IInspectable BooleanToVisibilityConverter::ConvertBack(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language)
    {
        Visibility visibility = winrt::unbox_value_or<Visibility>(value, Visibility::Collapsed);
        bool flag = (visibility == Visibility::Visible);
        return winrt::box_value(flag);
    }
}
