// pse-sdk-cpp

#pragma once

namespace pse
{
    class PedestalButtonElement : public BaseElement
    {
    public:
        enum class EButtonType : uint8_t
        {
            Switch  = 0,
            Click   = 1,
            Timer   = 2,
            Once    = 3
        };
        
        static PedestalButtonElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_PEDESTAL_BUTTON, PedestalButtonElement>(InTransform, InState, bVisibility); }
        
        EButtonType GetButtonType() const { return static_cast<EButtonType>(Register::getBitsAs<uint8_t, 2>(GetRegister(0), 0)); }
        void SetButtonType(const EButtonType InButtonType) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 2>(Register, 0, static_cast<uint8_t>(InButtonType));
            SetRegister(0, Register);
        }
        
        uint8_t GetTimerSeconds() const { return Register::getBitsAs<uint8_t, 7>(GetRegister(0), 2); }
        void SetTimerSeconds(const uint8_t InSeconds) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 7>(Register, 2, InSeconds);
            SetRegister(0, Register);
        }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}
