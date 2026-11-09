// pse-sdk-cpp

// Build date: 09 November 2026 | 21:18:13 UTC

#pragma once

#ifdef PSE_SDK_CPP_CORE_IMPLEMENTATION
#define PSE_EXPORTS
#endif
// Portal Solver Editor SDK


#include <cstdint>

enum PseCommand : uint32_t
{
	// Format (G - Group, C - Command)                           = 0xGGGСCCCC,
	PSE_COMMAND_GAME                                             = 0x00100000,
	PSE_COMMAND_GAME_SET_CHEATS_ENABLED                          = 0x00100001,
	PSE_COMMAND_GAME_GET_CHEATS_ENABLED                          = 0x00100002,
	PSE_COMMAND_GAME_SET_CHEATS_NOCLIP                           = 0x00100003,
	PSE_COMMAND_GAME_GET_CHEATS_NOCLIP                           = 0x00100004,
	PSE_COMMAND_GAME_SET_GRAVITY                                 = 0x00100005,
	PSE_COMMAND_GAME_GET_GRAVITY                                 = 0x00100006,
	PSE_COMMAND_GAME_CHECK_GUID_IS_VALID                         = 0x00100007,
	PSE_COMMAND_GAME_INITIALIZE                                  = 0x00100008,
	PSE_COMMAND_GAME_DEINITIALIZE                                = 0x00100009,
	
	PSE_COMMAND_PLAYER                                           = 0x00200000,
	PSE_COMMAND_PLAYER_SET_LOCATION                              = 0x00200001,
	PSE_COMMAND_PLAYER_GET_LOCATION                              = 0x00200002,
	PSE_COMMAND_PLAYER_SET_ROTATION                              = 0x00200003,
	PSE_COMMAND_PLAYER_GET_ROTATION                              = 0x00200004,
	PSE_COMMAND_PLAYER_SPAWN                                     = 0x00200005,
	PSE_COMMAND_PLAYER_KILL                                      = 0x00200006,
	
	PSE_COMMAND_SOLVER_GUN                                       = 0x00300000,
	PSE_COMMAND_SOLVER_GUN_SET_ENABLED                           = 0x00300001,
	PSE_COMMAND_SOLVER_GUN_GET_ENABLED                           = 0x00300002,
	PSE_COMMAND_SOLVER_GUN_ACTION_USE                            = 0x00300003,
	PSE_COMMAND_SOLVER_GUN_ACTION_RELEASE                        = 0x00300004,
	PSE_COMMAND_SOLVER_GUN_ACTION_THROW                          = 0x00300005,
	
	PSE_COMMAND_FLASHLIGHT                                       = 0x00400000,
	PSE_COMMAND_FLASHLIGHT_SET_ENABLED                           = 0x00400001,
	PSE_COMMAND_FLASHLIGHT_GET_ENABLED                           = 0x00400002,
	PSE_COMMAND_FLASHLIGHT_SET_STATE                             = 0x00400003,
	PSE_COMMAND_FLASHLIGHT_GET_STATE                             = 0x00400004,
	
	PSE_COMMAND_STATIC_MESH                                      = 0x00500000,
	PSE_COMMAND_STATIC_MESH_CREATE                               = 0x00500001,
	
	PSE_COMMAND_REPLACE                                          = 0x05062025,
	
	PSE_COMMAND_DYNAMIC_MESH                                     = 0x00600000,
	PSE_COMMAND_DYNAMIC_MESH_CREATE                              = 0x00600001,
	PSE_COMMAND_DYNAMIC_MESH_SET_MATERIAL                        = 0x00600002,
	PSE_COMMAND_DYNAMIC_MESH_SET_MESH                            = 0x00600003,
	PSE_COMMAND_DYNAMIC_MESH_SET_VISIBILITY                      = 0x00600004,
	PSE_COMMAND_DYNAMIC_MESH_GET_VISIBILITY                      = 0x00600005,
	PSE_COMMAND_DYNAMIC_MESH_SET_TRANSFORM                       = 0x00600006,
	PSE_COMMAND_DYNAMIC_MESH_GET_TRANSFORM                       = 0x00600007,
	PSE_COMMAND_DYNAMIC_MESH_DESTROY                             = 0x00600008,
	
	PSE_COMMAND_ELEMENT                                          = 0x00700000,
	PSE_COMMAND_ELEMENT_CREATE                                   = 0x00700001,
	PSE_COMMAND_ELEMENT_SET_CALLBACK                             = 0x00700002,
	PSE_COMMAND_ELEMENT_GET_CALLBACK                             = 0x00700003,
	PSE_COMMAND_ELEMENT_SET_STATE                                = 0x00700004,
	PSE_COMMAND_ELEMENT_GET_STATE                                = 0x00700005,
	PSE_COMMAND_ELEMENT_SET_VISIBILITY                           = 0x00700006,
	PSE_COMMAND_ELEMENT_GET_VISIBILITY                           = 0x00700007,
	PSE_COMMAND_ELEMENT_SET_TRANSFORM                            = 0x00700008,
	PSE_COMMAND_ELEMENT_GET_TRANSFORM                            = 0x00700009,
	PSE_COMMAND_ELEMENT_SET_CLASS                                = 0x0070000A,
	PSE_COMMAND_ELEMENT_GET_CLASS                                = 0x0070000B,
	PSE_COMMAND_ELEMENT_SET_REGISTER                             = 0x0070000C,
	PSE_COMMAND_ELEMENT_GET_REGISTER                             = 0x0070000D,
	PSE_COMMAND_ELEMENT_SET_ALL_REGISTERS                        = 0x0070000E,
	PSE_COMMAND_ELEMENT_GET_ALL_REGISTERS                        = 0x0070000F,
	PSE_COMMAND_ELEMENT_SET_STATE_AND_CALLBACK_AND_ALL_REGISTERS = 0x00700010,
	PSE_COMMAND_ELEMENT_GET_STATE_AND_CALLBACK_AND_ALL_REGISTERS = 0x00700011,
	PSE_COMMAND_ELEMENT_DESTROY                                  = 0x00700012,
	
	PSE_COMMAND_NONE                                             = 0xFFFFFFFF
};

enum PseEvent : uint32_t
{
	PSE_EVENT_ELEMENT_CHANGED    = 0x00000000,
	PSE_EVENT_GAME_TICK_OVERFLOW = 0x00000001,
	
	PSE_EVENT_NONE               = 0xFFFFFFFF
};

enum PseResult : uint32_t
{
	PSE_RESULT_SUCCESS                        = 0x00000000,
	
	PSE_RESULT_ERROR_COMMAND_NOT_FOUND        = 0x00000001,
	PSE_RESULT_ERROR_COMMAND_NOT_IMPLEMENTED  = 0x00000002,
	PSE_RESULT_ERROR_EXECUTION_FAILED         = 0x00000003,
	PSE_RESULT_ERROR_ARRAY_INDEX_OUT_OF_RANGE = 0x00000004,
	PSE_RESULT_ERROR_GUID_NOT_FOUND           = 0x00000005,
	PSE_RESULT_ERROR_INVALID_OBJECT_TYPE      = 0x00000006,
	PSE_RESULT_ERROR_GAME_NOT_INITIALIZED     = 0x00000007,
	
	PSE_RESULT_NONE                           = 0xFFFFFFFF
};

