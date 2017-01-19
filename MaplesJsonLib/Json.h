//
// Created by maples on 1/19/17.
//

#ifndef MAPLESJSONLIB_JSON_H
#define MAPLESJSONLIB_JSON_H

#include <string>

namespace Maples {
    class Object {
    public:
        virtual ~Object() {}
    };

    enum JsonType {Null, False, True, Number, String, Array, Object};

    class Value : public Object {
    public:
        ~Value() {}

        bool parse(const std::string &);
    private:
        bool parseNull(const std::string &);
        bool parseFalse(const std::string &);
        bool parseTrue(const std::string &);
    };
}


#endif //MAPLESJSONLIB_JSON_H
