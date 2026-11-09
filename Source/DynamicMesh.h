// pse-sdk-cpp

#pragma once

namespace pse
{
    class DynamicMesh
    {
        
    public:
        static DynamicMesh PrivateCreate(const PseTransform& InTransform, const PseMesh InMesh, const PseMaterial InMaterial, const bool bVisibility = true)
        {
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_DYNAMIC_MESH_CREATE;
            Data::set<0, PseTransform>(Cmd, InTransform);
            Data::set<40, PseMesh>(Cmd, InMesh);
            Data::set<42, PseMaterial>(Cmd, InMaterial);
            Data::set<44, int8_t>(Cmd, bVisibility ? 1 : 0);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::PseDynamicMesh::Create failed: 0x%X", Cmd.header);
            
            DynamicMesh Mesh;
            Mesh.GUID = Data::get<0, PseGUID>(Cmd);
            
            return Mesh;
        }
        
        void SetMaterial(const PseMaterial InMaterial) const
        {
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_DYNAMIC_MESH_SET_MATERIAL;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseMaterial>(Cmd, InMaterial);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::PseDynamicMesh::SetMaterial failed: 0x%X", Cmd.header);
        }
        
        void SetMesh(const PseMesh InMesh) const
        {
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_DYNAMIC_MESH_SET_MESH;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseMesh>(Cmd, InMesh);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::PseDynamicMesh::SetMesh failed: 0x%X", Cmd.header);
        }
        
        void SetVisibility(const bool bVisibility) const
        {
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_DYNAMIC_MESH_SET_VISIBILITY;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, int8_t>(Cmd, bVisibility ? 1 : 0);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::PseDynamicMesh::SetVisibility failed: 0x%X", Cmd.header);
        }
        
        bool GetVisibility() const
        {
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_DYNAMIC_MESH_GET_VISIBILITY;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::PseDynamicMesh::GetVisibility failed: 0x%X", Cmd.header);
            
            return Data::get<0, int8_t>(Cmd) != 0;
        }
        
        void SetTransform(const PseTransform& InTransform) const
        {
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_DYNAMIC_MESH_SET_TRANSFORM;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseTransform>(Cmd, InTransform);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::PseDynamicMesh::SetTransform failed: 0x%X", Cmd.header);
        }
        
        PseTransform GetTransform() const
        {
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_DYNAMIC_MESH_GET_TRANSFORM;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::PseDynamicMesh::GetTransform failed: 0x%X", Cmd.header);
            
            return Data::get<0, PseTransform>(Cmd);
        }
        
        void Destroy() const
        {
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_DYNAMIC_MESH_DESTROY;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::PseDynamicMesh::Destroy failed: 0x%X", Cmd.header);
        }
        
        PseGUID GetGUID() const { return GUID; }
    
    private:
        PseGUID GUID = -1;
    };
}
