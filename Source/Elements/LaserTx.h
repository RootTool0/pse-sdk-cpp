// pse-sdk-cpp

#pragma once

namespace pse
{
    class LaserTxElement : public BaseElement
    {
    public:
        static LaserTxElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_LASER_TX, LaserTxElement>(InTransform, InState, bVisibility); }
        
        bool GetModelShiftedDown() const { return (GetRegister(0) & 0x1) != 0; }
        void SetModelShiftedDown(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetLaserColor() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetLaserColor(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
    };
}
