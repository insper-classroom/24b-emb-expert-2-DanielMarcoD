/*
 * Copyright (c) 2024 EdgeImpulse Inc.
 *
 * Generated by Edge Impulse and licensed under the applicable Edge Impulse
 * Terms of Service. Community and Professional Terms of Service
 * (https://docs.edgeimpulse.com/page/terms-of-service) or Enterprise Terms of
 * Service (https://docs.edgeimpulse.com/page/enterprise-terms-of-service),
 * according to your product plan subscription (the “License”).
 *
 * This software, documentation and other associated files (collectively referred
 * to as the “Software”) is a single SDK variation generated by the Edge Impulse
 * platform and requires an active paid Edge Impulse subscription to use this
 * Software for any purpose.
 *
 * You may NOT use this Software unless you have an active Edge Impulse subscription
 * that meets the eligibility requirements for the applicable License, subject to
 * your full and continued compliance with the terms and conditions of the License,
 * including without limitation any usage restrictions under the applicable License.
 *
 * If you do not have an active Edge Impulse product plan subscription, or if use
 * of this Software exceeds the usage limitations of your Edge Impulse product plan
 * subscription, you are not permitted to use this Software and must immediately
 * delete and erase all copies of this Software within your control or possession.
 * Edge Impulse reserves all rights and remedies available to enforce its rights.
 *
 * Unless required by applicable law or agreed to in writing, the Software is
 * distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing
 * permissions, disclaimers and limitations under the License.
 */
// Generated on: 07.11.2024 19:49:51

#include <stdio.h>
#include <stdlib.h>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined (__GNUC__)  /* GNU compiler */
#define ALIGN(X) __attribute__((aligned(X)))
#define DEFINE_SECTION(x) __attribute__((section(x)))
#elif defined (_MSC_VER)
#define ALIGN(X) __declspec(align(X))
#elif defined (__TASKING__) /* TASKING Compiler */
#define ALIGN(X) __align(X)
#define DEFINE_SECTION(x) __attribute__(section(x)))
#elif defined (__ARMCC_VERSION) /* Arm Compiler */
#define ALIGN(X) __ALIGNED(x)
#define DEFINE_SECTION(x) __attribute__((section(x)))
#elif defined (__ICCARM__) /* IAR Compiler */
#define ALIGN(x) __attribute__((aligned(x)))
#define DEFINE_SECTION(x) __attribute__((section(x)))
#elif defined (__clang__) /* LLVM/Clang Compiler */
#define ALIGN(X) __ALIGNED(x)
#define DEFINE_SECTION(x) __attribute__((section(x)))
#endif

#ifndef EI_MAX_SCRATCH_BUFFER_COUNT
#ifndef CONFIG_IDF_TARGET_ESP32S3
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#else
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#endif // CONFIG_IDF_TARGET_ESP32S3
#endif // EI_MAX_SCRATCH_BUFFER_COUNT

#ifndef EI_MAX_OVERFLOW_BUFFER_COUNT
#define EI_MAX_OVERFLOW_BUFFER_COUNT 10
#endif // EI_MAX_OVERFLOW_BUFFER_COUNT

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX) || defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
constexpr int kTensorArenaSize = 1408;
#else
constexpr int kTensorArenaSize = 384;
#endif

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
#if defined (EI_TENSOR_ARENA_LOCATION)
#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) DEFINE_SECTION(STRINGIZE_VALUE_OF(EI_TENSOR_ARENA_LOCATION));
#else
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#endif
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};

enum used_operators_e {
  OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};

struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};

typedef struct {
  TfLiteTensor tensor;
  int16_t index;
} TfLiteTensorWithIndex;

typedef struct {
  TfLiteEvalTensor tensor;
  int16_t index;
} TfLiteEvalTensorWithIndex;

TfLiteContext ctx{};
static const int MAX_TFL_TENSOR_COUNT = 4;
static TfLiteTensorWithIndex tflTensors[MAX_TFL_TENSOR_COUNT];
static const int MAX_TFL_EVAL_COUNT = 4;
static TfLiteEvalTensorWithIndex tflEvalTensors[MAX_TFL_EVAL_COUNT];
TfLiteRegistration registrations[OP_LAST];