enum PseMesh : uint16_t
{
	PSE_MESH_PLANE               = 0x0000,
	PSE_MESH_FACE                = 0x0001,
	PSE_MESH_CUBE                = 0x0002,
	
	PSE_MESH_CUP_INNER           = 0x0003,
	PSE_MESH_CUP_OUTER           = 0x0004,
	PSE_MESH_II_INNER            = 0x0005,
	PSE_MESH_II_OUTER            = 0x0006,
	PSE_MESH_O_INNER             = 0x0007,
	PSE_MESH_O_OUTER             = 0x0008,
	PSE_MESH_U_INNER             = 0x0009,
	PSE_MESH_U_OUTER             = 0x000A,
	
	PSE_MESH_DOOR_FRAME          = 0x000B,
	PSE_MESH_LASER_FRAME         = 0x000C,
	PSE_MESH_LASER_FRAME_SHIFTED = 0x000D,
	PSE_MESH_PLANE_Z_SHIFTED     = 0x000E,
	PSE_MESH_CUBE_DROPPER_FRAME  = 0x000F,
};

enum PseMaterial : uint16_t
{
	PSE_MATERIAL_WALL_WHITE_SMALL            = 0x0000,
	PSE_MATERIAL_WALL_WHITE_MEDIUM           = 0x0001,
	PSE_MATERIAL_WALL_WHITE_DOUBLE           = 0x0002,
	PSE_MATERIAL_WALL_WHITE_BIG              = 0x0003,
	PSE_MATERIAL_WALL_WHITE_ABSOLUTE_SCIENCE = 0x0004,
	
	PSE_MATERIAL_WALL_BLACK_SMALL            = 0x0005,
	PSE_MATERIAL_WALL_BLACK_MEDIUM           = 0x0006,
	PSE_MATERIAL_WALL_BLACK_BIG              = 0x0007,
	
	PSE_MATERIAL_FLOOR_WHITE                 = 0x0008,
	PSE_MATERIAL_FLOOR_BLACK                 = 0x0009,
	
	PSE_MATERIAL_WINDOW_METAL_GRID           = 0x000A,
	PSE_MATERIAL_WINDOW_GLASS_METAL_GRID     = 0x000B,
	
	PSE_MATERIAL_WALL_YELLOW_1_0             = 0x000C,
	PSE_MATERIAL_WALL_YELLOW_1_5             = 0x000D,
};

enum PseClass : uint16_t
{
	PSE_CLASS_ENTRY_ELEVATOR           = 0x0000,
	PSE_CLASS_EXIT_ELEVATOR            = 0x0001,
	
	PSE_CLASS_DOOR                     = 0x0002,
	PSE_CLASS_BUTTON                   = 0x0003,
	PSE_CLASS_ANTI_EXPROPRIATION_FIELD = 0x0004,
	PSE_CLASS_PEDESTAL_BUTTON          = 0x0005,
	PSE_CLASS_SOLVER_BUTTON            = 0x0006,
	PSE_CLASS_INDICATOR                = 0x0007,
	
	PSE_CLASS_LASER_TX                 = 0x0008,
	PSE_CLASS_LASER_RX                 = 0x0009,
	PSE_CLASS_LASER_RELAY              = 0x000A,
	PSE_CLASS_LASER_PANEL              = 0x000B,
	
	PSE_CLASS_LASER_CUBE               = 0x000C,
	PSE_CLASS_WEIGHT_CUBE              = 0x000D,
	
	PSE_CLASS_FAITH_PLATE              = 0x000E,
	PSE_CLASS_PANEL                    = 0x000F,
	PSE_CLASS_STAIRS                   = 0x0010,
	PSE_CLASS_CUBE_DROPPER             = 0x0011,
	PSE_CLASS_SOLVER_GUN_PEDESTAL      = 0x0012,
	PSE_CLASS_FLASHLIGHT               = 0x0013,
	PSE_CLASS_WINDOW                   = 0x0014,
	
	PSE_CLASS_TRIGGER                  = 0x0015,
	PSE_CLASS_LAMP                     = 0x0016
};

// Portal Solver Editor SDK


#include <stdint.h>

#define PSE_COMMAND_BUFFER_SIZE 2048
#define PSE_EVENT_BUFFER_SIZE 256
#define PSE_MAX_COMMANDS_PER_TICK 128

typedef uint64_t PseGUID;
typedef uint32_t PseRegister;
typedef int8_t PseState;
typedef uint64_t PseCallback;

typedef struct { float x, y; } PseVector2;
typedef struct { float x, y, z; } PseVector3;
typedef struct { float x, y, z, w; } PseQuat;
typedef struct { PseQuat quat; PseVector3 location; PseVector3 scale; } PseTransform;
typedef struct { uint8_t r, g, b; } PseColor;

typedef struct alignas(64)
{
    uint32_t header;
    uint8_t data[60];
} PseData;

typedef struct alignas(64)
{
    alignas(64) PseData buffer[PSE_COMMAND_BUFFER_SIZE];
    alignas(64) uint32_t pseIndex;
    alignas(64) uint32_t gameIndex;
} PseCommandBuffer;

typedef struct alignas(64)
{
    alignas(64) PseData buffer[PSE_EVENT_BUFFER_SIZE];
    alignas(64) uint32_t gameIndex;
} PseEventBuffer;

typedef struct alignas(64)
{
    alignas(64) PseCommandBuffer commandBuffer;
    alignas(64) PseEventBuffer eventBuffer;
} PseBuffers;

// Portal Solver Editor SDK


#if defined(_WIN32)
    #ifdef PSE_EXPORTS
        #define PSE_API __declspec(dllexport)
    #else
        #define PSE_API __declspec(dllimport)
    #endif
#else
    #define PSE_API __attribute__((visibility("default")))
#endif


#ifdef __cplusplus
extern "C"
{
#endif
    
    // Buffers / Core
    PSE_API int32_t pseInitializeBuffers(void);
    PSE_API void    pseDeinitializeBuffers(void);
    
    PSE_API PseBuffers*       pseGetBuffersAddress(void);
    PSE_API PseCommandBuffer* pseGetCommandBufferAddress(void);
    PSE_API PseEventBuffer*   pseGetEventBufferAddress(void);
    PSE_API void*             pseGetSharedMemoryHandle(void);
    
    // Command Buffer / Methods
    PSE_API void     pseCommandBufferSynchronize(void);
    
    PSE_API uint32_t pseCommandBufferSinglePush(const PseData* pInData);
    PSE_API void     pseCommandBufferSingleWait(uint32_t absoluteIndex, PseData* pOutData);
    PSE_API void     pseCommandBufferSinglePushAndWait(PseData* pOutData);
    
    PSE_API uint32_t pseCommandBufferBatchPush(const PseData* pInData, uint32_t count);
    PSE_API void     pseCommandBufferBatchWait(uint32_t absoluteIndex, PseData* pOutData, uint32_t count);
    PSE_API void     pseCommandBufferBatchPushAndWait(PseData* pOutData, uint32_t count);
    
    PSE_API PseData* pseCommandBufferRawAt(uint32_t absoluteIndex);
    PSE_API uint32_t pseCommandBufferRawReserve(uint32_t count);
    PSE_API void     pseCommandBufferRawCommit(uint32_t startAbsoluteIndex, uint32_t count);
    PSE_API void     pseCommandBufferRawWait(uint32_t absoluteIndex, uint32_t count);
    PSE_API void     pseCommandBufferRawCommitAndWait(uint32_t startAbsoluteIndex, uint32_t count);
    
    // Event Buffer / Methods
    PSE_API int32_t pseEventBufferTryGet(PseData* pOutData);
    
#ifdef __cplusplus
}
#endif

