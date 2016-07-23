#include <iostream>
#include <GLUT/glut.h>
#include "GraphicsLib.h"

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Graphics");

    GraphicsLib::reSizeGLScene(400, 300);
    GraphicsLib::initGL();

    glutDisplayFunc(GraphicsLib::drawGLScene);
    glutIdleFunc(GraphicsLib::spin);

    glutMainLoop();
    return 0;
}
