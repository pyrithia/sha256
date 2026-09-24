#pragma once
#include <stddef.h>
#include <stdint.h>

typedef struct
{
    char hex[65];
} Digest;

uint32_t rotr(uint32_t, int);
uint32_t shr(uint32_t, int);
uint32_t sigma0(uint32_t);
uint32_t sigma1(uint32_t);
uint32_t SIGMA0(uint32_t);
uint32_t SIGMA1(uint32_t);
uint32_t Ch(uint32_t, uint32_t, uint32_t);
uint32_t Maj(uint32_t, uint32_t, uint32_t);
Digest sha256(const uint8_t*, size_t);
