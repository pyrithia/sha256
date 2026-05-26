#include "sha256.h"

uint32_t rotr(uint32_t A, int n) { return (A >> n) | (A << (32 - n)); }
