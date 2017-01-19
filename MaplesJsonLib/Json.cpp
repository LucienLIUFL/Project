//
// Created by maples on 1/19/17.
//

#include "Json.h"

using namespace Maples;

bool Value::parse(const std::string & context) {
    if (context.empty()) {
        return false;
    }

//    std::string::iterator iter = context.begin();
    switch (context.at(0)) {
        case 'n' :
            return this->parseNull(context);
        case 'f' :
            return this->parseFalse(context);
        case 't' :
            return this->parseTrue(context);

        default:
            return false;
    }
}

bool Value::parseNull(const std::string & context) {

    return false;
}

bool Value::parseFalse(const std::string & context) {
    return false;
}

bool Value::parseTrue(const std::string & context) {
    return false;
}
