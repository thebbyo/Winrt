#pragma once

#include "EyedropperToolbar.g.h"
#include "EyedropperToolbarViewModel.h"
namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct EyedropperToolbar : EyedropperToolbarT<EyedropperToolbar>
    {
        EyedropperToolbar();
        EyedropperToolbarViewModel eyedropperToolbarVM;
        void DragHandle_PointerPressed(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e);
        void DragHandle_PointerReleased(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e);
        void DragHandle_PointerMoved(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e);
        void Remove_Click(winrt::Windows::Foundation::IInspectable const& sender,
            winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };

}

namespace winrt::SamsungNotes::UI::Controls::factory_implementation
{
    struct EyedropperToolbar : EyedropperToolbarT<EyedropperToolbar, implementation::EyedropperToolbar>
    {
    };
}