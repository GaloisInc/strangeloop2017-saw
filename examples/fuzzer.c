#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  int bits = 0;
  if (Size > 0 && Data[0] == 'F') bits |= 1;
  if (Size > 1 && Data[1] == 'U') bits |= 2;
  if (Size > 2 && Data[2] == 'Z') bits |= 4;
  if (Size > 3 && Data[3] == 'Z') bits |= 8;
  if (Size > 4 && Data[4] == 'E') bits |= 16;
  if (Size > 5 && Data[5] == 'R') bits |= 32;
  if (bits == 63) {
    assert(0);
  }
  return 0;
}
