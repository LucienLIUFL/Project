//
// Created by maples on 1/19/17.
//

#ifndef MAPLESJSONLIB_JSON_H
#define MAPLESJSONLIB_JSON_H


namespace {
    class Object {
    public:
        virtual ~Object() {}
    };

    enum JsonType {Null, False, True, Number, String, Array, Object};

    class Value : public Object {
    public:
        ~Value() {}

        
    };
}


#endif //MAPLESJSONLIB_JSON_H
