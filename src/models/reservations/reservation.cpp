#include "reservation.h"

Reservation::Reservation(std::string const& from, std::string const& to)
    : from(from)
    , to(to)
{
}

bool Reservation::isEmpty() const
{
    return Reservation::from == "" && Reservation::to == "";
}

std::string Reservation::getDisplayText() const
{
    return Reservation::from + " - " + Reservation::to;
}