#ifdef PSE_SDK_CPP_CORE_IMPLEMENTATION
// Portal Solver Editor SDK


#include <atomic>
#include <Windows.h>

// Static
static inline void* gPseSharedMemoryHandle = nullptr;
static inline PseBuffers* gPseBuffers = nullptr;
static inline PseCommandBuffer* gPseCommandBuffer = nullptr;
static inline PseEventBuffer* gPseEventBuffer = nullptr;
static inline uint32_t gPseEventBufferIndex = 0;

// Private
static void privateCommandBufferRawCopy(void* pExternalData, uint32_t absoluteIndex, uint32_t count, bool bToBuffer)
{
    uint32_t spaceAtEnd = PSE_COMMAND_BUFFER_SIZE - (absoluteIndex & (PSE_COMMAND_BUFFER_SIZE - 1));
    void* pInternalStart = pseCommandBufferRawAt(absoluteIndex);
    
    if(count <= spaceAtEnd)
    {
        std::memcpy
        (
            bToBuffer ? pInternalStart : pExternalData,
            bToBuffer ? pExternalData : pInternalStart,
            count * 64
        );
    }
    else
    {
        uint32_t BytesAtEnd = spaceAtEnd * 64;
            
        std::memcpy
        (
            bToBuffer ? pInternalStart : pExternalData,
            bToBuffer ? pExternalData : pInternalStart,
            BytesAtEnd
        );
            
        std::memcpy
        (
            bToBuffer ? (uint8_t*)&gPseCommandBuffer->buffer[0] : (uint8_t*)pExternalData + BytesAtEnd,
            bToBuffer ? (uint8_t*)pExternalData + BytesAtEnd : (uint8_t*)&gPseCommandBuffer->buffer[0],
            (count - spaceAtEnd) * 64
        );
    }
}

PseData* privateEventBufferRawAt(uint32_t absoluteIndex)
{
    return &gPseEventBuffer->buffer[absoluteIndex & (PSE_EVENT_BUFFER_SIZE - 1)];
}

inline std::atomic<uint32_t>* privateAsAtomic(uint32_t* pVariable)
{
    return reinterpret_cast<std::atomic<uint32_t>*>(pVariable);
}

// Buffers / Core
int32_t pseInitializeBuffers(void)
{
    gPseSharedMemoryHandle = OpenFileMappingA(FILE_MAP_ALL_ACCESS, FALSE, "Global\\PortalSolverEditorSDK");
    if(!gPseSharedMemoryHandle)
    {
        // 0.2 fix: Global -> Local. Working for Backward Compatibility
        gPseSharedMemoryHandle = OpenFileMappingA(FILE_MAP_ALL_ACCESS, FALSE, "Local\\PortalSolverEditorSDK");
        if(!gPseSharedMemoryHandle) return -1; // Could not open file mapping object
    }
    
    void* pBuffers = MapViewOfFile(gPseSharedMemoryHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(PseBuffers));
    if(!pBuffers)
    {
        CloseHandle(gPseSharedMemoryHandle);
        gPseSharedMemoryHandle = nullptr;
        return -2; // Could not map view of file
    }
    
    gPseBuffers = static_cast<PseBuffers*>(pBuffers);
    gPseCommandBuffer = &gPseBuffers->commandBuffer;
    gPseEventBuffer = &gPseBuffers->eventBuffer;
    
    memset(pBuffers, 0, sizeof(PseBuffers));
    gPseEventBufferIndex = 0;
    
    return 0;
}

void pseDeinitializeBuffers(void)
{
    if(gPseBuffers) UnmapViewOfFile(gPseBuffers);
    if(gPseSharedMemoryHandle) CloseHandle(gPseSharedMemoryHandle);

    gPseBuffers = nullptr;
    gPseCommandBuffer = nullptr;
    gPseEventBuffer = nullptr;
    gPseSharedMemoryHandle = nullptr;
}

PseBuffers*       pseGetBuffersAddress(void)       { return gPseBuffers; }
PseCommandBuffer* pseGetCommandBufferAddress(void) { return gPseCommandBuffer; }
PseEventBuffer*   pseGetEventBufferAddress(void)   { return gPseEventBuffer; }
void*             pseGetSharedMemoryHandle(void)   { return gPseSharedMemoryHandle; }

// Command Buffer / Methods
void pseCommandBufferSynchronize(void)
{
    uint32_t pse = privateAsAtomic(&gPseCommandBuffer->pseIndex)->load(std::memory_order_relaxed);
    while(true)
    {
        uint32_t game = privateAsAtomic(&gPseCommandBuffer->gameIndex)->load(std::memory_order_acquire);
        if((int32_t)(game - pse) >= 0) break;
        _mm_pause();
    }
}

uint32_t pseCommandBufferSinglePush(const PseData* pInData)
{
    while(true)
    {
        uint32_t pse = privateAsAtomic(&gPseCommandBuffer->pseIndex)->load(std::memory_order_relaxed);
        uint32_t game = privateAsAtomic(&gPseCommandBuffer->gameIndex)->load(std::memory_order_acquire);
        
        if(pse - game < PSE_COMMAND_BUFFER_SIZE)
        {
            *pseCommandBufferRawAt(pse) = *pInData;
            privateAsAtomic(&gPseCommandBuffer->pseIndex)->store(pse + 1, std::memory_order_release);
            return pse;
        }
        
        _mm_pause();
    }
}

void pseCommandBufferSingleWait(uint32_t absoluteIndex, PseData* pOutData)
{
    while(true)
    {
        uint32_t game = privateAsAtomic(&gPseCommandBuffer->gameIndex)->load(std::memory_order_acquire);
        
        if(game > absoluteIndex)
        {
            *pOutData = *pseCommandBufferRawAt(absoluteIndex);
            return;
        }
        
        _mm_pause();
    }
}

void pseCommandBufferSinglePushAndWait(PseData* pOutData)
{
    pseCommandBufferSingleWait(pseCommandBufferSinglePush(pOutData), pOutData);
}

uint32_t pseCommandBufferBatchPush(const PseData* pInData, uint32_t count)
{
    while(true)
    {
        uint32_t pse = privateAsAtomic(&gPseCommandBuffer->pseIndex)->load(std::memory_order_relaxed);
        uint32_t game = privateAsAtomic(&gPseCommandBuffer->gameIndex)->load(std::memory_order_acquire);
            
        if(pse - game + count <= PSE_COMMAND_BUFFER_SIZE)
        {
            privateCommandBufferRawCopy((void*)pInData, pse, count, true);
            privateAsAtomic(&gPseCommandBuffer->pseIndex)->store(pse + count, std::memory_order_release);
            return pse;
        }
        _mm_pause();
    }
}

void pseCommandBufferBatchWait(uint32_t absoluteIndex, PseData* pInData, uint32_t count)
{
    if(count == 0) return;
        
    while(true)
    {
        uint32_t game = privateAsAtomic(&gPseCommandBuffer->gameIndex)->load(std::memory_order_acquire);
        if((int32_t)(game - (absoluteIndex + count)) >= 0)
        {
            privateCommandBufferRawCopy((void*)pInData, absoluteIndex, count, false);
            return;
        }
        _mm_pause();
    }
}

