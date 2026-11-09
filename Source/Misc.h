// pse-sdk-cpp

#pragma once

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
