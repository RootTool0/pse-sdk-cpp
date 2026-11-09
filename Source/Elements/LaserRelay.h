// pse-sdk-cpp

#pragma once

namespace pse
{
    class LaserRelayElement : public BaseElement
    {
    public:
        static LaserRelayElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_LASER_RELAY, LaserRelayElement>(InTransform, InState, bVisibility); }
        
        bool GetColorFilterEnabled() const { return (GetRegister(0) & 0x80000000u) != 0; }
        void SetColorFilterEnabled(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x80000000u) : (Register & ~0x80000000u)); }
        
        PseColor GetLaserColor() const { return Private::RegisterToColor(GetRegister(0) & 0x00FFFFFFu); }
        void     SetLaserColor(const PseColor InColor) const { const PseRegister Register = GetRegister(0); SetRegister(0, (Register & 0xFF000000u) | Private::ColorToRegister(InColor)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}
