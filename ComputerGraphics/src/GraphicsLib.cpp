#include "GraphicsLib.h"
#include <cmath>
#include <iostream>

#include <cstdio>
#include <cstdlib>

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#include "BMPLib.h"

float color = 0.0f;
float xRot;
float yRot;
float zRot;
GLuint texture[1];


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
    bool returnValue = false;
    returnValue = loadGLTextures();
    glEnable(GL_TEXTURE_2D);


    glShadeModel(GL_SMOOTH); // Set Shade Smooth
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set Black Background
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST); // Enable Depth Test
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    returnValue = true;
    return returnValue;
}

void GraphicsLib::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // glTranslatef(-2.0f, 0.0f, -10.0f);
    // drawTriangle();
    // glLoadIdentity();
    //
    // glTranslatef(2.0f, 0.0f, -10.0f);
    // drawQuads();
    // glLoadIdentity();
    glTranslatef(0.0f,0.0f,-5.0f);
    drawTexture();
    glLoadIdentity();

    glFlush();
}

void GraphicsLib::translate() {
    color += 0.01;
    xRot+=0.3f;
	yRot+=0.2f;
	zRot+=0.4f;
    glutPostRedisplay();
}

void GraphicsLib::drawTriangle() {
    glRotatef(xRot,1.0f,0.0f,0.0f);
	glRotatef(yRot,0.0f,1.0f,0.0f);
	glRotatef(zRot,0.0f,0.0f,1.0f);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, color, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glColor3f(color, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        glColor3f(0.0f, color, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f); // Front

        glColor3f(1.0f, color, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, color);
        glVertex3f(1.0f, -1.0f, 1.0f);

        glColor3f(0.0f, color, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f); // right

        glColor3f(1.0f, 0.0f, color);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, color);
        glVertex3f(1.0f, -1.0f, -1.0f);

        glColor3f(color, 0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f); // back

        glColor3f(1.0f, color, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glColor3f(color, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);

        glColor3f(0.0f, color, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f); // left
    glEnd();
}

void GraphicsLib::drawQuads() {
    glRotatef(xRot,1.0f,0.0f,0.0f);
	glRotatef(yRot,0.0f,1.0f,0.0f);
	glRotatef(zRot,0.0f,0.0f,1.0f);
    glColor3f(0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
        glColor3f(color,1.0f,0.0f);						// Set The Color To Blue
        glVertex3f( 1.0f, 1.0f,-1.0f);					// Top
        glVertex3f(-1.0f, 1.0f,-1.0f);
        glColor3f(1.0f,0.5f,color);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f, 1.0f, 1.0f);

        glColor3f(1.0f,0.5f,color);						// Set The Color To Orange
        glVertex3f( 1.0f,-1.0f, 1.0f);					// Bottom
        glVertex3f(-1.0f,-1.0f, 1.0f);
        glColor3f(0.0f, color, 1.0f);
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glVertex3f( 1.0f,-1.0f,-1.0f);

        glColor3f(1.0f,color,0.0f);						// Set The Color To Red
        glVertex3f( 1.0f, 1.0f, 1.0f);					// Front
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glColor3f(color,0.0f,1.0f);
        glVertex3f(-1.0f,-1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f, 1.0f);

        glColor3f(1.0f,1.0f,color);						// Set The Color To Yellow
        glVertex3f( 1.0f,-1.0f,-1.0f);					// Back
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glColor3f(color,0.0f,1.0f);
        glVertex3f(-1.0f, 1.0f,-1.0f);
        glVertex3f( 1.0f, 1.0f,-1.0f);

        glColor3f(0.0f,color,1.0f);						// Set The Color To Blue
        glVertex3f(-1.0f, 1.0f, 1.0f);					// Left
        glVertex3f(-1.0f, 1.0f,-1.0f);
        glColor3f(1.0f,1.0f,color);
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glVertex3f(-1.0f,-1.0f, 1.0f);

        glColor3f(1.0f,color,1.0f);						// Set The Color To Violet
        glVertex3f( 1.0f, 1.0f,-1.0f);					// Right
        glVertex3f( 1.0f, 1.0f, 1.0f);
        glColor3f(0.0f,1.0f,color);
        glVertex3f( 1.0f,-1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f,-1.0f);
    glEnd();
}

void GraphicsLib::drawTexture() {
	glRotatef(xRot,1.0f,0.0f,0.0f);
	glRotatef(yRot,0.0f,1.0f,0.0f);
	glRotatef(zRot,0.0f,0.0f,1.0f);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glEnd();
}

bool GraphicsLib::loadGLTextures() {
    bool returnValue = false;
    std::shared_ptr<BMPLib::BmpInfo> pBmpInfo;
    pBmpInfo = BMPLib::makeBmpInfo("data/Crate.bmp");
    if (pBmpInfo) {
        returnValue = true;
        glGenTextures(1, &texture[0]);

        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexImage2D(
            GL_TEXTURE_2D, 0, GL_RGB,
            pBmpInfo->bmp.biWidth,
            pBmpInfo->bmp.biHeight,
            0, GL_BGR, GL_UNSIGNED_BYTE,
            pBmpInfo->imageData
        );
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    }
    return returnValue;
}
