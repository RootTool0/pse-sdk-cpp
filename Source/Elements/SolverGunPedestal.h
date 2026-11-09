// pse-sdk-cpp

#pragma once

namespace pse
{
    class SolverGunPedestalElement : public BaseElement
    {
    public:
        static SolverGunPedestalElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_SOLVER_GUN_PEDESTAL, SolverGunPedestalElement>(InTransform, InState, bVisibility); }
    };
}
