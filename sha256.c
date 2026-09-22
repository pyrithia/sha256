#include "sha256.h"

uint32_t rotr(uint32_t A, int n) { return (A >> n) | (A << (32 - n)); }

uint32_t shr(uint32_t A, int n) { return (A >> n); }

uint32_t sigma0(uint32_t A) { return rotr(A, 7) ^ rotr(A, 18) ^ shr(A, 3); }

uint32_t sigma1(uint32_t A) { return rotr(A, 17) ^ rotr(A, 19) ^ shr(A, 10); }

uint32_t SIGMA0(uint32_t A) { return rotr(A, 2) ^ rotr(A, 13) ^ rotr(A, 22); }

uint32_t SIGMA1(uint32_t A) { return rotr(A, 6) ^ rotr(A, 11) ^ rotr(A, 25); }