namespace g0 {
const TfArray<2, int> tensor_dimension0 = { 2, { 1,39 } };
const TfArray<1, float> quant0_scale = { 1, { 35.120975494384766, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[3] = { 0, 0, 0, };
const TfArray<1, int> tensor_dimension1 = { 1, { 3 } };
const TfArray<1, float> quant1_scale = { 1, { 0.077242031693458557, } };
const TfArray<1, int> quant1_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant1 = { (TfLiteFloatArray*)&quant1_scale, (TfLiteIntArray*)&quant1_zero, 0 };
const ALIGN(16) int8_t tensor_data2[3*10] = { 
  69, -5, 106, -101, -44, 55, 86, -101, -127, 85, 
  73, 80, -23, -73, -116, 10, 38, -94, 16, -19, 
  -99, -1, 123, 0, -106, -94, -99, -54, 118, 34, 
};
const TfArray<2, int> tensor_dimension2 = { 2, { 3,10 } };
const TfArray<1, float> quant2_scale = { 1, { 0.0053994166664779186, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(16) int32_t tensor_data3[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension3 = { 1, { 10 } };
const TfArray<1, float> quant3_scale = { 1, { 0.048415299504995346, } };
const TfArray<1, int> quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(16) int8_t tensor_data4[10*20] = { 
  44, -84, -77, 14, 104, 21, 120, -121, -10, -58, 18, 19, 72, 122, 52, -89, -4, -28, -76, 27, 
  -61, -124, 79, 73, 63, -34, -51, -104, -96, 20, -66, -50, 77, 24, 79, 97, -53, 37, -48, -33, 
  -25, -105, -3, 114, -52, -64, -39, 22, -44, -12, 35, 55, -23, -93, -14, -76, 91, -106, -109, -88, 
  64, 15, 107, 4, -67, 82, -59, -42, -26, 76, 114, 56, -80, -101, 4, -49, -25, -58, 115, 91, 
  -49, 65, -105, -46, -92, 76, -39, 29, -100, 66, 98, 62, -22, 54, 27, -103, -53, 109, 79, 62, 
  -95, 76, -75, 55, -33, -126, -7, 85, -126, -51, 84, 65, -55, 68, -26, -73, -40, 67, -73, 4, 
  100, 51, -67, -85, 84, 88, 10, -42, -31, 0, 62, 43, -71, -45, 4, -19, 61, -19, -17, -38, 
  -16, 99, 54, 67, -8, 91, 98, -113, 127, -36, -57, 124, 67, -28, -101, 54, 97, 6, 15, 91, 
  68, 44, 66, 44, 101, 38, -112, -20, -27, 10, 109, 29, -2, -113, -28, 104, -91, 77, -51, -35, 
  48, -78, -25, -2, 80, 103, -29, 3, 78, -104, -70, 45, -90, -59, 52, -20, -23, 96, 3, 84, 
};
const TfArray<2, int> tensor_dimension4 = { 2, { 10,20 } };
const TfArray<1, float> quant4_scale = { 1, { 0.0035314166452735662, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(16) int32_t tensor_data5[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension5 = { 1, { 20 } };
const TfArray<1, float> quant5_scale = { 1, { 0.11267756670713425, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(16) int8_t tensor_data6[20*39] = { 
  0, -14, -22, 81, 28, 48, 28, -63, 32, -78, -3, 35, -87, -64, -21, 86, 24, 71, -47, -47, 84, -25, 81, 17, -90, 62, -48, -48, -68, -88, 23, 30, 59, -81, -92, 42, -61, 70, -9, 
  -96, -7, 80, 12, -29, 16, 31, 29, 43, 90, -63, 41, 13, 18, 60, -53, 76, 48, 99, -59, -16, -10, 81, -19, 50, 47, -18, 71, -24, -72, -15, 91, 84, 95, 67, -31, -78, -9, 26, 
  72, -20, -96, -65, 48, -46, 66, 88, 99, -4, -69, 21, -66, 56, -60, 68, 36, 63, 7, 47, 103, -86, 59, -72, 17, -20, 97, 46, -49, -73, -44, 68, 53, -68, -16, -29, -81, -3, 60, 
  -81, 51, -52, 58, -8, 57, -10, 95, 49, -83, 80, 78, 48, 60, 42, -22, -75, -48, 33, 62, -64, 40, -63, -37, 59, 50, -70, 58, 82, 64, -44, 41, 82, -44, 59, 12, 96, -94, 18, 
  74, 26, 22, -66, -83, -78, 78, -28, -51, 54, -33, 14, -66, -46, -56, 36, 53, 61, -13, -27, -15, 86, -24, -20, -36, 0, 70, 73, -97, -80, 46, -67, 84, -74, -35, -52, -34, -94, 17, 
  -35, 67, 31, -6, -35, -81, 7, 95, -41, 19, -94, -38, -100, 39, -10, 41, -92, 24, -34, 5, -79, -84, -12, -51, 70, -28, 21, -28, -29, 92, -27, -12, 74, -61, 21, -93, 66, -58, 39, 
  39, -21, -24, -60, -68, -103, -39, 64, -40, 3, -10, -13, -5, 49, 46, -21, -45, -56, 90, 70, -53, 13, -50, 58, -45, -15, 95, -78, 76, 21, 61, -95, -3, -16, -81, 53, -93, 36, -83, 
  77, -127, 44, 90, 91, 34, 32, 45, -26, 87, -16, 99, -30, 37, -95, -63, -29, -49, -62, 96, 86, -59, -48, 3, -17, 99, -28, 14, -80, -15, 12, 95, 26, -81, -30, -86, -12, 32, 72, 
  42, 90, 69, -22, -91, 53, -19, -65, -15, -23, 0, 53, 50, -49, -9, 7, 33, -55, 89, 12, 83, 59, 81, 34, 54, 56, 61, -19, 97, -95, 42, -99, -19, -6, -85, -32, -90, 78, -70, 
  -87, 41, -88, -10, -61, 55, -94, -4, -58, -103, -88, -71, -103, -30, -63, 78, -14, 54, 66, -67, -24, 59, 15, 88, 95, 63, 1, 33, -7, 41, -46, -32, -76, -7, 65, 26, 63, 71, -18, 
  103, 4, 52, -84, -67, -29, 68, 27, 5, 43, -64, 40, 37, -67, 30, -43, 8, 8, 46, 32, -73, 57, -80, 88, 92, -7, -36, -42, 81, 78, -85, -67, -67, -10, 109, 98, -17, -66, -66, 
  -11, 16, 85, -30, -74, -88, 98, -39, 72, -24, 84, 90, 62, 87, -65, 77, -42, -36, 88, 2, -23, -22, 93, 3, 29, 38, 57, 43, 106, 33, -16, -23, 2, -42, 25, -24, -70, 23, 24, 
  -37, -94, -16, -32, 61, -82, -57, -94, -78, 49, -21, -90, 26, 63, -1, 17, 15, -28, 86, -24, 48, 58, -60, 63, 51, -30, 13, -28, 53, -20, -31, 24, -96, 88, 60, 60, 78, -66, -84, 
  22, -98, -53, -6, 87, 95, -84, 91, -15, 22, 18, 25, 86, 25, -18, -69, -100, -17, -81, -38, -77, -79, -6, -33, -43, -100, -68, 86, -17, 6, 29, -97, -74, -96, -15, 23, 43, -8, 79, 
  81, -71, -66, 9, -4, -69, -54, 23, 36, 23, 85, -108, -95, 86, -89, -53, -97, 4, 45, -88, 72, 85, -60, 61, -103, -69, -24, -70, 65, -37, 91, -64, -55, 50, -26, -76, -89, 12, 68, 
  0, 83, -73, -93, -92, 27, -12, 16, 36, 33, -6, 38, -55, 46, 46, 76, 16, 44, 35, 58, -90, 83, -80, 43, 23, 1, -44, -36, -19, -54, 26, -34, -35, 52, -8, 21, 0, -91, 25, 
  -4, -64, -34, -13, 74, -29, -39, -77, 30, -92, -92, -37, 17, 42, -32, 41, -83, -54, 37, -38, -88, -63, 32, -48, 35, -38, -23, 81, -74, 65, 29, -6, 71, -65, -35, -58, 24, -90, -50, 
  -19, 49, 88, 70, 72, -31, -38, 82, 34, -13, -35, 96, -35, 70, -71, -33, -69, 26, 91, -54, 53, -42, -73, 97, -53, -77, -50, 32, -7, -57, -13, -75, 3, 24, 9, 97, 94, -53, 69, 
  -83, -25, 52, -96, 48, 8, -64, -9, -3, -35, -91, -38, -84, -70, -74, -52, 6, -58, -54, 38, -49, 82, -54, 78, -43, -86, -4, -28, -88, -68, 46, -43, -63, -89, 97, 78, 27, -66, -76, 
  -3, 74, 5, -48, -17, -32, 29, -13, 71, 67, -80, 78, 68, -1, -2, -40, -3, -83, -53, 27, -37, -91, 78, -78, -7, 3, -64, -42, 35, 78, -69, 15, 83, -62, 9, 34, -90, 21, 6, 
};
const TfArray<2, int> tensor_dimension6 = { 2, { 20,39 } };
const TfArray<1, float> quant6_scale = { 1, { 0.0032082698307931423, } };
const TfArray<1, int> quant6_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const TfArray<2, int> tensor_dimension7 = { 2, { 1,20 } };
const TfArray<1, float> quant7_scale = { 1, { 13.709880828857422, } };
const TfArray<1, int> quant7_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const TfArray<2, int> tensor_dimension8 = { 2, { 1,10 } };
const TfArray<1, float> quant8_scale = { 1, { 14.305624961853027, } };
const TfArray<1, int> quant8_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const TfArray<2, int> tensor_dimension9 = { 2, { 1,3 } };
const TfArray<1, float> quant9_scale = { 1, { 6.0464811325073242, } };
const TfArray<1, int> quant9_zero = { 1, { 126 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const TfArray<2, int> tensor_dimension10 = { 2, { 1,3 } };
const TfArray<1, float> quant10_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant10_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const TfLiteFullyConnectedParams opdata0 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs0 = { 3, { 0,6,5 } };
const TfArray<1, int> outputs0 = { 1, { 7 } };
const TfLiteFullyConnectedParams opdata1 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs1 = { 3, { 7,4,3 } };
const TfArray<1, int> outputs1 = { 1, { 8 } };
const TfLiteFullyConnectedParams opdata2 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs2 = { 3, { 8,2,1 } };
const TfArray<1, int> outputs2 = { 1, { 9 } };
const TfLiteSoftmaxParams opdata3 = { 1 };
const TfArray<1, int> inputs3 = { 1, { 9 } };
const TfArray<1, int> outputs3 = { 1, { 10 } };
};

TensorInfo_t tensorData[] = {
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension0, 39, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant0))}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data1, (TfLiteIntArray*)&g0::tensor_dimension1, 12, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant1))}, },
{ kTfLiteMmapRo, kTfLiteInt8, (int32_t*)g0::tensor_data2, (TfLiteIntArray*)&g0::tensor_dimension2, 30, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant2))}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data3, (TfLiteIntArray*)&g0::tensor_dimension3, 40, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant3))}, },
{ kTfLiteMmapRo, kTfLiteInt8, (int32_t*)g0::tensor_data4, (TfLiteIntArray*)&g0::tensor_dimension4, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant4))}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data5, (TfLiteIntArray*)&g0::tensor_dimension5, 80, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant5))}, },
{ kTfLiteMmapRo, kTfLiteInt8, (int32_t*)g0::tensor_data6, (TfLiteIntArray*)&g0::tensor_dimension6, 780, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant6))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 48), (TfLiteIntArray*)&g0::tensor_dimension7, 20, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant7))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension8, 10, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant8))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 16), (TfLiteIntArray*)&g0::tensor_dimension9, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant9))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension10, 3, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant10))}, },
};

