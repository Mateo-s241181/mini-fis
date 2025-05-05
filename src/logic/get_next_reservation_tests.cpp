#include <catch2/catch_test_macros.hpp>

#include "reservation_logic.h"

TEST_CASE("get_next_reservation", "[get_next_reservation]")
{
    std::vector<std::string> stops = { "A", "B", "C", "D", "E" };
    Reservation r1 { "A", "B" };
    Reservation r2 { "B", "C" };
    Reservation r3 { "D", "E" };
    std::vector<Reservation> reservations { r1, r2, r3 };

    Reservation n1 = get_next_reservation(reservations, "A", stops);
    REQUIRE(n1.from == "A");
    REQUIRE(n1.to == "B");

    //Warum ist die reservation von a nach b noch bei b gültig und nicht die reservation von b nach c??

    Reservation n2 = get_next_reservation(reservations, "B", stops);
    REQUIRE(n2.from == "A");
    REQUIRE(n2.to == "B");

    Reservation n3 = get_next_reservation(reservations, "C", stops);
    REQUIRE(n3.from == "B");
    REQUIRE(n3.to == "C");

    Reservation n4 = get_next_reservation(reservations, "D", stops);
    REQUIRE(n4.from == "D");
    REQUIRE(n4.to == "E");

    Reservation n5 = get_next_reservation(reservations, "E", stops);
    REQUIRE(n5.from == "D");
    REQUIRE(n5.to == "E");
}
