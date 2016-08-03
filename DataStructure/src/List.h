#ifndef LIST_H_
#define LIST_H_

using Type = int;
class Node {
public:
    Node() : next(nullptr) {}
    Type elem;
    Node * next;
};

class List {
public:
    List();
    List(const List &) = delete;
    List & operator=(const List &) = delete;
    virtual ~List();

    int getSize() const;
    bool empty() const;
    void append(const Type & e);
    void insert(int pos, const Type & e);
    void remove(int pos);
    int find(const Type & e) const;
    void traverse(void (* visit)(Type));
private:
    Node * header;
    int size;
};

#endif
