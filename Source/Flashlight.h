// pse-sdk-cpp

#pragma once

namespace pse::Flashlight
{
    inline void SetEnabled(const bool bEnabled)
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_FLASHLIGHT_SET_ENABLED;
        Data::set<0, int8_t>(Cmd, bEnabled ? 1 : 0);
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Flashlight::SetEnabled failed: 0x%X", Cmd.header);
    }
    
    inline bool GetEnabled()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_FLASHLIGHT_GET_ENABLED;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Flashlight::GetEnabled failed: 0x%X", Cmd.header);
        
        return Data::get<0, int8_t>(Cmd) != 0;
    }
    
    inline void SetState(const bool bState)
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_FLASHLIGHT_SET_STATE;
        Data::set<0, int8_t>(Cmd, bState ? 1 : 0);
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Flashlight::SetState failed: 0x%X", Cmd.header);
    }
    
    inline bool GetState()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_FLASHLIGHT_GET_STATE;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Flashlight::GetState failed: 0x%X", Cmd.header);
        
        return Data::get<0, int8_t>(Cmd) != 0;
    }
}