void pseCommandBufferBatchPushAndWait(PseData* pInData, uint32_t count)
{
    pseCommandBufferBatchWait(pseCommandBufferBatchPush(pInData, count), pInData, count);
}

PseData* pseCommandBufferRawAt(uint32_t absoluteIndex)
{
    return &gPseCommandBuffer->buffer[absoluteIndex & (PSE_COMMAND_BUFFER_SIZE - 1)];
}

uint32_t pseCommandBufferRawReserve(uint32_t count)
{
    while(true)
    {
        uint32_t pse = privateAsAtomic(&gPseCommandBuffer->pseIndex)->load(std::memory_order_relaxed);
        uint32_t game = privateAsAtomic(&gPseCommandBuffer->gameIndex)->load(std::memory_order_acquire);
        if(pse - game + count <= PSE_COMMAND_BUFFER_SIZE) return pse;
        _mm_pause();
    }
}

void pseCommandBufferRawCommit(uint32_t startAbsoluteIndex, uint32_t count)
{
    privateAsAtomic(&gPseCommandBuffer->pseIndex)->store(startAbsoluteIndex + count, std::memory_order_release);
}

void pseCommandBufferRawWait(uint32_t absoluteIndex, uint32_t count)
{
    while(true)
    {
        uint32_t game = privateAsAtomic(&gPseCommandBuffer->gameIndex)->load(std::memory_order_acquire);
        if((int32_t)(game - (absoluteIndex + count)) >= 0) return;
        _mm_pause();
    }
}

void pseCommandBufferRawCommitAndWait(uint32_t startAbsoluteIndex, uint32_t count)
{
    pseCommandBufferRawCommit(startAbsoluteIndex, count);
    pseCommandBufferRawWait(startAbsoluteIndex, count);
}

// Event Buffer / Methods
int32_t pseEventBufferTryGet(PseData* pOutData)
{
    uint32_t game = privateAsAtomic(&gPseEventBuffer->gameIndex)->load(std::memory_order_acquire);
    if((int32_t)(game - gPseEventBufferIndex) <= 0) return 0;
    
    *pOutData = *privateEventBufferRawAt(gPseEventBufferIndex);
    ++gPseEventBufferIndex;
    return 1;
}


#endif
#include <cmath>
// Portal Solver Editor SDK


#ifdef __cplusplus

#include <cstring>
#include <stdint.h>


namespace pse
{
    namespace Register 
    {
		// Bit
		inline void setBit(PseRegister& outRegister, const uint8_t inOffset, const bool inValue)
		{
			outRegister = (outRegister & ~(1 << inOffset)) | (static_cast<PseRegister>(inValue) << inOffset);
		}
		
		inline bool getBit(const PseRegister inRegister, const uint8_t inOffset)
		{
			return (inRegister & (1 << inOffset)) != 0;
		}
		
		inline void updateBit(const bool toRegister, PseRegister& outRegister, const uint8_t inOffset, bool& outValue)
		{
			if(toRegister) setBit(outRegister, inOffset, outValue);
			else outValue = getBit(outRegister, inOffset);
		}
		
		// Int
		template<typename T>
		T getInt(const PseRegister inRegister, const uint8_t inOffset)
		{
	        constexpr uint8_t BitSize = sizeof(T) * 8;
			static_assert(sizeof(T) * 8 <= 32, "T is big!");
	        constexpr uint32_t Mask = (BitSize == 32) ? 0xFFFFFFFF : ((1U << BitSize) - 1);
			return static_cast<T>((inRegister >> inOffset) & Mask);
		}
		
		template<typename T>
		void setInt(PseRegister& outRegister, const uint8_t inOffset, const T inValue)
		{
	        constexpr uint8_t BitSize = sizeof(T) * 8;
			static_assert(sizeof(T) * 8 <= 32, "T is big!");
	        constexpr uint32_t Mask = (BitSize == 32) ? 0xFFFFFFFF : ((1U << BitSize) - 1);
			outRegister = (outRegister & ~(Mask << inOffset)) | ((static_cast<PseRegister>(inValue) & Mask) << inOffset);
		}
		
		template<typename T, typename Q>
		void updateInt(const bool toRegister, PseRegister& outRegister, const uint8_t inOffset, Q& outValue)
		{
			if(toRegister) setInt<T>(outRegister, inOffset, static_cast<T>(outValue));
			else outValue = static_cast<Q>(getInt<T>(outRegister, inOffset));
		}
		
		// BitAs
		template<typename T, uint8_t bitCount>
		T getBitsAs(const PseRegister inRegister, const uint8_t inOffset)
		{
			static_assert(bitCount > 0 && bitCount <= 32, "bitCount must be between 1 and 32!");
	        constexpr uint32_t Mask = (bitCount == 32) ? 0xFFFFFFFF : ((1U << bitCount) - 1);
			return static_cast<T>((static_cast<PseRegister>(inRegister) >> inOffset) & Mask);
		}
		
		template<typename T, uint8_t bitCount>
		void setBitsAs(PseRegister& outRegister, const uint8_t inOffset, const T inValue)
		{
			static_assert(bitCount > 0 && bitCount <= 32, "bitCount must be between 1 and 32!");
	        constexpr uint32_t Mask = (bitCount == 32) ? 0xFFFFFFFF : ((1U << bitCount) - 1);
			outRegister = static_cast<PseRegister>((static_cast<PseRegister>(outRegister) & ~(Mask << inOffset)) | ((static_cast<PseRegister>(inValue) & Mask) << inOffset));
		}
		
		template<typename T, uint8_t bitCount, typename Q>
		void updateBitsAs(const bool toRegister, PseRegister& outRegister, const uint8_t inOffset, Q& outValue)
		{
			if(toRegister) setBitsAs<T, bitCount>(outRegister, inOffset, static_cast<T>(outValue));
			else outValue = static_cast<Q>(getBitsAs<T, bitCount>(outRegister, inOffset));
		}
    }
	
    namespace Data
    {
    	template<uint8_t offset, typename T>
        void set(PseData& outData, const T& inValue)
        {
        	static_assert(offset + sizeof(T) <= 60, "offset + sizeof(T) must be between 0 and 60!");
            std::memcpy(&outData.data[offset], &inValue, sizeof(T));
        }
        
    	template<uint8_t offset, typename T>
        T get(const PseData& inData)
        {
        	static_assert(offset + sizeof(T) <= 60, "offset + sizeof(T) must be between 0 and 60!");
            T result;
            std::memcpy(&result, &inData.data[offset], sizeof(T));
            return result;
        }
    }
	
    namespace Events
    {
		//  1 - The event was successfully retrieved and processed by the built-in callback
        //  0 - The event was retrieved, but not recognized by the SDK (given to the user in outData)
        // -1 - Event buffer is empty
        inline int32_t poll(PseData& outData)
        {
            if(pseEventBufferTryGet(&outData) == 0)
				return -1;
            
			switch(outData.header)
			{
			default: break;
			case PSE_EVENT_ELEMENT_CHANGED:
			    {
                    PseCallback callback = pse::Data::get<8, PseCallback>(outData);
                    if(callback == 0) return false;
					
                    PseState state = pse::Data::get<16, PseState>(outData);
                    auto pfnCallback = reinterpret_cast<void(*)(PseState)>(callback);
                    pfnCallback(state);
					
                    return 1;
                }
				break;
			}
			
            return 0;
        }
		
        inline int32_t poll()
        {
            PseData data{};
            return poll(data);
        }
	}
	
