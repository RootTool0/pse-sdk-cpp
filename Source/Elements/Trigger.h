// pse-sdk-cpp

#pragma once

namespace pse
{
    class TriggerElement : public BaseElement
    {
    public:
        enum class ETarget : uint8_t
        {
            None    = 0b0000,
            Player  = 0b0001,
            Cubes   = 0b0010
        };
        
        enum class ECondition : uint8_t
        {
            None        = 0b0000,
            OnOverlapIn = 0b0001,
            OnOverlapOut= 0b0010
        };
        
        enum class EAction : uint8_t
        {
            None    = 0b0000,
            Call    = 0b0001,
            Destroy = 0b0010
        };
        
        static TriggerElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_TRIGGER, TriggerElement>(InTransform, InState, bVisibility); }
        
        ETarget GetTarget() const { return static_cast<ETarget>(Register::getBitsAs<uint8_t, 4>(GetRegister(0), 8)); }
        void SetTarget(const ETarget InTarget) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 4>(Register, 8, static_cast<uint8_t>(InTarget));
            SetRegister(0, Register);
        }
        
        ECondition GetCondition() const { return static_cast<ECondition>(Register::getBitsAs<uint8_t, 4>(GetRegister(0), 4)); }
        void SetCondition(const ECondition InCondition) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 4>(Register, 4, static_cast<uint8_t>(InCondition));
            SetRegister(0, Register);
        }
        
        EAction GetAction() const { return static_cast<EAction>(Register::getBitsAs<uint8_t, 4>(GetRegister(0), 0)); }
        void SetAction(const EAction InAction) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 4>(Register, 0, static_cast<uint8_t>(InAction));
            SetRegister(0, Register);
        }
    };
    
    PSE_ENUM_CLASS_FLAGS(TriggerElement::ETarget)
    PSE_ENUM_CLASS_FLAGS(TriggerElement::ECondition)
    PSE_ENUM_CLASS_FLAGS(TriggerElement::EAction)
}
