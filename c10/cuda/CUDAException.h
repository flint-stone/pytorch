#pragma once

#include <c10/util/Exception.h>
#include <c10/macros/Macros.h>
#include <c10/util/Logging.h>
#include <cuda.h>

// Note [CHECK macro]
// ~~~~~~~~~~~~~~~~~~
// This is a macro so that AT_ERROR can get accurate __LINE__
// and __FILE__ information.  We could split this into a short
// macro and a function implementation if we pass along __LINE__
// and __FILE__, but no one has found this worth doing.

// For CUDA Runtime API
#define C10_CUDA_CHECK(EXPR)                                         \
  do {                                                               \
    cudaError_t __err = EXPR;                                        \
    if (__err != cudaSuccess) {                                      \
      auto error_unused C10_UNUSED = cudaGetLastError();             \
      TORCH_CHECK(false, "CUDA error: ", cudaGetErrorString(__err)); \
    }                                                                \
  } while (0)

  #define C10_CUDA_CHECK_WARN(EXPR)                            \
  do {                                                         \
    cudaError_t __err = EXPR;                                  \
    if (__err != cudaSuccess) {                                \
      auto error_unused C10_UNUSED = cudaGetLastError();       \
      TORCH_WARN("CUDA warning: ", cudaGetErrorString(__err)); \
    }                                                          \
  } while (0)

static printCurrentContext(){
	CUresult result;
	CUContext cuContext;
	result = cuCtxGetCurrent(&cuContext);
	if (result == CUDA_SUCCESS){
		result = cuCtxPopCurrent(&cuContext);
		LOG(WARNING) << "pop context current " << cuContext;
	}
}