    namespace Quat
    {
    	inline PseQuat fromRadians(const float pitch, const float yaw, const float roll)
    	{
    		const float pitchHalf = pitch * 0.5f;
    		const float yawHalf   = yaw   * 0.5f;
    		const float rollHalf  = roll  * 0.5f;
    		
    		const float sp = std::sin(pitchHalf);
    		const float cp = std::cos(pitchHalf);
    		
    		const float sy = std::sin(yawHalf);
    		const float cy = std::cos(yawHalf);
    		
    		const float sr = std::sin(rollHalf);
    		const float cr = std::cos(rollHalf);
    		
    		PseQuat quat{};
    		quat.x = cr * sp * sy + sr * cp * cy;
    		quat.y = cr * sp * cy - sr * cp * sy;
    		quat.z = cr * cp * sy - sr * sp * cy;
    		quat.w = cr * cp * cy + sr * sp * sy;
    		
    		return quat;
    	}
    	
    	inline PseQuat fromDegrees(const float pitch, const float yaw, const float roll)
    	{
    		constexpr float degreesToRadians = 3.14159265358979323846f / 180.0f;
    		return fromRadians(pitch * degreesToRadians, yaw * degreesToRadians, roll * degreesToRadians);
    	}
    }
}

#endif

// pse-sdk-cpp


#include <cstdint>

#ifndef PSE_ASSERT
    #include <cstdio>
    #include <cstdlib>

    #ifdef NDEBUG
        #define PSE_ASSERT(LikelyExpression, Format, ...) ((void)0)
    #else
        #define PSE_ASSERT(LikelyExpression, Format, ...) \
        do { \
        if(!(LikelyExpression)) { \
        std::printf("[PseCpp] Assertion failed: \"%s\" Message: \"" Format "\"\n", #LikelyExpression, ##__VA_ARGS__); \
        std::abort(); \
        } \
        } while(false)
    #endif
#endif

#define PSE_ENUM_CLASS_FLAGS(EnumType)                                                                      \
    constexpr EnumType operator|(const EnumType InA, const EnumType InB)                                    \
    {                                                                                                       \
        using Underlying = std::underlying_type_t<EnumType>;                                                \
        return static_cast<EnumType>(static_cast<Underlying>(InA) | static_cast<Underlying>(InB));          \
    }                                                                                                       \
    constexpr EnumType operator&(const EnumType InA, const EnumType InB)                                    \
    {                                                                                                       \
        using Underlying = std::underlying_type_t<EnumType>;                                                \
        return static_cast<EnumType>(static_cast<Underlying>(InA) & static_cast<Underlying>(InB));          \
    }                                                                                                       \
    constexpr EnumType operator^(const EnumType InA, const EnumType InB)                                    \
    {                                                                                                       \
        using Underlying = std::underlying_type_t<EnumType>;                                                \
        return static_cast<EnumType>(static_cast<Underlying>(InA) ^ static_cast<Underlying>(InB));          \
    }                                                                                                       \
    constexpr EnumType operator~(const EnumType InA)                                                        \
    {                                                                                                       \
        using Underlying = std::underlying_type_t<EnumType>;                                                \
        return static_cast<EnumType>(~static_cast<Underlying>(InA));                                        \
    }                                                                                                       \
    constexpr EnumType& operator|=(EnumType& OutA, const EnumType InB) { OutA = OutA | InB; return OutA; }  \
    constexpr EnumType& operator&=(EnumType& OutA, const EnumType InB) { OutA = OutA & InB; return OutA; }  \
    constexpr EnumType& operator^=(EnumType& OutA, const EnumType InB) { OutA = OutA ^ InB; return OutA; }  \
    constexpr bool operator!(const EnumType InA)                                                            \
    {                                                                                                       \
        using Underlying = std::underlying_type_t<EnumType>;                                                \
        return static_cast<Underlying>(InA) == 0;                                                           \
    }

namespace pse
{
    inline bool Initialize()
    {
        if(pseGetBuffersAddress() != nullptr) return true;
        
        const int32_t Result = pseInitializeBuffers();
        PSE_ASSERT(Result == 0, "pse::Initialize failed: pseInitializeBuffers returned %d", Result);
        
        return Result != 0;
    }
    
    inline void Deinitialize()
    {
        pseDeinitializeBuffers();
    }
}

// Euler's ZYX in Degrees
struct PseRotator
{
    float Pitch = 0.f;
    float Yaw   = 0.f;
    float Roll  = 0.f;
};

// pse-sdk-cpp


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

// pse-sdk-cpp


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

// pse-sdk-cpp


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

// pse-sdk-cpp


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

// pse-sdk-cpp


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

// pse-sdk-cpp


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

// pse-sdk-cpp


namespace pse
{
    class BaseElement
    {
        
    public:
        BaseElement() = default;
        BaseElement(const PseGUID InGUID) : GUID(InGUID) {}
        
        PseGUID GetGUID() const { return GUID; }
        bool IsValidGUID() const { return GetGUID() != -1; }
        
        void SetTransform(const PseTransform& InTransform) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::SetTransform: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_SET_TRANSFORM;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseTransform>(Cmd, InTransform);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::SetTransform failed: 0x%X", Cmd.header);
        }
        
        PseTransform GetTransform() const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::GetTransform: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_GET_TRANSFORM;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::GetTransform failed: 0x%X", Cmd.header);
            
            return Data::get<0, PseTransform>(Cmd);
        }
        
        void SetVisibility(const bool bVisibility) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::SetVisibility: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_SET_VISIBILITY;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, int8_t>(Cmd, bVisibility ? 1 : 0);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::SetVisibility failed: 0x%X", Cmd.header);
        }
        
        bool GetVisibility() const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::GetVisibility: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_GET_VISIBILITY;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::GetVisibility failed: 0x%X", Cmd.header);
            
            return Data::get<0, int8_t>(Cmd) != 0;
        }
        
        void SetState(const PseState InState) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::SetState: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_SET_STATE;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseState>(Cmd, InState);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::SetState failed: 0x%X", Cmd.header);
        }
        
        PseState GetState() const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::GetState: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_GET_STATE;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::GetState failed: 0x%X", Cmd.header);
            
            return Data::get<0, PseState>(Cmd);
        }
        
        void SetCallback(const PseCallback InCallback) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::SetCallback: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_SET_CALLBACK;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseCallback>(Cmd, InCallback);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::SetCallback failed: 0x%X", Cmd.header);
        }
        
        PseCallback GetCallback() const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::GetCallback: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_GET_CALLBACK;
            Data::set<0, PseGUID>(Cmd, GUID);
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::GetCallback failed: 0x%X", Cmd.header);
            
            return Data::get<0, PseCallback>(Cmd);
        }
        
        PseRegister GetRegister(const int Index) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::GetRegister: Element is not Valid! (GUID == -1)");
            PSE_ASSERT(Index >= 0 && Index <= 7, "pse::BaseElement::GetRegister: Index %d out of range [0,7]", Index);
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_GET_REGISTER;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, int8_t>(Cmd, static_cast<int8_t>(Index));
            
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::GetRegister failed: 0x%X", Cmd.header);
            
            return Data::get<0, PseRegister>(Cmd);
        }
        
        void SetRegister(const int Index, const PseRegister InRegister) const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::SetRegister: Element is not Valid! (GUID == -1)");
            PSE_ASSERT(Index >= 0 && Index <= 7, "pse::BaseElement::SetRegister: Index %d out of range [0,7]", Index);
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_SET_REGISTER;
            Data::set<0, PseGUID>(Cmd, GUID);
            Data::set<8, PseRegister>(Cmd, InRegister);
            Data::set<16, int8_t>(Cmd, static_cast<int8_t>(Index));
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::SetRegister failed: 0x%X", Cmd.header);
        }
        
        void Destroy() const
        {
            PSE_ASSERT(IsValidGUID(), "pse::BaseElement::Destroy: Element is not Valid! (GUID == -1)");
            
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_DESTROY;
            Data::set<0, PseGUID>(Cmd, GUID);
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::BaseElement::Destroy failed: 0x%X", Cmd.header);
        }
        
    private:
        PseGUID GUID = -1;
    };
    
    namespace Private
    {
        template<PseClass TPseClass, typename TElement>
        static TElement CreateElement(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true)
        {
            PseData Cmd{};
            Cmd.header = PSE_COMMAND_ELEMENT_CREATE;
            Data::set<0, PseTransform>(Cmd, InTransform);
            Data::set<40, PseClass>(Cmd, TPseClass);
            Data::set<42, PseCallback>(Cmd, 0);
            Data::set<50, PseState>(Cmd, InState);
            Data::set<51, int8_t>(Cmd, bVisibility ? 1 : 0);
            pseCommandBufferSinglePushAndWait(&Cmd);
            PSE_ASSERT(Cmd.header == PSE_RESULT_SUCCESS, "pse::Private::TypedElement<0x%X>::Create failed: 0x%X", TPseClass, Cmd.header);
            
            return TElement{ Data::get<0, PseGUID>(Cmd) };
        }
    	
        inline PseRegister ColorToRegister(const PseColor InColor)
        {
            return (static_cast<PseRegister>(InColor.r) << 16) |
                   (static_cast<PseRegister>(InColor.g) << 8)  |
                    static_cast<PseRegister>(InColor.b);
        }
        
        inline PseColor RegisterToColor(const PseRegister InRegister)
        {
            return PseColor
            {
                static_cast<uint8_t>((InRegister >> 16) & 0xFF),
                static_cast<uint8_t>((InRegister >> 8)  & 0xFF),
                static_cast<uint8_t>( InRegister        & 0xFF)
            };
        }
        
        inline PseRegister PackUInt16(const uint16_t InLow, const uint16_t InHigh)
        {
            return  (static_cast<PseRegister>(InLow ) & 0xFFFF) |
                   ((static_cast<PseRegister>(InHigh) & 0xFFFF) << 16);
        }
        
        inline uint16_t UnpackLowUInt16(const PseRegister InRegister)  { return static_cast<uint16_t>( InRegister        & 0xFFFF); }
        inline uint16_t UnpackHighUInt16(const PseRegister InRegister) { return static_cast<uint16_t>((InRegister >> 16) & 0xFFFF); }
        
        inline PseRegister PackInt16(const int16_t InLow, const int16_t InHigh)
        {
            return  (static_cast<PseRegister>(static_cast<uint16_t>(InLow )) & 0xFFFF) |
                   ((static_cast<PseRegister>(static_cast<uint16_t>(InHigh)) & 0xFFFF) << 16);
        }
        
        inline int16_t UnpackLowInt16(const PseRegister InRegister)  { return static_cast<int16_t>(static_cast<uint16_t>( InRegister        & 0xFFFF)); }
        inline int16_t UnpackHighInt16(const PseRegister InRegister) { return static_cast<int16_t>(static_cast<uint16_t>((InRegister >> 16) & 0xFFFF)); }
    }
}