#ifndef TF_LITE_STATIC_MEMORY
TfLiteNode tflNodes[4] = {
{ (TfLiteIntArray*)&g0::inputs0, (TfLiteIntArray*)&g0::outputs0, (TfLiteIntArray*)&g0::inputs0, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata0)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs1, (TfLiteIntArray*)&g0::outputs1, (TfLiteIntArray*)&g0::inputs1, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata1)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs2, (TfLiteIntArray*)&g0::outputs2, (TfLiteIntArray*)&g0::inputs2, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata2)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs3, (TfLiteIntArray*)&g0::outputs3, (TfLiteIntArray*)&g0::inputs3, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata3)), nullptr, 0, },
};
#else
TfLiteNode tflNodes[4] = {
{ (TfLiteIntArray*)&g0::inputs0, (TfLiteIntArray*)&g0::outputs0, (TfLiteIntArray*)&g0::inputs0, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata0)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs1, (TfLiteIntArray*)&g0::outputs1, (TfLiteIntArray*)&g0::inputs1, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata1)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs2, (TfLiteIntArray*)&g0::outputs2, (TfLiteIntArray*)&g0::inputs2, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata2)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs3, (TfLiteIntArray*)&g0::outputs3, (TfLiteIntArray*)&g0::inputs3, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata3)), nullptr, 0, },
};
#endif

