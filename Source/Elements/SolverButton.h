// pse-sdk-cpp

#pragma once

namespace pse
{
    class SolverButtonElement : public BaseElement
    {
    public:
        enum class EButtonType : uint8_t
        {
            Switch  = 0,
            Click   = 1,
            Timer   = 2,
            Once    = 3
        };
        
        static SolverButtonElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_SOLVER_BUTTON, SolverButtonElement>(InTransform, InState, bVisibility); }
        
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
        
        bool GetFlatModel() const { return (GetRegister(0) & 0x200) != 0; }
        void SetFlatModel(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x200) : (Register & ~0x200)); }
        
        bool GetCallbackGreenHighlight() const { return (GetRegister(0) & 0x400) != 0; }
        void SetCallbackGreenHighlight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x400) : (Register & ~0x400)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}
