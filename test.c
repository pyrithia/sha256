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
    return 0;
}