// pse-sdk-cpp


namespace pse
{
    class AntiExpropriationFieldElement : public BaseElement
    {
    public:
        enum class ESolverGunMode : uint8_t
        {
            None    = 0,
            Switch  = 1,
            Enable  = 2,
            Disable = 3,
            Release = 4
        };
        
        static AntiExpropriationFieldElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_ANTI_EXPROPRIATION_FIELD, AntiExpropriationFieldElement>(InTransform, InState, bVisibility); }
        
        ESolverGunMode GetSolverGunMode() const
        {
            const uint8_t Value = Register::getBitsAs<uint8_t, 4>(GetRegister(0), 2);
            return (Value <= 4) ? static_cast<ESolverGunMode>(Value) : ESolverGunMode::None;
        }
        
        void SetSolverGunMode(const ESolverGunMode InMode) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 4>(Register, 2, static_cast<uint8_t>(InMode));
            SetRegister(0, Register);
        }
        
        bool GetKillPlayer() const { return (GetRegister(0) & 0x2) != 0; }
        void SetKillPlayer(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x2) : (Register & ~0x2)); }
        
        bool GetDestroyObjects() const { return (GetRegister(0) & 0x1) != 0; }
        void SetDestroyObjects(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColor() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColor(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        int16_t GetWidth() const  { return Private::UnpackLowInt16(GetRegister(2)); }
        int16_t GetHeight() const { return Private::UnpackHighInt16(GetRegister(2)); }
        
        void SetWidth(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(2);
            SetRegister(2, Private::PackInt16(InValue, Private::UnpackHighInt16(Register)));
        }
        
        void SetHeight(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(2);
            SetRegister(2, Private::PackInt16(Private::UnpackLowInt16(Register), InValue));
        }
    };
}

// pse-sdk-cpp


namespace pse
{
    class ButtonElement : public BaseElement
    {
    public:
        static ButtonElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_BUTTON, ButtonElement>(InTransform, InState, bVisibility); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class CubeDropperElement : public BaseElement
    {
    public:
        enum class ECubeType : uint8_t
        {
            WeightCube  = 0,
            LaserCube   = 1
        };
        
        static CubeDropperElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_CUBE_DROPPER, CubeDropperElement>(InTransform, InState, bVisibility); }
        
