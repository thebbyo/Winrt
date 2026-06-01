
#include "pch.h"
#include "KeyboardHelper.xaml.h"
#include "KeyboardHelper.g.cpp"
using namespace winrt;
using namespace Microsoft::UI::Xaml;
namespace winrt::SamsungNotes::UI::Controls::implementation
{
    KeyboardHelper::KeyboardHelper()
    {
        // Register the BooleanToVisibilityConverter as a resource so the DataTemplate
        // can reference it via {StaticResource BooleanToVisibilityConverter}
        auto converter = winrt::make<winrt::SamsungNotes::UI::Controls::implementation::BooleanToVisibilityConverter>();
        this->Resources().Insert(winrt::box_value(L"BooleanToVisibilityConverter"), converter);

        InitializeComponent();
        m_viewModel = KeyboardHelperViewModel();

        // Set CollectionViewSource sources from code-behind since the ViewModel
        // is a plain C++ struct (not a WinRT runtime class) and cannot be used
        // as a DataContext for {Binding} in XAML.
        auto noteTextEditSource = this->Resources().Lookup(winrt::box_value(L"NoteTextEditKeyboardHelperSource"))
            .as<winrt::Microsoft::UI::Xaml::Data::CollectionViewSource>();
        noteTextEditSource.Source(m_viewModel.NoteTextEditShortcuts());

        auto viewPanelControlSource = this->Resources().Lookup(winrt::box_value(L"ViewPanelControlKeyboardHelperSource"))
            .as<winrt::Microsoft::UI::Xaml::Data::CollectionViewSource>();
        viewPanelControlSource.Source(m_viewModel.NoteViewPanelControlShortcuts());
    }
    KeyboardHelperViewModel
        KeyboardHelper::ViewModel()
    {
        return m_viewModel;
    }
}