// pse-sdk-cpp

#pragma once

namespace pse
{
    class FaithPlateElement : public BaseElement
    {
    public:
        static FaithPlateElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_FAITH_PLATE, FaithPlateElement>(InTransform, InState, bVisibility); }
        
        bool GetReleaseOnLanding() const { return (GetRegister(0) & 0x2) != 0; }
        void SetReleaseOnLanding(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x2) : (Register & ~0x2)); }
        
        bool GetUseGlobalCoordinates() const { return (GetRegister(0) & 0x1) != 0; }
        void SetUseGlobalCoordinates(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
        
        int16_t GetTargetX() const { return Private::UnpackLowInt16(GetRegister(3)); }
        int16_t GetTargetY() const { return Private::UnpackHighInt16(GetRegister(3)); }
        int16_t GetTargetZ() const { return Private::UnpackLowInt16(GetRegister(4)); }
        int16_t GetHeight()  const { return Private::UnpackHighInt16(GetRegister(4)); }
        
        void SetTargetX(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(3);
            SetRegister(3, Private::PackInt16(InValue, Private::UnpackHighInt16(Register)));
        }
        
        void SetTargetY(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(3);
            SetRegister(3, Private::PackInt16(Private::UnpackLowInt16(Register), InValue));
        }
        
        void SetTargetZ(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(4);
            SetRegister(4, Private::PackInt16(InValue, Private::UnpackHighInt16(Register)));
        }
        
        void SetHeight(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(4);
            SetRegister(4, Private::PackInt16(Private::UnpackLowInt16(Register), InValue));
        }
    };
}
