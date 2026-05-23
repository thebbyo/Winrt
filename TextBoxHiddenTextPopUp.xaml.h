#pragma once

#include "TextBoxHiddenTextPopUpViewModel.h"
#include "TextBoxHiddenTextPopUp.g.h"
using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Controls;
namespace winrt::SamsungNotes::UI::Controls::implementation
{
    struct TextBoxHiddenTextPopUp : TextBoxHiddenTextPopUpT<TextBoxHiddenTextPopUp>
    {
        TextBoxHiddenTextPopUp();

        // ViewModel instance
        TextBoxHiddenTextPopUpViewModel ViewModel();

        // Method to hide the popup
        void HidePopup();
        void OnOkButtonClick(IInspectable const& sender, RoutedEventArgs const& e);

        

    private:
        TextBoxHiddenTextPopUpViewModel m_viewModel;
    };
}

namespace winrt::SamsungNotes::UI::Controls::factory_implementation
{
    struct TextBoxHiddenTextPopUp : TextBoxHiddenTextPopUpT<TextBoxHiddenTextPopUp, winrt::SamsungNotes::UI::Controls::implementation::TextBoxHiddenTextPopUp>
    {
    };
}