used_operators_e used_ops[] =
{OP_FULLY_CONNECTED, OP_FULLY_CONNECTED, OP_FULLY_CONNECTED, OP_SOFTMAX, };


// Indices into tflTensors and tflNodes for subgraphs
const size_t tflTensors_subgraph_index[] = {0, 11, };
const size_t tflNodes_subgraph_index[] = {0, 4, };

// Input/output tensors
static const int in_tensor_indices[] = {
  0, 
};

static const int out_tensor_indices[] = {
  10, 
};


size_t current_subgraph_index = 0;

static void init_tflite_tensor(size_t i, TfLiteTensor *tensor) {
  tensor->type = tensorData[i].type;
  tensor->is_variable = false;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  tensor->allocation_type = tensorData[i].allocation_type;
#else
  tensor->allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
  tensor->bytes = tensorData[i].bytes;
  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  if(tensor->allocation_type == kTfLiteArenaRw){
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
      tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
  tensor->quantization = tensorData[i].quantization;
  if (tensor->quantization.type == kTfLiteAffineQuantization) {
    TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
    tensor->params.scale = quant->scale->data[0];
    tensor->params.zero_point = quant->zero_point->data[0];
  }

}

static void init_tflite_eval_tensor(int i, TfLiteEvalTensor *tensor) {

  tensor->type = tensorData[i].type;

  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  auto allocation_type = tensorData[i].allocation_type;
  if(allocation_type == kTfLiteArenaRw) {
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
    tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
}

static void* overflow_buffers[EI_MAX_OVERFLOW_BUFFER_COUNT];
static size_t overflow_buffers_ix = 0;
static void * AllocatePersistentBufferImpl(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  uint32_t align_bytes = (bytes % 16) ? 16 - (bytes % 16) : 0;

  if (current_location - (bytes + align_bytes) < tensor_boundary) {
    if (overflow_buffers_ix > EI_MAX_OVERFLOW_BUFFER_COUNT - 1) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d, does not fit in tensor arena and reached EI_MAX_OVERFLOW_BUFFER_COUNT\n",
        (int)bytes);
      return NULL;
    }

    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers[overflow_buffers_ix++] = ptr;
    return ptr;
  }

  current_location -= bytes;

  // align to the left aligned boundary of 16 bytes
  current_location -= 15; // for alignment
  current_location += 16 - ((uintptr_t)(current_location) & 15);

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}

typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;

static scratch_buffer_t scratch_buffers[EI_MAX_SCRATCH_BUFFER_COUNT];
static size_t scratch_buffers_ix = 0;

static TfLiteStatus RequestScratchBufferInArenaImpl(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  if (scratch_buffers_ix > EI_MAX_SCRATCH_BUFFER_COUNT - 1) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d, reached EI_MAX_SCRATCH_BUFFER_COUNT\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBufferImpl(ctx, b.bytes);
  if (!b.ptr) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffers[scratch_buffers_ix] = b;
  *buffer_idx = scratch_buffers_ix;

  scratch_buffers_ix++;

  return kTfLiteOk;
}

static void* GetScratchBufferImpl(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > (int)scratch_buffers_ix) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static const uint16_t TENSOR_IX_UNUSED = 0x7FFF;

static void ResetTensors() {
  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    tflTensors[ix].index = TENSOR_IX_UNUSED;
  }
  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    tflEvalTensors[ix].index = TENSOR_IX_UNUSED;
  }
}

static TfLiteTensor* GetTensorImpl(const struct TfLiteContext* context,
                               int tensor_idx) {

  tensor_idx = tflTensors_subgraph_index[current_subgraph_index] + tensor_idx;

  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    // already used? OK!
    if (tflTensors[ix].index == tensor_idx) {
      return &tflTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_tensor(tensor_idx, &tflTensors[ix].tensor);
      tflTensors[ix].index = tensor_idx;
      return &tflTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_TENSOR_COUNT (%d)\n", MAX_TFL_TENSOR_COUNT);
  return nullptr;
}

static TfLiteEvalTensor* GetEvalTensorImpl(const struct TfLiteContext* context,
                                       int tensor_idx) {

  tensor_idx = tflTensors_subgraph_index[current_subgraph_index] + tensor_idx;

  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    // already used? OK!
    if (tflEvalTensors[ix].index == tensor_idx) {
      return &tflEvalTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflEvalTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_eval_tensor(tensor_idx, &tflEvalTensors[ix].tensor);
      tflEvalTensors[ix].index = tensor_idx;
      return &tflEvalTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_EVAL_COUNT (%d)\n", (int)MAX_TFL_EVAL_COUNT);
  return nullptr;
}

class EonMicroContext : public MicroContext {
 public:
 
  EonMicroContext(): MicroContext(nullptr, nullptr, nullptr) { }

  void* AllocatePersistentBuffer(size_t bytes) {
    return AllocatePersistentBufferImpl(nullptr, bytes);
  }

  TfLiteStatus RequestScratchBufferInArena(size_t bytes,
                                           int* buffer_index) {
  return RequestScratchBufferInArenaImpl(nullptr, bytes, buffer_index);
  }

  void* GetScratchBuffer(int buffer_index) {
    return GetScratchBufferImpl(nullptr, buffer_index);
  }
 
  TfLiteTensor* AllocateTempTfLiteTensor(int tensor_index) {
    return GetTensorImpl(nullptr, tensor_index);
  }

  void DeallocateTempTfLiteTensor(TfLiteTensor* tensor) {
    return;
  }

  bool IsAllTempTfLiteTensorDeallocated() {
    return true;
  }

  TfLiteEvalTensor* GetEvalTensor(int tensor_index) {
    return GetEvalTensorImpl(nullptr, tensor_index);
  }

};


} // namespace

TfLiteStatus tflite_learn_4_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    ei_printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;

  EonMicroContext micro_context_;
  
  // Set microcontext as the context ptr
  ctx.impl_ = static_cast<void*>(&micro_context_);
  // Setup tflitecontext functions
  ctx.AllocatePersistentBuffer = &AllocatePersistentBufferImpl;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArenaImpl;
  ctx.GetScratchBuffer = &GetScratchBufferImpl;
  ctx.GetTensor = &GetTensorImpl;
  ctx.GetEvalTensor = &GetEvalTensorImpl;
  ctx.ReportError = &MicroContextReportOpError;

  ctx.tensors_size = 11;
  for (size_t i = 0; i < 11; ++i) {
    TfLiteTensor tensor;
    init_tflite_tensor(i, &tensor);
    if (tensor.allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tensor.data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }

  if (tensor_boundary > current_location /* end of arena size */) {
    ei_printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }

  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for (size_t g = 0; g < 1; ++g) {
    current_subgraph_index = g;
    for(size_t i = tflNodes_subgraph_index[g]; i < tflNodes_subgraph_index[g+1]; ++i) {
      if (registrations[used_ops[i]].init) {
        tflNodes[i].user_data = registrations[used_ops[i]].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
      }
    }
  }
  current_subgraph_index = 0;

  for(size_t g = 0; g < 1; ++g) {
    current_subgraph_index = g;
    for(size_t i = tflNodes_subgraph_index[g]; i < tflNodes_subgraph_index[g+1]; ++i) {
      if (registrations[used_ops[i]].prepare) {
        ResetTensors();
        TfLiteStatus status = registrations[used_ops[i]].prepare(&ctx, &tflNodes[i]);
        if (status != kTfLiteOk) {
          return status;
        }
      }
    }
  }
  current_subgraph_index = 0;

  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_input(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(in_tensor_indices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_output(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(out_tensor_indices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_invoke() {
  for (size_t i = 0; i < 4; ++i) {
    ResetTensors();

    TfLiteStatus status = registrations[used_ops[i]].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif

  // scratch buffers are allocated within the arena, so just reset the counter so memory can be reused
  scratch_buffers_ix = 0;

  // overflow buffers are on the heap, so free them first
  for (size_t ix = 0; ix < overflow_buffers_ix; ix++) {
    ei_free(overflow_buffers[ix]);
  }
  overflow_buffers_ix = 0;
  return kTfLiteOk;
}
