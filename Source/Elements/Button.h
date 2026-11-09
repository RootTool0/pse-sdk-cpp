// pse-sdk-cpp

#pragma once

namespace pse
{
    class ButtonElement : public BaseElement
    {
    public:
        static ButtonElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_BUTTON, ButtonElement>(InTransform, InState, bVisibility); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}
