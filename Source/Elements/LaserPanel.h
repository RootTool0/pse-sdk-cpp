// pse-sdk-cpp

#pragma once

namespace pse
{
    class LaserPanelElement : public BaseElement
    {
    public:
        static LaserPanelElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_LASER_PANEL, LaserPanelElement>(InTransform, InState, bVisibility); }
        
        bool GetActiveVisual() const { return (GetRegister(0) & 0x40000000u) != 0; }
        void SetActiveVisual(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x40000000u) : (Register & ~0x40000000u)); }
        
        uint8_t GetMaxAngle() const { return Register::getBitsAs<uint8_t, 8>(GetRegister(0), 16); }
        void SetMaxAngle(const uint8_t InDegrees) const
        {
            const uint8_t Clamped = (InDegrees > 180) ? 180 : InDegrees;
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 8>(Register, 16, Clamped);
            SetRegister(0, Register);
        }
        
        uint8_t GetMinAngle() const
        {
            const uint8_t Value = Register::getBitsAs<uint8_t, 8>(GetRegister(0), 8);
            const uint8_t Max   = GetMaxAngle();
            return (Value > Max) ? Max : Value;
        }
        void SetMinAngle(const uint8_t InDegrees) const
        {
            const uint8_t Max     = GetMaxAngle();
            const uint8_t Clamped = (InDegrees > Max) ? Max : ((InDegrees > 180) ? 180 : InDegrees);
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 8>(Register, 8, Clamped);
            SetRegister(0, Register);
        }
        
        uint8_t GetAngle() const
        {
            const uint8_t Value = Register::getBitsAs<uint8_t, 8>(GetRegister(0), 0);
            const uint8_t Min   = GetMinAngle();
            const uint8_t Max   = GetMaxAngle();
            return (Value < Min) ? Min : ((Value > Max) ? Max : Value);
        }
        void SetAngle(const uint8_t InDegrees) const
        {
            const uint8_t Min     = GetMinAngle();
            const uint8_t Max     = GetMaxAngle();
            const uint8_t Clamped = (InDegrees < Min) ? Min : ((InDegrees > Max) ? Max : InDegrees);
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 8>(Register, 0, Clamped);
            SetRegister(0, Register);
        }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}
