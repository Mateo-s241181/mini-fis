

#include "reservation_logic.h"
#include <algorithm>

void insert_reservation(Reservation const& reservation, std::vector<Reservation>& reservations, std::vector<std::string> const& stops)
{
    if(!is_valid_for_route(reservation, stops)){
    return;
    }

    //in new_reservations wird einfach so die neue reservation geadded
    reservations.push_back(reservation);

    std::vector<Reservation> new_reservations{};
    
    //iterieren durch stops
    for(auto i = stops.begin(); i < stops.end(); i++){

        //iterieren durch die Elemente von reservations
        for(auto res_elem : reservations){

            //Wenn in stops ein element von reservations gefunden wird
            if (*i == res_elem.from){

                //das Element wird in new_reservations hinzugefügt
                new_reservations.push_back(res_elem);
                i = std::find(stops.begin(), stops.end(), res_elem.to) - 1;
            }
        }
    }

    reservations = new_reservations;
}

Reservation get_next_reservation(std::vector<Reservation> const& reservations, std::string const& next_stop, std::vector<std::string> const& stops)
{

    auto next_stop_it = std::find(stops.begin(), stops.end(), next_stop);

    
    for (auto res_elem : reservations){

        for (auto i = next_stop_it; i < stops.end(); i++){

            //iterator dereferenzieren und mit res_elem.to vergleichen
            if(res_elem.to == *i){
                return res_elem;
            }
        }
    }

    
    return Reservation{};
}

bool is_valid_for_route(Reservation const& reservation, std::vector<std::string> const& stops)
{
    //Ziel: Erkennung, ob den Abfahrtsort in der Reservation vor dem Ankunftsort in stops vorkommt

    //Boolean Variablen, um zu tracken, ob der jeweilige Ort schon gefunden worden ist
    bool fromFound {false};
    bool toFound {false};

    //Jedes Element aus stops betrachten
    for (auto stop_elem : stops){
        
        //Wenn die Elemente mit dem jeweiligen Ort übereinstimmen, werden die Variablen auf true gesetzt
        if (stop_elem == reservation.from){
            fromFound = true;
        }
        if (stop_elem == reservation.to){
            toFound = true;

            //Wenn toFound gefunden worden ist, muss fromFound ebenfalls gefunden worden sein, damit die Reservation valid ist
            return fromFound;
        }
    }
    //Falls der Zielort nicht gefunden wird gelangt der Code an dieses  return-Statement
    return false;
}

//Die Variante oben ist deutlich Speichereffizienter als diese, da nur bool (1 Byte) variablen genutzt werden und keine size_t (4 oder sogar 8 bytes)

// size_t fromPos = -1;
// size_t toPos = -1;

// for (auto i = 0; i < stops.size(); i++){

//     if (stops[i] == reservation.from){
//         fromPos = i;
//     }
//     if (stops[i] == reservation.to){
//         toPos = i;
//     }
// }

// if(fromPos != -1 && toPos != -1){
//     return fromPos < toPos;
// }
// return false;
