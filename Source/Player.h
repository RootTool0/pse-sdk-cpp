// pse-sdk-cpp

#pragma once

namespace pse::Player
{
    inline void SetLocation(const PseVector3& InLocation)
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_PLAYER_SET_LOCATION;
        Data::set<0, PseVector3>(Cmd, InLocation);
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Player::SetLocation failed: 0x%X", Cmd.header);
    }
    
    inline PseVector3 GetLocation()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_PLAYER_GET_LOCATION;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Player::GetLocation failed: 0x%X", Cmd.header);
        
        return Data::get<0, PseVector3>(Cmd);
    }
    
    inline void SetRotation(const PseQuat& InQuat)
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_PLAYER_SET_ROTATION;
        Data::set<0, PseQuat>(Cmd, InQuat);
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Player::SetRotation failed: 0x%X", Cmd.header);
    }
    
    inline void SetRotation(const PseRotator& InRotator)
    {
        SetRotation(Quat::fromDegrees(InRotator.Pitch, InRotator.Yaw, InRotator.Roll));
    }
    
    inline PseQuat GetRotation()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_PLAYER_GET_ROTATION;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Player::GetRotation failed: 0x%X", Cmd.header);
        
        return Data::get<0, PseQuat>(Cmd);
    }
    
    inline void Spawn()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_PLAYER_SPAWN;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Player::Spawn failed: 0x%X", Cmd.header);
    }
    
    inline void Kill()
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_PLAYER_KILL;
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Player::Kill failed: 0x%X", Cmd.header);
    }
}
