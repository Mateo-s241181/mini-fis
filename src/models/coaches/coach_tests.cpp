#include <catch2/catch_test_macros.hpp>

#include "coach.h"

TEST_CASE("empty_coach", "[coach]")
{
    Coach c;

    REQUIRE(c.ceiling_displays.empty());
    REQUIRE(c.seat_displays.empty());
}

TEST_CASE("add_ceiling_display", "[coach]")
{
    Coach c;
    Display d("Ceiling Display 1");

    c.addCeilingDisplay(d);

    REQUIRE(c.ceiling_displays.size() == 1);
    REQUIRE(c.ceiling_displays[0].getText() == "Ceiling Display 1");
}

TEST_CASE("add_seat_display", "[coach]")
{
    Coach c;
    Display d("Seat Display 1");

    c.addSeatDisplay("42", d);

    REQUIRE(c.seat_displays.size() == 1);
    REQUIRE(c.seat_displays["42"].getText() == "Seat Display 1");
}

TEST_CASE("update_ceiling_displays", "[coach]")
{
    Coach c;
    Display d1("Ceiling Display 1");
    Display d2("Ceiling Display 2");

    c.addCeilingDisplay(d1);
    c.addCeilingDisplay(d2);

    c.updateCeilingDisplays("Updated Ceiling Text");

    REQUIRE(c.ceiling_displays[0].getText() == "Nächster Halt: Updated Ceiling Text");
    REQUIRE(c.ceiling_displays[1].getText() == "Nächster Halt: Updated Ceiling Text");
}

TEST_CASE("update_seat_display", "[coach]")
{
    Coach c;
    Display d("Seat Display 1");

    c.addSeatDisplay("42", d);
    c.updateSeatDisplay("42", "Updated Seat Text");

    REQUIRE(c.seat_displays["42"].getText() == "Updated Seat Text");
}
TEST_CASE("update_nonexistent_seat_display", "[coach]")
{
    Coach c;
    Display d("Seat Display 1");

    c.addSeatDisplay("42", d);
    c.updateSeatDisplay("43", "Updated Seat Text"); // Update a non-existent seat

    REQUIRE(c.seat_displays["42"].getText() == "Seat Display 1");
    REQUIRE(c.seat_displays.size() == 1); // Ensure the size remains the same
}
