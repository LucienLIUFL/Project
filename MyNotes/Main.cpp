#include <iostream>
#include <string>

class Object {
public:
    explicit Object(const std::string & name) : _name(name) {}

    virtual ~Object() {}

    std::string _name;
};

class Book {
public:
    Book(const Object & object) : _object(object) {}

    std::string show() {
        return _object._name;
    }
private:
    Object _object;
};

int main(int argc, const char * argv[]) {

    Object object = std::string("Potter");
    // Book Harry(Object(std::string("Harry")));
    // Book Maples(std::string("Maples"));
    // Book Potter = std::string("Potter");

    // std::cout << Harry.show() << Maples.show() << std::endl;
    std::cout << object._name << std::endl;
    return 0;
}