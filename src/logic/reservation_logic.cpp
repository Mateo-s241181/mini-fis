

#include "reservation_logic.h"
#include <algorithm>

void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops)
{
    if(!is_valid_for_route(reservation, stops)){
    return;
    }

    if (reservations.size() == 0){
        reservations.insert(reservations.begin(), reservation);
    }

    else{

        if (getPosition(reservations[0].to, stops) <= getPosition(reservation.from, stops)){

            reservations.insert(reservations.end(), reservation);
            return;
        }

        if(getPosition(reservations[0].from, stops) >= getPosition(reservation.from, stops)){
            reservations.insert(reservations.begin(), reservation);
            return;
        }

        //durch reservations rangen
        for (auto i = 0; i < reservations.size(); i++){

            if (getPosition(reservations[i].to, stops) <= getPosition(reservation.from, stops) && getPosition(reservations[i+1].from, stops) >= getPosition(reservation.from, stops)){

                reservations.insert(reservations.begin()+i, reservation);
                return;
            }

        }
    }
}

Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops)
{

    //Wann ist eine Reservierung für an einem bestimmten next_stop gültig?
    //      Genau dann, wenn position von reservation.from < pos(next_stop) und pos(reservations.to) > pos(next_stop)
    
    //Durch reservations rangen und testen

    for (Reservation res_elem : reservations){

        if (getPosition(res_elem.from, stops) <= getPosition(next_stop, stops) && getPosition(res_elem.to, stops) >= getPosition(next_stop, stops)){
            return res_elem;
        }
    }

   return Reservation{};
}

bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops)
{
    size_t fromPos = -1;
    size_t toPos = -1;

    for (auto i = 0; i < stops.size(); i++){

        if (stops[i] == reservation.from){
            fromPos = i;
        }
        if (stops[i] == reservation.to){
            toPos = i;
        }
    }

    if(fromPos != -1 && toPos != -1){
        return fromPos < toPos;
    }
    return false;
}


