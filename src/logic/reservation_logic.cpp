

#include "reservation_logic.h"

void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops)
{
    // TODO
}

Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops)
{
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


//Hilfsfunktion => Für get_next_reservation gedacht
//Placeholder Type T
template <typename T>

size_t getPosition(T x, std::vector<T> v){

    for (size_t i = 0; i < v.size(), i++){

        if(v[i] == x){
            return i;
        }
    }
}