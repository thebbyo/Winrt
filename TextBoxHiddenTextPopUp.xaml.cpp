#include "pch.h"
#include "TextBoxHiddenTextPopUp.xaml.h"
#if __has_include("TextBoxHiddenTextPopUp.g.cpp")
#include "TextBoxHiddenTextPopUp.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Input;
using namespace winrt::SamsungNotes::UI::Controls::implementation;

namespace winrt::SamsungNotes::UI::Controls::implementation
{
    TextBoxHiddenTextPopUp::TextBoxHiddenTextPopUp()
    {
        InitializeComponent();

        // Set up the callback in the ViewModel
        m_viewModel.OnHidePopup = [this]()
            {
                HidePopup();
            };

        // Bind ViewModel to XAML if using data binding
        // DataContext(box_value(m_viewModel));
    }

    TextBoxHiddenTextPopUpViewModel TextBoxHiddenTextPopUp::ViewModel()
    {
        return m_viewModel;
    }

    void TextBoxHiddenTextPopUp::HidePopup()
    {
        // Find the AllTextGrid by name and set its visibility
        if (auto grid = FindName(L"AllTextGrid").try_as<Grid>())
        {
            grid.Visibility(Visibility::Collapsed);
        }

        // Alternative: If this control is inside a Popup, you can hide the popup
        // if (auto popup = this->try_as<Popup>())
        // {
        //     popup.IsOpen(false);
        // }
    }
    void TextBoxHiddenTextPopUp::OnOkButtonClick(IInspectable const& sender, RoutedEventArgs const& e)
    {
        m_viewModel.OnOkButtonClicked();
    }

}
