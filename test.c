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

int main()
{
    RUN(test_rotr);
    RUN(test_shr);
    return 0;
}
