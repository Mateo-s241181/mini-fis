#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle()
    : next_stop(""),
    coaches{},
    reservations{},
    route{}
{
}

void Vehicle::addCoach(Coach const& coach)
{
    coaches.push_back(coach);

    //Eine Leere unordered map für den coach hinzufügen
    reservations.push_back(std::unordered_map<std::string, std::vector<Reservation>> {});
}

void Vehicle::addStop(std::string const& stop)
{
    route.push_back(stop);
}

void Vehicle::addReservation(size_t coachIndex, std::string const& seatId, Reservation const& reservation)
{
    //Falls codeindex in reservations unerreichbar ist, brich ab
    if (coachIndex >= reservations.size()){
        return;
    }

    //enthält der Wagen mit dem coachIndex einen Eintrag mit dem Key seatId?
    if(!reservations[coachIndex].contains(seatId)){

        //Man müsste noch prüfen ob der sitz im wagon existiert

        //Eine element in der Map mit dem key seatId hinzufügen
        reservations[coachIndex].insert(std::pair<std::string, std::vector<Reservation>>(seatId, std::vector<Reservation>{}));
    }
    
    //Reservation hinzufügen, falls die reservation sinnvoll ist
    if (is_valid_for_route(reservation, route)){
        reservations[coachIndex][seatId].push_back(reservation);
    }
}

void Vehicle::showAllDisplays() const
{
    for (auto el : coaches){
        el.showAllDisplays();
    }
}

void Vehicle::showAllReservations() const
{
    return;
}

void Vehicle::setCurrentStop(size_t pos)
{
    // TODO
}

void Vehicle::arriveAtStop()
{
    // TODO
}

void Vehicle::departFromStop()
{
    // TODO
}

void Vehicle::updateSeatDisplays()
{
    // TODO
}
