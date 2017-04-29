//
// Created by maples on 1/25/17.
//

#ifndef MYGAME_MAPLES_H
#define MYGAME_MAPLES_H
#include <string>
#include <sstream>

namespace Maples {
    template <class T> std::string to_string(const T & value) {
        std::ostringstream otm;
        otm << value;
        return otm.str();
    }
}


#endif //MYGAME_MAPLES_H
