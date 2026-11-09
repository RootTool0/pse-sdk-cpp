// pse-sdk-cpp

#pragma once

namespace pse
{
    class PanelElement : public BaseElement
    {
    public:
        enum class EAnimation : uint8_t
        {
            None        = 0,
            Front       = 1,
            FrontFront  = 2,
            FrontBack   = 3,
            Up          = 4,
            UpFront     = 5,
            UpBack      = 6
        };
        
        static PanelElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_PANEL, PanelElement>(InTransform, InState, bVisibility); }
        
        EAnimation GetAnimation() const
        {
            const uint8_t Value = Register::getInt<uint8_t>(GetRegister(0), 0);
            return (Value <= 6) ? static_cast<EAnimation>(Value) : EAnimation::None;
        }
        
        void SetAnimation(const EAnimation InAnimation) const
        {
            PseRegister Register = GetRegister(0);
            Register::setInt<uint8_t>(Register, 0, static_cast<uint8_t>(InAnimation));
            SetRegister(0, Register);
        }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}
