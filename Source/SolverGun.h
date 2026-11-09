// pse-sdk-cpp

#pragma once

namespace pse::SolverGun
{
    inline void SetEnabled(const bool bEnabled)
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_SOLVER_GUN_SET_ENABLED;
        Data::set<0, int8_t>(Cmd, bEnabled ? 1 : 0);
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::SolverGun::SetEnabled failed: 0x%X", Cmd.header);
    }
    
    inline bool GetEnabled()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_SOLVER_GUN_GET_ENABLED;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::SolverGun::GetEnabled failed: 0x%X", Cmd.header);
        
        return Data::get<0, int8_t>(Cmd) != 0;
    }
    
    inline void Use()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_SOLVER_GUN_ACTION_USE;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::SolverGun::Use failed: 0x%X", Cmd.header);
    }
    
    inline void Release()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_SOLVER_GUN_ACTION_RELEASE;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::SolverGun::Release failed: 0x%X", Cmd.header);
    }
    
    inline void Throw()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_SOLVER_GUN_ACTION_THROW;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::SolverGun::Throw failed: 0x%X", Cmd.header);
    }
}
