#pragma once
#include <stdbool.h>

#include <config/config.h>
//#include "cpu_features/cpu_features_types.h"
#include "cpuinfo_aarch64.h"
#include "cpuinfo_x86.h"

typedef enum { SIMD_SSE3, SIMD_SSE4_1, SIMD_SSE4_2, SIMD_AVX, SIMD_AVX2, SIMD_NEON } SimdIntrinsic;

typedef struct {
    char mName[512];
    SimdIntrinsic mSimd;

    cpu_features::X86Features mFeaturesX86;
    cpu_features::X86Microarchitecture mArchitectureX86;

    cpu_features::Aarch64Features mFeaturesAarch64;
} CpuInfo;

#if defined(ANDROID)
#include <jni.h>
bool initCpuInfo(CpuInfo *outCpuInfo, JNIEnv *pJavaEnv);
#else
bool initCpuInfo(CpuInfo *outCpuInfo);
#endif

CpuInfo *getCpuInfo(void);