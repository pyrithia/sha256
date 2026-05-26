#include "sha256.h"
#include "tinytest.h"

void test_rotr()
{
    ASSERT_EQUALS(0x12345678, rotr(0x12345678, 0));
    ASSERT_EQUALS(0x81234567, rotr(0x12345678, 4));
    ASSERT_EQUALS(0x78123456, rotr(0x12345678, 8));
    ASSERT_EQUALS(0x56781234, rotr(0x12345678, 16));
}

int main()
{
    RUN(test_rotr);
    return 0;
}
