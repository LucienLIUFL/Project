#include "GraphicsLib.h"
#include <thread>
#include <cmath>
#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// void GraphicsLib::drawStar() {
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(0.0, 0.4, 0.2);
//     glBegin(GL_LINE_LOOP);
//         glVertex2i(50, 100);
//         glVertex2i(150, 100);
//         glVertex2i(70, 40);
//         glVertex2i(100, 140);
//         glVertex2i(130, 40);
//     glEnd();
//     glFlush();
// }
//
// void GraphicsLib::drawCycle(int n, double extend) {
//     double angle = (3.1415926 * 2 / n);
//     double x = 0, y = 50;
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(0.0, 1, 0.2);
//     glBegin(GL_POLYGON);
//     glVertex2f(x, y);
//     for (int i = 0; i < n; ++i) {
//         x += (extend * sin(i * angle));
//         y += (extend * cos(i * angle));
//         glVertex2f(x, y);
//     }
//     glEnd();
//     glFlush();
// }

float angle = 0.0f;

void GraphicsLib::reSizeGLScene(int width, int height) {
    if (0 == height) {
        height = 1;
    }
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION); // Select Projection Matrix
    glLoadIdentity(); // Reset Projection Matrix

    double aspect = static_cast<double>(width) / height;
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

bool GraphicsLib::initGL() {
    glShadeModel(GL_SMOOTH); // Set Shade Smooth
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set Black Background
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST); // Enable Depth Test
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    return true;
}

void GraphicsLib::drawGLScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(-1.5f, 0.0f, -10.0f);

    glRotatef(angle, 1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f); // Front

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f); // right

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f); // back

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f); // left
    glEnd();

    glLoadIdentity();
    glTranslatef(3.0f, 0.0f, -10.0f);

    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    glColor3f(0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
        glColor3f(0.0f,1.0f,0.0f);						// Set The Color To Blue
        glVertex3f( 1.0f, 1.0f,-1.0f);					// Top
        glVertex3f(-1.0f, 1.0f,-1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f, 1.0f, 1.0f);

        glColor3f(1.0f,0.5f,0.0f);						// Set The Color To Orange
        glVertex3f( 1.0f,-1.0f, 1.0f);					// Bottom
        glVertex3f(-1.0f,-1.0f, 1.0f);
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glVertex3f( 1.0f,-1.0f,-1.0f);

        glColor3f(1.0f,0.0f,0.0f);						// Set The Color To Red
        glVertex3f( 1.0f, 1.0f, 1.0f);					// Front
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f,-1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f, 1.0f);

        glColor3f(1.0f,1.0f,0.0f);						// Set The Color To Yellow
        glVertex3f( 1.0f,-1.0f,-1.0f);					// Back
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glVertex3f(-1.0f, 1.0f,-1.0f);
        glVertex3f( 1.0f, 1.0f,-1.0f);

        glColor3f(0.0f,0.0f,1.0f);						// Set The Color To Blue
        glVertex3f(-1.0f, 1.0f, 1.0f);					// Left
        glVertex3f(-1.0f, 1.0f,-1.0f);
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glVertex3f(-1.0f,-1.0f, 1.0f);
        
        glColor3f(1.0f,0.0f,1.0f);						// Set The Color To Violet
        glVertex3f( 1.0f, 1.0f,-1.0f);					// Right
        glVertex3f( 1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f,-1.0f);
    glEnd();
    // glFlush();
    glutSwapBuffers();
}

void GraphicsLib::spin() {
    angle += 2.0f;
    if (angle > 360.0) {
        angle -= 360.0;
    }
    glutPostRedisplay();
}
