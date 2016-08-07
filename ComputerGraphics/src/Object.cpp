#include "Object.h"
#include <OpenGL/gl.h>

void Object3D::init() {
    float ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
    float diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float position[] = {0.0f, 0.0f, 2.0f, 1.0f};

    glDepthFunc(GL_LEQUAL);
    // Light Section
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);

    glEnable(GL_DEPTH_TEST); // Enable Depth Test
}
