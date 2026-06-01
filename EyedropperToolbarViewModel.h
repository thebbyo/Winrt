#pragma once
#include <winrt/Windows.Foundation.h>
#include <functional>
struct EyedropperToolbarViewModel
{
    bool mTouchDown{ false };
    bool isPointerPressed{ false };

    double left{ 20 };
    double top{ 20 };

    double width{ 146 };
    double height{ 45 };

    winrt::Windows::Foundation::Point lastPoint;
    // Add callback function pointer
    std::function<void()> onHideToolbar;

    // In onRemoveButtonClicked(), add at the end:


    void onPointerPressed(
        winrt::Windows::Foundation::Point const& p,
        bool isRight,
        bool isMiddle)
    {
        if (isRight || isMiddle)
        {
            mTouchDown = false;
        }
        else
        {
            mTouchDown = true;
            lastPoint = p;
        }

        isPointerPressed = true;
    }

    void onPointerMoved(
        winrt::Windows::Foundation::Point const& p,
        double canvasWidth,
        double canvasHeight)
    {
        if (!mTouchDown)
            return;

        double dx = p.X - lastPoint.X;
        double dy = p.Y - lastPoint.Y;

        left += dx;
        top += dy;

        if (left < 0) left = 0;
        if (top < 0) top = 0;
        if (left + width > canvasWidth) left = canvasWidth - width;
        if (top + height > canvasHeight) top = canvasHeight - height;

        lastPoint = p;
    }

    void onPointerReleased()
    {
        isPointerPressed = false;
        mTouchDown = false;
    }
    void onRemoveButtonClicked() {
        // Set debug flag

        // Reset the toolbar state
        mTouchDown = false;
        isPointerPressed = false;

        // Reset position to default (optional)
        left = 20;
        top = 20;

        // Clear the last point
        lastPoint = winrt::Windows::Foundation::Point(0, 0);

        if (onHideToolbar) {
            onHideToolbar();  // This will call the View's hide function
        }
    }

};