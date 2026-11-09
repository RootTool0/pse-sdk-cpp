// pse-sdk-cpp

#pragma once

namespace pse
{
    class WindowElement : public BaseElement
    {
    public:
        static WindowElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_WINDOW, WindowElement>(InTransform, InState, bVisibility); }
        
        PseMaterial GetCentralMaterial() const { return Register::getInt<PseMaterial>(GetRegister(0), 16); }
        void SetCentralMaterial(const PseMaterial InMaterial) const
        {
            PseRegister Register = GetRegister(0);
            Register::setInt<PseMaterial>(Register, 16, InMaterial);
            SetRegister(0, Register);
        }
        
        bool GetShowBottomRight() const { return (GetRegister(0) & 0x0100) != 0; }
        void SetShowBottomRight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0100) : (Register & ~0x0100)); }
        
        bool GetShowBottomLeft() const { return (GetRegister(0) & 0x0080) != 0; }
        void SetShowBottomLeft(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0080) : (Register & ~0x0080)); }
        
        bool GetShowTopRight() const { return (GetRegister(0) & 0x0040) != 0; }
        void SetShowTopRight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0040) : (Register & ~0x0040)); }
        
        bool GetShowTopLeft() const { return (GetRegister(0) & 0x0020) != 0; }
        void SetShowTopLeft(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0020) : (Register & ~0x0020)); }
        
        bool GetShowRight() const { return (GetRegister(0) & 0x0010) != 0; }
        void SetShowRight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0010) : (Register & ~0x0010)); }
        
        bool GetShowLeft() const { return (GetRegister(0) & 0x0008) != 0; }
        void SetShowLeft(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0008) : (Register & ~0x0008)); }
        
        bool GetShowBottom() const { return (GetRegister(0) & 0x0004) != 0; }
        void SetShowBottom(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0004) : (Register & ~0x0004)); }
        
        bool GetShowTop() const { return (GetRegister(0) & 0x0002) != 0; }
        void SetShowTop(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0002) : (Register & ~0x0002)); }
        
        bool GetShowCenter() const { return (GetRegister(0) & 0x0001) != 0; }
        void SetShowCenter(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0001) : (Register & ~0x0001)); }
        
        bool GetPassSolverRays() const { return (GetRegister(0) & 0x0200) != 0; }
        void SetPassSolverRays(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0200) : (Register & ~0x0200)); }
        
        bool GetPassLaserRays() const { return (GetRegister(0) & 0x0400) != 0; }
        void SetPassLaserRays(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0400) : (Register & ~0x0400)); }
        
        uint16_t GetWidth() const  { return Private::UnpackLowUInt16(GetRegister(1)); }
        uint16_t GetHeight() const { return Private::UnpackHighUInt16(GetRegister(1)); }
        
        void SetWidth(const uint16_t InWidth) const
        {
            const PseRegister Register = GetRegister(1);
            SetRegister(1, Private::PackUInt16(InWidth, Private::UnpackHighUInt16(Register)));
        }
        
        void SetHeight(const uint16_t InHeight) const
        {
            const PseRegister Register = GetRegister(1);
            SetRegister(1, Private::PackUInt16(Private::UnpackLowUInt16(Register), InHeight));
        }
    };
}
