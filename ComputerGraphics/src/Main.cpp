#include <iostream>
#include <GLUT/glut.h>
#include "GraphicsLib.h"

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Graphics");

    GraphicsLib::initGL();
    glutDisplayFunc(GraphicsLib::drawGLScene);
    glutMainLoop();
    return 0;
}
