// pse-sdk-cpp

#pragma once

namespace pse
{
    class BaseElement
    {
        
    public:
        BaseElement() = default;
        BaseElement(const PseGUID InGUID) : GUID(InGUID) {}
        
        PseGUID GetGUID() const { return GUID; }
        bool IsValidGUID() const { return GetGUID() != -1; }
        
        void SetTransform(const PseTransform& InTransform) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::SetTransform: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_SET_TRANSFORM;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseTransform>(Cmd, InTransform);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::SetTransform failed: 0x%X", Cmd.header);
        }
        
        PseTransform GetTransform() const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::GetTransform: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_GET_TRANSFORM;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::GetTransform failed: 0x%X", Cmd.header);
            
            return Data::get<0, PseTransform>(Cmd);
        }
        
        void SetVisibility(const bool bVisibility) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::SetVisibility: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_SET_VISIBILITY;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, int8_t>(Cmd, bVisibility ? 1 : 0);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::SetVisibility failed: 0x%X", Cmd.header);
        }
        
        bool GetVisibility() const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::GetVisibility: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_GET_VISIBILITY;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::GetVisibility failed: 0x%X", Cmd.header);
            
            return Data::get<0, int8_t>(Cmd) != 0;
        }
        
        void SetState(const PseState InState) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::SetState: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_SET_STATE;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseState>(Cmd, InState);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::SetState failed: 0x%X", Cmd.header);
        }
        
        PseState GetState() const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::GetState: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_GET_STATE;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::GetState failed: 0x%X", Cmd.header);
            
            return Data::get<0, PseState>(Cmd);
        }
        
        void SetCallback(const PseCallback InCallback) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::SetCallback: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_SET_CALLBACK;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseCallback>(Cmd, InCallback);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::SetCallback failed: 0x%X", Cmd.header);
        }
        
        PseCallback GetCallback() const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::GetCallback: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_GET_CALLBACK;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::GetCallback failed: 0x%X", Cmd.header);
            
            return Data::get<0, PseCallback>(Cmd);
        }
        
        PseRegister GetRegister(const int Index) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::GetRegister: Element is not Valid! (GUID == -1)");
            PSE_ASSERT(Index >= 0 && Index <= 7, "pse::BaseElement::GetRegister: Index %d out of range [0,7]", Index);
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_GET_REGISTER;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, int8_t>(Cmd, static_cast<int8_t>(Index));
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::GetRegister failed: 0x%X", Cmd.header);
            
            return Data::get<0, PseRegister>(Cmd);
        }
        
        void SetRegister(const int Index, const PseRegister InRegister) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::SetRegister: Element is not Valid! (GUID == -1)");
            PSE_ASSERT(Index >= 0 && Index <= 7, "pse::BaseElement::SetRegister: Index %d out of range [0,7]", Index);
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_SET_REGISTER;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseRegister>(Cmd, InRegister);
            Data::set<16, int8_t>(Cmd, static_cast<int8_t>(Index));
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::SetRegister failed: 0x%X", Cmd.header);
        }
        
        void Destroy() const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::Destroy: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_DESTROY;
            Data::set<0, PseGUID>(Cmd, GUID);
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::Destroy failed: 0x%X", Cmd.header);
        }
        
    private:
        PseGUID GUID = -1;
    };
    
    namespace Private
    {
        template<PseClass TPseClass, typename TElement>
        static TElement CreateElement(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true)
        {
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_CREATE;
            Data::set<0, PseTransform>(Cmd, InTransform);
            Data::set<40, PseClass>(Cmd, TPseClass);
            Data::set<42, PseCallback>(Cmd, 0);
            Data::set<50, PseState>(Cmd, InState);
            Data::set<51, int8_t>(Cmd, bVisibility ? 1 : 0);
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Private::TypedElement<0x%X>::Create failed: 0x%X", TPseClass, Cmd.header);
            
            return TElement{ Data::get<0, PseGUID>(Cmd) };
        }
    	
        inline PseRegister ColorToRegister(const PseColor InColor)
        {
            return (static_cast<PseRegister>(InColor.r) << 16) |
                   (static_cast<PseRegister>(InColor.g) << 8)  |
                    static_cast<PseRegister>(InColor.b);
        }
        
        inline PseColor RegisterToColor(const PseRegister InRegister)
        {
            return PseColor
            {
                static_cast<uint8_t>((InRegister >> 16) & 0xFF),
                static_cast<uint8_t>((InRegister >> 8)  & 0xFF),
                static_cast<uint8_t>( InRegister        & 0xFF)
            };
        }
        
        inline PseRegister PackUInt16(const uint16_t InLow, const uint16_t InHigh)
        {
            return  (static_cast<PseRegister>(InLow ) & 0xFFFF) |
                   ((static_cast<PseRegister>(InHigh) & 0xFFFF) << 16);
        }
        
        inline uint16_t UnpackLowUInt16(const PseRegister InRegister)  { return static_cast<uint16_t>( InRegister        & 0xFFFF); }
        inline uint16_t UnpackHighUInt16(const PseRegister InRegister) { return static_cast<uint16_t>((InRegister >> 16) & 0xFFFF); }
        
        inline PseRegister PackInt16(const int16_t InLow, const int16_t InHigh)
        {
            return  (static_cast<PseRegister>(static_cast<uint16_t>(InLow )) & 0xFFFF) |
                   ((static_cast<PseRegister>(static_cast<uint16_t>(InHigh)) & 0xFFFF) << 16);
        }
        
        inline int16_t UnpackLowInt16(const PseRegister InRegister)  { return static_cast<int16_t>(static_cast<uint16_t>( InRegister        & 0xFFFF)); }
        inline int16_t UnpackHighInt16(const PseRegister InRegister) { return static_cast<int16_t>(static_cast<uint16_t>((InRegister >> 16) & 0xFFFF)); }
    }
}
