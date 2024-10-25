#include <catch2/catch_test_macros.hpp>
#include <translotator/utils/epsilon.hpp>

using namespace translotator;

TEST_CASE("eplison", "[basic]")
{
    REQUIRE(exponent_epsilon<float, 3>() == 1e-3f);
    REQUIRE(exponent_epsilon<double, 7>() == 1e-7);
    REQUIRE(exponent_epsilon<long double, 10>() == 1e-10L);

    if (CONFIG_TRANSLOTATOR_DEFAULT_FLOATING_POINT_PRECISION_32_EPSILON == 4)
    {
        REQUIRE(epsilon<float>() == 1e-4f);
    }

    if (CONFIG_TRANSLOTATOR_DEFAULT_FLOATING_POINT_PRECISION_64_EPSILON == 10)
    {
        REQUIRE(epsilon<double>() == 1e-10);
    }

    if (CONFIG_TRANSLOTATOR_DEFAULT_FLOATING_POINT_PRECISION_128_EPSILON == 16)
    {
        REQUIRE(epsilon<long double>() == 1e-16L);
    }
}