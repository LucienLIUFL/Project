#ifndef OBJECT_H_
#define OBJECT_H_


class Object {
public:
    virtual ~Object() = default;
    virtual void init() = 0;
    virtual void idle() = 0;
    virtual void draw(double x, double y, double z) = 0;
    virtual void keyEvent(unsigned char key, int x, int y) = 0;
};

class Object3D : public Object {
public:
    void init() override;
};

// class Object2D : public Object {
// public:
// };

#endif
