#include "pch.h"
#include "EyedropperToolbar.xaml.h"
#if __has_include("EyedropperToolbar.g.cpp")
#include "EyedropperToolbar.g.cpp"
#endif

#include "winrt/Microsoft.UI.Xaml.Input.h"
#include "winrt/Microsoft.UI.Input.h"
using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Input;


namespace winrt::SamsungNotes::UI::Controls::implementation
{
    EyedropperToolbar::EyedropperToolbar() {
        InitializeComponent();

        // Connect ViewModel callback to View function
        eyedropperToolbarVM.onHideToolbar = [this]() {
            try {
                auto controller = FloatingController();
                if (controller) {
                    // Move off-screen instead of just hiding to see if callback is working
                    winrt::Microsoft::UI::Xaml::Controls::Canvas::SetLeft(controller, -1000);
                    winrt::Microsoft::UI::Xaml::Controls::Canvas::SetTop(controller, -1000);
                }
            }
            catch (...) {
                // Handle any exceptions that might occur
            }
            };
    }


    void EyedropperToolbar::DragHandle_PointerPressed(
        winrt::Windows::Foundation::IInspectable const& sender,
        PointerRoutedEventArgs const& e)
    {
        auto point = e.GetCurrentPoint(RootCanvas());

        eyedropperToolbarVM.onPointerPressed(
            point.Position(),
            point.Properties().IsRightButtonPressed(),
            point.Properties().IsMiddleButtonPressed());

        auto handle = sender.as<UIElement>();
        handle.CapturePointer(e.Pointer());
    }

    void EyedropperToolbar::DragHandle_PointerMoved(
        winrt::Windows::Foundation::IInspectable const& sender,
        PointerRoutedEventArgs const& e)
    {
        if (!eyedropperToolbarVM.mTouchDown)
            return;

        auto point = e.GetCurrentPoint(RootCanvas());

        eyedropperToolbarVM.onPointerMoved(
            point.Position(),
            RootCanvas().ActualWidth(),
            RootCanvas().ActualHeight()
        );
        winrt::Microsoft::UI::Xaml::Controls::Canvas::SetLeft(FloatingController(), eyedropperToolbarVM.left);
        winrt::Microsoft::UI::Xaml::Controls::Canvas::SetTop(FloatingController(), eyedropperToolbarVM.top);
    }

    void EyedropperToolbar::DragHandle_PointerReleased(
        winrt::Windows::Foundation::IInspectable const& sender,
        PointerRoutedEventArgs const& e)
    {
        eyedropperToolbarVM.onPointerReleased();

        auto handle = sender.as<UIElement>();
        handle.ReleasePointerCapture(e.Pointer());
    }

    void EyedropperToolbar::Remove_Click(
        winrt::Windows::Foundation::IInspectable const& sender,
        winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        // Hide the toolbar
        FloatingController().Visibility(winrt::Microsoft::UI::Xaml::Visibility::Collapsed);

        // Or collapse the entire user control
        // this->Visibility(winrt::Microsoft::UI::Xaml::Visibility::Collapsed);
    }

}