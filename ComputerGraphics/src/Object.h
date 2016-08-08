#ifndef OBJECT_H_
#define OBJECT_H_

#include <array>

class Object {
public:
    virtual ~Object() = default;
    virtual void init() = 0;
    virtual void idle() = 0;
    virtual void draw(float x, float y, float z) = 0;
    virtual void keyEvent(unsigned char key, int x, int y) = 0;
};

class Object3D : public Object {
public:
    void init() override;
protected:
    std::array<float, 3> coords;
    std::array<float, 3> colors;
    std::array<float, 3> angles;

    // virtual void Material();
    // virtual void
};

// class Object2D : public Object {
// public:
// };

class Cube : public Object3D {
public:
    void idle() override;
    void draw(float x, float y, float z) override;
    void keyEvent(unsigned char key, int x, int y) override;
};

#endif