        bool GetRespawnOnDestroy() const { return (GetRegister(0) & 0x10) != 0; }
        void SetRespawnOnDestroy(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x10) : (Register & ~0x10)); }
        
        ECubeType GetCubeType() const
        {
            const uint8_t Value = Register::getBitsAs<uint8_t, 4>(GetRegister(0), 0);
            return (Value <= 1) ? static_cast<ECubeType>(Value) : ECubeType::WeightCube;
        }
        
        void SetCubeType(const ECubeType InCubeType) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 4>(Register, 0, static_cast<uint8_t>(InCubeType));
            SetRegister(0, Register);
        }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class DoorElement : public BaseElement
    {
    public:
        static DoorElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_DOOR, DoorElement>(InTransform, InState, bVisibility); }
        
        bool GetAutoClose() const { return (GetRegister(0) & 0x2) != 0; }
        void SetAutoClose(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x2) : (Register & ~0x2)); }
        
        bool GetCallbackHighlight() const { return (GetRegister(0) & 0x1) != 0; }
        void SetCallbackHighlight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class EntryElevatorElement : public BaseElement
    {
    public:
        static EntryElevatorElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_ENTRY_ELEVATOR, EntryElevatorElement>(InTransform, InState, bVisibility); }
        
        bool GetAutoClose() const { return (GetRegister(0) & 0x2) != 0; }
        void SetAutoClose(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x2) : (Register & ~0x2)); }
        
        bool GetCallbackHighlight() const { return (GetRegister(0) & 0x1) != 0; }
        void SetCallbackHighlight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class ExitElevatorElement : public BaseElement
    {
    public:
        static ExitElevatorElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_EXIT_ELEVATOR, ExitElevatorElement>(InTransform, InState, bVisibility); }
        
        bool GetAutoClose() const { return (GetRegister(0) & 0x2) != 0; }
        void SetAutoClose(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x2) : (Register & ~0x2)); }
        
        bool GetCallbackHighlight() const { return (GetRegister(0) & 0x1) != 0; }
        void SetCallbackHighlight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class FaithPlateElement : public BaseElement
    {
    public:
        static FaithPlateElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_FAITH_PLATE, FaithPlateElement>(InTransform, InState, bVisibility); }
        
        bool GetReleaseOnLanding() const { return (GetRegister(0) & 0x2) != 0; }
        void SetReleaseOnLanding(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x2) : (Register & ~0x2)); }
        
        bool GetUseGlobalCoordinates() const { return (GetRegister(0) & 0x1) != 0; }
        void SetUseGlobalCoordinates(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
        
        int16_t GetTargetX() const { return Private::UnpackLowInt16(GetRegister(3)); }
        int16_t GetTargetY() const { return Private::UnpackHighInt16(GetRegister(3)); }
        int16_t GetTargetZ() const { return Private::UnpackLowInt16(GetRegister(4)); }
        int16_t GetHeight()  const { return Private::UnpackHighInt16(GetRegister(4)); }
        
        void SetTargetX(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(3);
            SetRegister(3, Private::PackInt16(InValue, Private::UnpackHighInt16(Register)));
        }
        
        void SetTargetY(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(3);
            SetRegister(3, Private::PackInt16(Private::UnpackLowInt16(Register), InValue));
        }
        
        void SetTargetZ(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(4);
            SetRegister(4, Private::PackInt16(InValue, Private::UnpackHighInt16(Register)));
        }
        
        void SetHeight(const int16_t InValue) const
        {
            const PseRegister Register = GetRegister(4);
            SetRegister(4, Private::PackInt16(Private::UnpackLowInt16(Register), InValue));
        }
    };
}

// pse-sdk-cpp


namespace pse
{
    class FlashlightElement : public BaseElement
    {
    public:
        static FlashlightElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_FLASHLIGHT, FlashlightElement>(InTransform, InState, bVisibility); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class IndicatorElement : public BaseElement
    {
    public:
        static IndicatorElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_INDICATOR, IndicatorElement>(InTransform, InState, bVisibility); }
        
        bool GetFlatModel() const { return (GetRegister(0) & 0x2) != 0; }
        void SetFlatModel(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x2) : (Register & ~0x2)); }
        
        bool GetTimerMode() const { return (GetRegister(0) & 0x1) != 0; }
        void SetTimerMode(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class LampElement : public BaseElement
    {
    public:
        static LampElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_LAMP, LampElement>(InTransform, InState, bVisibility); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class LaserCubeElement : public BaseElement
    {
    public:
        static LaserCubeElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_LASER_CUBE, LaserCubeElement>(InTransform, InState, bVisibility); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class LaserPanelElement : public BaseElement
    {
    public:
        static LaserPanelElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_LASER_PANEL, LaserPanelElement>(InTransform, InState, bVisibility); }
        
        bool GetActiveVisual() const { return (GetRegister(0) & 0x40000000u) != 0; }
        void SetActiveVisual(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x40000000u) : (Register & ~0x40000000u)); }
        
        uint8_t GetMaxAngle() const { return Register::getBitsAs<uint8_t, 8>(GetRegister(0), 16); }
        void SetMaxAngle(const uint8_t InDegrees) const
        {
            const uint8_t Clamped = (InDegrees > 180) ? 180 : InDegrees;
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 8>(Register, 16, Clamped);
            SetRegister(0, Register);
        }
        
        uint8_t GetMinAngle() const
        {
            const uint8_t Value = Register::getBitsAs<uint8_t, 8>(GetRegister(0), 8);
            const uint8_t Max   = GetMaxAngle();
            return (Value > Max) ? Max : Value;
        }
        void SetMinAngle(const uint8_t InDegrees) const
        {
            const uint8_t Max     = GetMaxAngle();
            const uint8_t Clamped = (InDegrees > Max) ? Max : ((InDegrees > 180) ? 180 : InDegrees);
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 8>(Register, 8, Clamped);
            SetRegister(0, Register);
        }
        
        uint8_t GetAngle() const
        {
            const uint8_t Value = Register::getBitsAs<uint8_t, 8>(GetRegister(0), 0);
            const uint8_t Min   = GetMinAngle();
            const uint8_t Max   = GetMaxAngle();
            return (Value < Min) ? Min : ((Value > Max) ? Max : Value);
        }
        void SetAngle(const uint8_t InDegrees) const
        {
            const uint8_t Min     = GetMinAngle();
            const uint8_t Max     = GetMaxAngle();
            const uint8_t Clamped = (InDegrees < Min) ? Min : ((InDegrees > Max) ? Max : InDegrees);
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 8>(Register, 0, Clamped);
            SetRegister(0, Register);
        }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class LaserRelayElement : public BaseElement
    {
    public:
        static LaserRelayElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_LASER_RELAY, LaserRelayElement>(InTransform, InState, bVisibility); }
        
        bool GetColorFilterEnabled() const { return (GetRegister(0) & 0x80000000u) != 0; }
        void SetColorFilterEnabled(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x80000000u) : (Register & ~0x80000000u)); }
        
        PseColor GetLaserColor() const { return Private::RegisterToColor(GetRegister(0) & 0x00FFFFFFu); }
        void     SetLaserColor(const PseColor InColor) const { const PseRegister Register = GetRegister(0); SetRegister(0, (Register & 0xFF000000u) | Private::ColorToRegister(InColor)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class LaserRxElement : public BaseElement
    {
    public:
        static LaserRxElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_LASER_RX, LaserRxElement>(InTransform, InState, bVisibility); }
        
        bool GetModelShiftedDown() const { return (GetRegister(0) & 0x1) != 0; }
        void SetModelShiftedDown(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
        
        bool GetColorFilterEnabled() const { return (GetRegister(3) & 0x80000000u) != 0; }
        void SetColorFilterEnabled(const bool bValue) const { const PseRegister Register = GetRegister(3); SetRegister(3, bValue ? (Register | 0x80000000u) : (Register & ~0x80000000u)); }
        
        PseColor GetLaserColor() const { return Private::RegisterToColor(GetRegister(3) & 0x00FFFFFFu); }
        void     SetLaserColor(const PseColor InColor) const { const PseRegister Register = GetRegister(3); SetRegister(3, (Register & 0xFF000000u) | Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class LaserTxElement : public BaseElement
    {
    public:
        static LaserTxElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_LASER_TX, LaserTxElement>(InTransform, InState, bVisibility); }
        
        bool GetModelShiftedDown() const { return (GetRegister(0) & 0x1) != 0; }
        void SetModelShiftedDown(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetLaserColor() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetLaserColor(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class PanelElement : public BaseElement
    {
    public:
        enum class EAnimation : uint8_t
        {
            None        = 0,
            Front       = 1,
            FrontFront  = 2,
            FrontBack   = 3,
            Up          = 4,
            UpFront     = 5,
            UpBack      = 6
        };
        
        static PanelElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_PANEL, PanelElement>(InTransform, InState, bVisibility); }
        
        EAnimation GetAnimation() const
        {
            const uint8_t Value = Register::getInt<uint8_t>(GetRegister(0), 0);
            return (Value <= 6) ? static_cast<EAnimation>(Value) : EAnimation::None;
        }
        
        void SetAnimation(const EAnimation InAnimation) const
        {
            PseRegister Register = GetRegister(0);
            Register::setInt<uint8_t>(Register, 0, static_cast<uint8_t>(InAnimation));
            SetRegister(0, Register);
        }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class PedestalButtonElement : public BaseElement
    {
    public:
        enum class EButtonType : uint8_t
        {
            Switch  = 0,
            Click   = 1,
            Timer   = 2,
            Once    = 3
        };
        
        static PedestalButtonElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_PEDESTAL_BUTTON, PedestalButtonElement>(InTransform, InState, bVisibility); }
        
        EButtonType GetButtonType() const { return static_cast<EButtonType>(Register::getBitsAs<uint8_t, 2>(GetRegister(0), 0)); }
        void SetButtonType(const EButtonType InButtonType) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 2>(Register, 0, static_cast<uint8_t>(InButtonType));
            SetRegister(0, Register);
        }
        
        uint8_t GetTimerSeconds() const { return Register::getBitsAs<uint8_t, 7>(GetRegister(0), 2); }
        void SetTimerSeconds(const uint8_t InSeconds) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 7>(Register, 2, InSeconds);
            SetRegister(0, Register);
        }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class SolverButtonElement : public BaseElement
    {
    public:
        enum class EButtonType : uint8_t
        {
            Switch  = 0,
            Click   = 1,
            Timer   = 2,
            Once    = 3
        };
        
        static SolverButtonElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_SOLVER_BUTTON, SolverButtonElement>(InTransform, InState, bVisibility); }
        
        EButtonType GetButtonType() const { return static_cast<EButtonType>(Register::getBitsAs<uint8_t, 2>(GetRegister(0), 0)); }
        void SetButtonType(const EButtonType InButtonType) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 2>(Register, 0, static_cast<uint8_t>(InButtonType));
            SetRegister(0, Register);
        }
        
        uint8_t GetTimerSeconds() const { return Register::getBitsAs<uint8_t, 7>(GetRegister(0), 2); }
        void SetTimerSeconds(const uint8_t InSeconds) const
        {
            PseRegister Register = GetRegister(0);
            Register::setBitsAs<uint8_t, 7>(Register, 2, InSeconds);
            SetRegister(0, Register);
        }
        
        bool GetFlatModel() const { return (GetRegister(0) & 0x200) != 0; }
        void SetFlatModel(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x200) : (Register & ~0x200)); }
        
        bool GetCallbackGreenHighlight() const { return (GetRegister(0) & 0x400) != 0; }
        void SetCallbackGreenHighlight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x400) : (Register & ~0x400)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class SolverGunPedestalElement : public BaseElement
    {
    public:
        static SolverGunPedestalElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_SOLVER_GUN_PEDESTAL, SolverGunPedestalElement>(InTransform, InState, bVisibility); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class StairsElement : public BaseElement
    {
    public:
        static StairsElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_STAIRS, StairsElement>(InTransform, InState, bVisibility); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


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

// pse-sdk-cpp


namespace pse
{
    class WeightCubeElement : public BaseElement
    {
    public:
        static WeightCubeElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_WEIGHT_CUBE, WeightCubeElement>(InTransform, InState, bVisibility); }
        
        bool GetCallbackHighlight() const { return (GetRegister(0) & 0x1) != 0; }
        void SetCallbackHighlight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x1) : (Register & ~0x1)); }
        
        PseColor GetColorActivated() const { return Private::RegisterToColor(GetRegister(1)); }
        void     SetColorActivated(const PseColor InColor) const { SetRegister(1, Private::ColorToRegister(InColor)); }
        
        PseColor GetColorDeactivated() const { return Private::RegisterToColor(GetRegister(2)); }
        void     SetColorDeactivated(const PseColor InColor) const { SetRegister(2, Private::ColorToRegister(InColor)); }
    };
}

