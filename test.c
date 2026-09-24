#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "sha256.h"
#include "tinytest.h"

void test_rotr()
{
    ASSERT_EQUALS(0x12345678, rotr(0x12345678, 0));
    ASSERT_EQUALS(0x81234567, rotr(0x12345678, 4));
    ASSERT_EQUALS(0x78123456, rotr(0x12345678, 8));
    ASSERT_EQUALS(0x56781234, rotr(0x12345678, 16));
}

void test_shr()
{
    ASSERT_EQUALS(0x12345678, shr(0x12345678, 0));
    ASSERT_EQUALS(0x01234567, shr(0x12345678, 4));
    ASSERT_EQUALS(0x00123456, shr(0x12345678, 8));
    ASSERT_EQUALS(0x00001234, shr(0x12345678, 16));
}

void test_sigma0()
{
    ASSERT_EQUALS(0x02004000, sigma0(0x00000001));
    ASSERT_EQUALS(0x1FFFFFFF, sigma0(0xffffffff));
}

void test_sigma1()
{
    ASSERT_EQUALS(0x0000A000, sigma1(0x00000001));
    ASSERT_EQUALS(0x003FFFFF, sigma1(0xffffffff));
}

void test_SIGMA0()
{
    ASSERT_EQUALS(0x40080400, SIGMA0(0x00000001));
    ASSERT_EQUALS(0xffffffff, SIGMA0(0xffffffff));
}

void test_SIGMA1()
{
    ASSERT_EQUALS(0x04200080, SIGMA1(0x00000001));
    ASSERT_EQUALS(0xffffffff, SIGMA1(0xffffffff));
}

void test_Ch()
{
    ASSERT_EQUALS(0x22222222, Ch(0, 0x11111111, 0x22222222));
    ASSERT_EQUALS(0x11111111, Ch(0xffffffff, 0x11111111, 0x22222222));
    ASSERT_EQUALS(0x00f000f0, Ch(0x0f0f0f0f, 0xf0f0f0f0, 0x00ff00ff));
}

void test_Maj()
{
    ASSERT_EQUALS(0, Maj(0, 0, 0));
    ASSERT_EQUALS(0xffffffff, Maj(0xffffffff, 0xffffffff, 0xffffffff));
    ASSERT_EQUALS(0, Maj(0xffffffff, 0, 0));
    ASSERT_EQUALS(0xffffffff, Maj(0xffffffff, 0xffffffff, 0));
    ASSERT_EQUALS(0x00ff00ff, Maj(0x0f0f0f0f, 0xf0f0f0f0, 0x00ff00ff));
}

void test_sha256()
{
    ASSERT_STRING_EQUALS(
        "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
        sha256((const uint8_t*)"", 0).hex);
    ASSERT_STRING_EQUALS(
        "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad",
        sha256((const uint8_t*)"abc", 3).hex);
    ASSERT_STRING_EQUALS(
        "71c480df93d6ae2f1efad1447c66c9525e316218cf51fc8d9ed832f2daf18b73",
        sha256((uint8_t*)"abcdefghijklmnopqrstuvwxyz", 26).hex);

    char* million = malloc(1000000);
    memset(million, 'a', 1000000);
    ASSERT_STRING_EQUALS(
        "cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0",
        sha256((const uint8_t*)million, 1000000).hex);
    free(million);
}

int main()
{
    RUN(test_rotr);
    RUN(test_shr);
    RUN(test_sigma0);
    RUN(test_sigma1);
    RUN(test_SIGMA0);
    RUN(test_SIGMA1);
    RUN(test_Ch);
    RUN(test_Maj);
    RUN(test_sha256);
    return 0;
}
