// pse-sdk-cpp

#pragma once

namespace pse::StaticMesh
{
    inline void Create(const PseTransform& InTransform, const PseMesh InMesh, const PseMaterial InMaterial)
    {
        PseData Cmd{};
        Cmd.header = PSE_COMMAND_STATIC_MESH_CREATE;
        Data::set<0, PseTransform>(Cmd, InTransform);
        Data::set<40, PseMesh>(Cmd, InMesh);
        Data::set<42, PseMaterial>(Cmd, InMaterial);
        
        pseCommandBufferSinglePushAndWait(&Cmd);
        PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::StaticMesh::Create failed: 0x%X", Cmd.header);
    }
}