// pse-sdk-cpp


namespace pse
{
    class WindowElement : public BaseElement
    {
    public:
        static WindowElement Create(const PseTransform& InTransform, const PseState InState = 0, const bool bVisibility = true) { return Private::CreateElement<PSE_CLASS_WINDOW, WindowElement>(InTransform, InState, bVisibility); }
        
        PseMaterial GetCentralMaterial() const { return Register::getInt<PseMaterial>(GetRegister(0), 16); }
        void SetCentralMaterial(const PseMaterial InMaterial) const
        {
            PseRegister Register = GetRegister(0);
            Register::setInt<PseMaterial>(Register, 16, InMaterial);
            SetRegister(0, Register);
        }
        
        bool GetShowBottomRight() const { return (GetRegister(0) & 0x0100) != 0; }
        void SetShowBottomRight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0100) : (Register & ~0x0100)); }
        
        bool GetShowBottomLeft() const { return (GetRegister(0) & 0x0080) != 0; }
        void SetShowBottomLeft(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0080) : (Register & ~0x0080)); }
        
        bool GetShowTopRight() const { return (GetRegister(0) & 0x0040) != 0; }
        void SetShowTopRight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0040) : (Register & ~0x0040)); }
        
        bool GetShowTopLeft() const { return (GetRegister(0) & 0x0020) != 0; }
        void SetShowTopLeft(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0020) : (Register & ~0x0020)); }
        
        bool GetShowRight() const { return (GetRegister(0) & 0x0010) != 0; }
        void SetShowRight(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0010) : (Register & ~0x0010)); }
        
        bool GetShowLeft() const { return (GetRegister(0) & 0x0008) != 0; }
        void SetShowLeft(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0008) : (Register & ~0x0008)); }
        
        bool GetShowBottom() const { return (GetRegister(0) & 0x0004) != 0; }
        void SetShowBottom(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0004) : (Register & ~0x0004)); }
        
        bool GetShowTop() const { return (GetRegister(0) & 0x0002) != 0; }
        void SetShowTop(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0002) : (Register & ~0x0002)); }
        
        bool GetShowCenter() const { return (GetRegister(0) & 0x0001) != 0; }
        void SetShowCenter(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0001) : (Register & ~0x0001)); }
        
        bool GetPassSolverRays() const { return (GetRegister(0) & 0x0200) != 0; }
        void SetPassSolverRays(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0200) : (Register & ~0x0200)); }
        
        bool GetPassLaserRays() const { return (GetRegister(0) & 0x0400) != 0; }
        void SetPassLaserRays(const bool bValue) const { const PseRegister Register = GetRegister(0); SetRegister(0, bValue ? (Register | 0x0400) : (Register & ~0x0400)); }
        
        uint16_t GetWidth() const  { return Private::UnpackLowUInt16(GetRegister(1)); }
        uint16_t GetHeight() const { return Private::UnpackHighUInt16(GetRegister(1)); }
        
        void SetWidth(const uint16_t InWidth) const
        {
            const PseRegister Register = GetRegister(1);
            SetRegister(1, Private::PackUInt16(InWidth, Private::UnpackHighUInt16(Register)));
        }
        
        void SetHeight(const uint16_t InHeight) const
        {
            const PseRegister Register = GetRegister(1);
            SetRegister(1, Private::PackUInt16(Private::UnpackLowUInt16(Register), InHeight));
        }
    };
}

