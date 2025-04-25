#include "coach.h"

#include <iostream>

Coach::Coach()
    :   ceiling_displays{ },
        seat_displays{ }
{
}

void Coach::addCeilingDisplay(Display const& display)
{
    ceiling_displays.push_back(display);
}

void Coach::addSeatDisplay(std::string const& seatId, Display const& display)
{
    seat_displays.insert(std::pair<std::string, Display>(seatId, display));
}

void Coach::updateCeilingDisplays(std::string const& newText)
{
    //WICHTIG: el als reference (&el) passen. Ansonsten Updated updateText() in der Schleife nur die Kopie von el
    for (auto &el : ceiling_displays){
        el.updateText(newText);
    }
}

void Coach::updateSeatDisplay(std::string const& seatId, std::string const& newText)
{
    //Falls ein std::pair mit dem key seatId existiert
    if (seat_displays.contains(seatId)){

        //Update den Text auf dem Display an stelle seatId
        seat_displays[seatId].updateText(newText);
    }


    // auto it = seat_displays.find(seatId);

    // if(it != seat_displays.end()){


    //     // 2.   it->second.updateText(newText);

    //     // 3.   auto [id, display] = *it;
    //     //      display.updateText(newText);
    // }
}

void Coach::showCeilingDisplays() const
{
    for (auto el : ceiling_displays){
        el.show();
    }
}

void Coach::showSeatDisplays() const
{
    for(auto el : seat_displays){
        el.second.show();
    }
}

void Coach::showAllDisplays() const
{
    showCeilingDisplays();
    showSeatDisplays();
}
