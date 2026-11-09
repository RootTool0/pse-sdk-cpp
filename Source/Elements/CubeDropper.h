// pse-sdk-cpp

#pragma once

namespace pse
{
    class CubeDropperElement : public BaseElement
    {
    public:
        enum class ECubeType : uint8_t
        {
            WeightCube  = 0,
            LaserCube   = 1
        };
        
        static CubeDropperElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_CUBE_DROPPER, CubeDropperElement>(InTransform, InState, bVisibility); }
        
        bool GetRespawnOnDestroy() const { return (GetRegister(0) & 0x10) != 0; }
        void SetRespawnOnDestroy(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x10) : (Register & ~0x10)); }
        
        ECubeType GetCubeType() const
        {
            const uint8_t Value = Register::getBitsAs<uint8_t, 4>(GetRegister(0), 0);
            return (Value <= 1) ? static_cast<ECubeType>(Value) : ECubeType::WeightCube;
        }
        
        void SetCubeType(const ECubeType InCubeType) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 4>(Register, 0, static_cast<uint8_t>(InCubeType));
            SetRegister(0, Register);
        }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}
