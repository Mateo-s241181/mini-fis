#include <catch2/catch_test_macros.hpp>

#include "reservation_logic.h"

TEST_CASE("is_valid_for_route", "[is_valid_for_route]")
{
    std::vector<std::string> stops = { "A", "B", "C", "D", "E" };
    Reservation r1 { "A", "B" }; // gültig
    Reservation r2 { "B", "C" }; // gültig
    Reservation r3 { "D", "F" }; // ungültig
    Reservation r4 { "F", "D" }; // ungültig
    Reservation r5 { "E", "D" }; // ungültig
    Reservation r6 { "A", "" }; // ungültig
    Reservation r7 { "", "A" }; // ungültig
    Reservation r8 { "", "" }; // ungültig

    REQUIRE(is_valid_for_route(r1, stops) == true);
    REQUIRE(is_valid_for_route(r2, stops) == true);
    REQUIRE(is_valid_for_route(r3, stops) == false);
    REQUIRE(is_valid_for_route(r4, stops) == false);
    REQUIRE(is_valid_for_route(r5, stops) == false);
    REQUIRE(is_valid_for_route(r6, stops) == false);
    REQUIRE(is_valid_for_route(r7, stops) == false);
    REQUIRE(is_valid_for_route(r8, stops) == false);
}

TEST_CASE("find position", "[find_position]")
{

    std::vector<int> v1 {0, 1, 2, 3, 4, 5};
    std::vector<int> v2 {0, 7, 2, 3, 4, 5};
    std::vector<int> v3 {0, 1, 2, 9, 4, 5};
    std::vector<int> v4 {0, 1, 2, 3, 123, 5};

    REQUIRE(getPosition(1, v1) == 1);
    REQUIRE(getPosition(5, v2) == 5);
    REQUIRE(getPosition(7, v3) == 6);
    REQUIRE(getPosition(123, v4) == 4);

}
