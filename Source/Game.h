// pse-sdk-cpp

#pragma once

namespace pse::Game
{
    inline void SetCheatsEnabled(const bool bEnabled)
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_GAME_SET_CHEATS_ENABLED;
        Data::set<0, int8_t>(Cmd, bEnabled ? 1 : 0);
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Game::SetCheatsEnabled failed: 0x%X", Cmd.header);
    }
    
    inline bool GetCheatsEnabled()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_GAME_GET_CHEATS_ENABLED;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Game::GetCheatsEnabled failed: 0x%X", Cmd.header);
        
        return Data::get<0, int8_t>(Cmd) != 0;
    }
    
    inline void SetCheatsNoclip(const bool bEnabled)
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_GAME_SET_CHEATS_NOCLIP;
        Data::set<0, int8_t>(Cmd, bEnabled ? 1 : 0);
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Game::SetCheatsNoclip failed: 0x%X", Cmd.header);
    }
    
    inline bool GetCheatsNoclip()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_GAME_GET_CHEATS_NOCLIP;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Game::GetCheatsNoclip failed: 0x%X", Cmd.header);
        
        return Data::get<0, int8_t>(Cmd) != 0;
    }
    
    inline void SetGravity(const float InGravity)
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_GAME_SET_GRAVITY;
        Data::set<0, float>(Cmd, InGravity);
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Game::SetGravity failed: 0x%X", Cmd.header);
    }
    
    inline float GetGravity()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_GAME_GET_GRAVITY;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Game::GetGravity failed: 0x%X", Cmd.header);
        
        return Data::get<0, float>(Cmd);
    }
    
    inline bool CheckGUIDIsValid(const PseGUID InGUID)
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_GAME_CHECK_GUID_IS_VALID;
        Data::set<0, PseGUID>(Cmd, InGUID);
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Game::CheckGUIDIsValid failed: 0x%X", Cmd.header);
        
        return Data::get<0, int8_t>(Cmd) != 0;
    }
    
    inline void Initialize()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_GAME_INITIALIZE;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Game::Initialize failed: 0x%X", Cmd.header);
    }
    
    inline void Deinitialize()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_GAME_DEINITIALIZE;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Game::Deinitialize failed: 0x%X", Cmd.header);
    }
}
