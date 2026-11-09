// pse-sdk-cpp

#pragma once

namespace pse
{
    class FlashlightElement : public BaseElement
    {
    public:
        static FlashlightElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_FLASHLIGHT, FlashlightElement>(InTransform, InState, bVisibility); }
    };
}
