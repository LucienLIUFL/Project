#include <iostream>
#include <GLUT/glut.h>
#include "GraphicsLib.h"

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400, 1000);
    glutCreateWindow("Graphics");

    GraphicsLib::reSizeGLScene(4, 3);
    GraphicsLib::initGL();

    glutDisplayFunc(GraphicsLib::display);
    glutIdleFunc(GraphicsLib::spin);

    glutMainLoop();
    return 0;
}
