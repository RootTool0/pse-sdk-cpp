// pse-sdk-cpp

#pragma once

namespace pse
{
    class DoorElement : public BaseElement
    {
    public:
        static DoorElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_DOOR, DoorElement>(InTransform, InState, bVisibility); }
        
        bool GetAutoClose() const { return (GetRegister(0) & 0x2) != 0; }
        void SetAutoClose(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x2) : (Register & ~0x2)); }
        
        bool GetCallbackHighlight() const { return (GetRegister(0) & 0x1) != 0; }
        void SetCallbackHighlight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}
