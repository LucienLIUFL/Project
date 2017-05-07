//
// Created by maples on 4/21/17.
//

#ifndef COMPUTER_GRAPHICS_BRUSH_H
#define COMPUTER_GRAPHICS_BRUSH_H


#include <array>
#include <OpenGL/OpenGL.h>

class Brush
{
public:
    void display();

private:
    void SetPixel(int x, int y)
    {
        glColor3f(1.0, 1.0, 1.0); //Set pixel to black
        glBegin(GL_POINTS);
        glVertex2i(x, y); //Set pixel coordinates
        glEnd();
        glFlush(); //Render pixel
    }

    void Bresenham(GLint xStart, GLint yStart, GLint xEnd, GLint yEnd);
};


//#include <OpenGL/OpenGL.h>
//#include <GLUT/glut.h>
//#include <functional>
//#include <cstdio>
//#include <iostream>
//#include "Model/Point.h"
//#include "Algorithm/Brush.h"
//
//void Init()
//{
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    glMatrixMode(GL_PROJECTION);
//    gluOrtho2D(0, 400, 0, 300);      // Set
//
//    // NEED?
//    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//}
//
//int main(int argc, char * argv[])
//{
//    glutInit(&argc, argv);                      // Initialize GLUT
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// Set display mode
//    glutInitWindowSize(400, 300);
//    glutCreateWindow(argv[0]);
//    Init();
//    glutDisplayFunc([] {std::make_shared<Brush>()->display();});
//    glutMainLoop();              // Display everything and wait
//
//    return 0;
//}

#endif //COMPUTER_GRAPHICS_BRUSH_H
