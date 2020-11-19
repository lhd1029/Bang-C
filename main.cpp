#include "cnrt.h"
typedef unsigned short half;
void foo2(half val);
int main(void) {
  cnrtInit(0);
  cnrtDev_t dev;
  cnrtGetDeviceHandle(&dev, 0);
  cnrtSetCurrentDevice(dev);
  half val = 0;
  cnrtConvertFloatToHalf(&val, 3.14);
  cnrtDim3_t dim = {4, 1, 1};
  cnrtFunctionType_t ktype = CNRT_FUNC_TYPE_UNION1;
  cnrtKernelParamsBuffer_t params;
  cnrtGetKernelParamsBuffer(&params);
  cnrtKernelParamsBufferAddParam(params, &val, sizeof(val));
  cnrtQueue_t queue;
  CNRT_CHECK(cnrtCreateQueue(&queue));
  CNRT_CHECK(cnrtInvokeKernel_V2(reinterpret_cast<void**>(&foo2), dim, params, ktype, queue));
  cnrtSyncQueue(queue);
  cnrtDestroy();
  return 0;
}