#include <iostream>
#include <functional>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "GraphicsLib.h"

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200, 0.0, 200);
}

void display() {
    GraphicsLib drawer;
    // drawer.drawStar();
    drawer.drawCycle(16, 20.0);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Graphics");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
