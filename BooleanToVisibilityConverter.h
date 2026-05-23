#pragma once
#include "winrt/Microsoft.UI.Xaml.Data.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.Foundation.h"

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct BooleanToVisibilityConverter : winrt::implements<BooleanToVisibilityConverter, winrt::Microsoft::UI::Xaml::Data::IValueConverter>
    {
        BooleanToVisibilityConverter() = default;

        winrt::Windows::Foundation::IInspectable Convert(
            winrt::Windows::Foundation::IInspectable const& value,
            winrt::Windows::UI::Xaml::Interop::TypeName const& targetType,
            winrt::Windows::Foundation::IInspectable const& parameter,
            hstring const& language);

        winrt::Windows::Foundation::IInspectable ConvertBack(
            winrt::Windows::Foundation::IInspectable const& value,
            winrt::Windows::UI::Xaml::Interop::TypeName const& targetType,
            winrt::Windows::Foundation::IInspectable const& parameter,
            hstring const& language);
    };
}
