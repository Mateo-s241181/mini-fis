#include "vehicle.h"
#include <iostream>
#include <algorithm>

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
    //durch alle coaches durchrangen
    for (auto map_elem : reservations){

        //alle paare einer unordered map accessem
        for(auto pair_elem : map_elem){

            //SeatId zur Identifikation ausgeben
            std::cout << "SeatId: " << pair_elem.first << '\n' << '\n';

            //den reservationsvektor der seatId durchgehen
            for(auto reservation_elem : pair_elem.second){

                //Jede Reservation anzeigen
                reservation_elem.getDisplayText();
            }
        }
    }
    return;
}

//TODO:
//Test schreiben für showAllReservations

void Vehicle::setCurrentStop(size_t pos)
{

    next_stop = pos < route.size() ? route[pos] : "" ;

    //genau das gleiche wie:
    
    // if(pos < route.size()){
    //     next_stop = route[pos];
    //     return;
    // }
    // next_stop = "";
}

void Vehicle::arriveAtStop()
{
    size_t pos = getPosition(next_stop, route);

    //Station, an der man angekommen ist auf den displays anzeigen
    for (auto &coach_elem : coaches){
        coach_elem.updateCeilingDisplays(next_stop);
    }

    //Eine Position weiter gehen

    //Muss außerhalb der funktion passieren???
    //erst returnen => Erhöhung ist ein Seiteneffekt, muss vor die funktion geschrieben werden
    pos++;
    
    //++pos wurde erst erhöhen und dann returnen => Könnte direkt in die Funktion geschreiben werden
    setCurrentStop(pos);
}

void Vehicle::departFromStop()
{
    size_t pos = getPosition(next_stop, route);

    setCurrentStop(pos);

    for (auto &coach_elem : coaches){
        coach_elem.updateCeilingDisplays(next_stop);
    }
}

void Vehicle::updateSeatDisplays()
{
    // TODO
}
