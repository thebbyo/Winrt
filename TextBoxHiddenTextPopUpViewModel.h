#pragma once
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.UI.Xaml.h>
#include <functional>

struct TextBoxHiddenTextPopUpViewModel
{
    // Property to control grid visibility
    bool IsGridVisible{ true };

    // Text property that can be bound to the TextBox
    winrt::hstring TextContent{ L"Sample text content goes here. This demonstrates the popup UI design with scrollable text content." };

    // Callback function pointer for hiding the popup
    std::function<void()> OnHidePopup;

    // Method called when OK button is clicked
    void OnOkButtonClicked()
    {
        // Hide the grid
        IsGridVisible = false;

        // Notify the view to hide the popup
        if (OnHidePopup)
        {
            OnHidePopup();
        }
    }

    // Optional: Method to set the text content
    void SetTextContent(winrt::hstring const& text)
    {
        TextContent = text;
    }

    // Optional: Method to show the popup (for reuse)
    void ShowPopup()
    {
        IsGridVisible = true;
    }
};
