#ifndef VECTOR_H_
#define VECTOR_H_

using Type = int;
namespace Maples {
    class Vector {
    public:
        Vector();
        Vector(int size);
        Vector(const Vector & v);
        Vector & operator=(const Vector & v);
        virtual ~Vector();

        void clear();
        bool empty() const;
        int size() const;
        Type operator[](int index) const;
        int find(Type e) const;
        int prior(Type e) const ;
        int next(Type e) const;
        void insert(int index, Type e);
        void remove(int index);
        void traverse(void (*visit)(Type));
        void append(Type e);
    private:
        Type * m_pElement;
        int m_sizeElement;

        void m_moveElement(int memSize);
        void m_copyElement(const Vector & v);
    };
}


#endif
