// pse-sdk-cpp

#pragma once

namespace pse
{
    class LaserCubeElement : public BaseElement
    {
    public:
        static LaserCubeElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_LASER_CUBE, LaserCubeElement>(InTransform, InState, bVisibility); }
    };
}
