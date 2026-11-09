// pse-sdk-cpp

#pragma once

namespace pse
{
    class AntiExpropriationFieldElement : public BaseElement
    {
    public:
        enum class ESolverGunMode : uint8_t
        {
            None    = 0,
            Switch  = 1,
            Enable  = 2,
            Disable = 3,
            Release = 4
        };
        
        static AntiExpropriationFieldElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_ANTI_EXPROPRIATION_FIELD, AntiExpropriationFieldElement>(InTransform, InState, bVisibility); }
        
        ESolverGunMode GetSolverGunMode() const
        {
            const uint8_t Value = Register::getBitsAs<uint8_t, 4>(GetRegister(0), 2);
            return (Value <= 4) ? static_cast<ESolverGunMode>(Value) : ESolverGunMode::None;
        }
        
        void SetSolverGunMode(const ESolverGunMode InMode) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 4>(Register, 2, static_cast<uint8_t>(InMode));
            SetRegister(0, Register);
        }
        
        bool GetKillPlayer() const { return (GetRegister(0) & 0x2) != 0; }
        void SetKillPlayer(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x2) : (Register & ~0x2)); }
        
        bool GetDestroyObjects() const { return (GetRegister(0) & 0x1) != 0; }
        void SetDestroyObjects(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColor() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColor(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        int16_t GetWidth() const  { return Private::UnpackLowInt16(GetRegister(2)); }
        int16_t GetHeight() const { return Private::UnpackHighInt16(GetRegister(2)); }
        
        void SetWidth(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(2);
            SetRegister(2, Private::PackInt16(InValue, Private::UnpackHighInt16(Register)));
        }
        
        void SetHeight(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(2);
            SetRegister(2, Private::PackInt16(Private::UnpackLowInt16(Register), InValue));
        }
    };
}
