#include "custom_tester.hpp"

#include <translotator/translotator.hpp>

using namespace translotator;

TEST_CASE("DualQuaternion", "[objects]")
{
    DualQuaternionf dq{Quaternionf{1.f, 2.f, 3.f, 4.f}, Quaternionf{5.f, 6.f, 7.f, 8.f}};

    SECTION("constructor")
    {
        DualQuaternionf dq1 = dq;
        REQUIRE_THAT(dq1, EqualsMatrix(dq));

        DualQuaternionf dq2{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f};
        REQUIRE_THAT(dq2, EqualsMatrix(dq));

        DualQuaternionf dq3{Quaternionf{1.f, 2.f, 3.f, 4.f}, Quaternionf{5.f, 6.f, 7.f, 8.f}};
        REQUIRE_THAT(dq3, EqualsMatrix(dq));

        DualQuaternionf dq4{Vectorf<8>{{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f}}};
        REQUIRE_THAT(dq4, EqualsMatrix(dq));
    }

    SECTION("accessors")
    {
        DualQuaternionf dq1 = dq;
        REQUIRE(close_enough(dq1.real().w(), 1.f));
        REQUIRE(close_enough(dq1.real().x(), 2.f));
        REQUIRE(close_enough(dq1.real().y(), 3.f));
        REQUIRE(close_enough(dq1.real().z(), 4.f));
        REQUIRE(close_enough(dq1.dual().w(), 5.f));
        REQUIRE(close_enough(dq1.dual().x(), 6.f));
        REQUIRE(close_enough(dq1.dual().y(), 7.f));
        REQUIRE(close_enough(dq1.dual().z(), 8.f));

        dq1.real().w() = 11.f;
        dq1.real().x() = 12.f;
        dq1.real().y() = 13.f;
        dq1.real().z() = 14.f;
        dq1.dual().w() = 15.f;
        dq1.dual().x() = 16.f;
        dq1.dual().y() = 17.f;
        dq1.dual().z() = 18.f;

        REQUIRE(close_enough(dq1.real().w(), 11.f));
        REQUIRE(close_enough(dq1.real().x(), 12.f));
        REQUIRE(close_enough(dq1.real().y(), 13.f));
        REQUIRE(close_enough(dq1.real().z(), 14.f));
        REQUIRE(close_enough(dq1.dual().w(), 15.f));
        REQUIRE(close_enough(dq1.dual().x(), 16.f));
        REQUIRE(close_enough(dq1.dual().y(), 17.f));
        REQUIRE(close_enough(dq1.dual().z(), 18.f));
    }

    SECTION("operators")
    {
        { // operator +
        }

        { // operator -
        }

        { // operator *
        }
    }

    SECTION("utils")
    {
    }

    SECTION("static functions")
    {
    }
    SECTION("casts")
    {
    }
}