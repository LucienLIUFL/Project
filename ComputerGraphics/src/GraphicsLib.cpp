#include "GraphicsLib.h"
#include <cmath>
#include <iostream>

#include <cstdio>
#include <cstdlib>

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#include "BMPLib.h"

#define MAPLES_2D
#define STAR

// Color
float color = 0.0f;
// ~Color

// Rotation
float xRot;
float yRot;
float zRot;
// ~Rotation

// <Texture>
unsigned int texture;
// </Texture>

// <Light>
bool lightStatus = false;
bool keyStautus = false;

float ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
float diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
float position[] = {0.0f, 0.0f, 2.0f, 1.0f};
// </Light>

// <Blend>
bool blendStatus = false;
// </Blend>

// <Star>
const int STAR_NUM = 50;
Star stars[50];

float zoom = -100.0f;
float tilt = 90.f;
float spin = 0.0f;
int loop = 0;
// </Star>


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

    // 3D or 2D
#ifdef MAPLES_3D
    glDepthFunc(GL_LEQUAL);
    // Light Section
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glEnable(GL_LIGHT1);

    glEnable(GL_DEPTH_TEST); // Enable Depth Test
#endif


    // Texture Section
    returnValue = loadGLTextures();
    glEnable(GL_TEXTURE_2D);
    // Normal Section
    glShadeModel(GL_SMOOTH); // Set Shade Smooth
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set Black Background
    glClearDepth(1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    // Blend Section
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

#ifdef STAR
    glEnable(GL_BLEND);
    for (int i = 0; i < STAR_NUM; ++i) {
        stars[i].angle = 0.0f;
        stars[i].dist = (static_cast<float>(i) / STAR_NUM) * 0.5f;
        stars[i].r = (rand() % 256);
        stars[i].g = (rand() % 256);
        stars[i].b = (rand() % 256);
    }
#endif

    returnValue = true;
    return returnValue;
}

void GraphicsLib::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // drawTriangle(-2.0f, 0.0f, -10.0f);
    // drawQuads(2.0f, 0.0f, -10.0f);
    // drawTexture(0.0f,0.0f,-5.0f);
    // drawTest(0.0, 0.0, -10.0);
    // gluLookAt(0.0f, 0.0f, 20.0f, 0.0f,0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    drawStars(0.0, 0.0, zoom);

    glutSwapBuffers();
}

void GraphicsLib::translate() {
#ifdef BOX
    color += 0.01;
    xRot+=0.3f;
	yRot+=0.2f;
	zRot+=0.4f;
#endif

#ifdef STAR
    spin += 0.01;
#endif
    glutPostRedisplay();
}

void GraphicsLib::keyEvent(unsigned char key, int x, int y) {
    switch (key) {
        // Light Control
        case 'L' : {
            glDisable(GL_LIGHTING);
            break;
        };
        case 'l' : {
            glEnable(GL_LIGHTING);
            break;
        };
        // Blend Control
        case 'B' : {
            glDisable(GL_BLEND);
            glEnable(GL_DEPTH_TEST);
            break;
        }
        case 'b' : {
            glDisable(GL_DEPTH_TEST);
            glEnable(GL_BLEND);
            break;
        }
    }
}

void GraphicsLib::drawTriangle(float x, float y, float z) {
    glTranslatef(x, y, z);
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
    glLoadIdentity();
}

void GraphicsLib::drawQuads(float x, float y, float z) {
    glTranslatef(x, y, z);
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
    glLoadIdentity();
}

void GraphicsLib::drawTexture(float x, float y, float z) {
    glTranslatef(x, y, z);
	glRotatef(xRot,1.0f,0.0f,0.0f);
	glRotatef(yRot,0.0f,1.0f,0.0f);
	glRotatef(zRot,0.0f,0.0f,1.0f);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
		// Front Face
        glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        // glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		// Back Face
        glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		// Top Face
        glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		// Bottom Face
        glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		// Right face
        glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		// Left Face
        glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glEnd();
    glLoadIdentity();
}

void GraphicsLib::drawTest(float x, float y, float z) {
    glTranslatef(x, y, z);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glEnd();
    glLoadIdentity();
}

bool GraphicsLib::loadGLTextures() {
    bool returnValue = false;
    std::shared_ptr<BMPLib::BmpInfo> pBmpInfo;
    pBmpInfo = BMPLib::makeBmpInfo("data/Star.bmp");
    if (pBmpInfo) {
        returnValue = true;
        glGenTextures(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D, 0, 3,
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

void GraphicsLib::drawStars(float x, float y, float z) {
    glTranslatef(x, y, z);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, texture);

    for (int i = 0; i < STAR_NUM; ++i) {
        glLoadIdentity();
        glRotatef(7.2 * i * spin, 0, 0, 1);
        // glTranslatef(1.0f, 0.0f, zoom);
        // glRotatef(tilt, 1.0f, 0.0f, 0.0f);
        //
        // glRotatef(stars[loop].angle, 0.0, 1.0, 0.0);
        glTranslatef(stars[loop].dist, i, zoom);
        //
        // glRotatef(-stars[loop].angle, 0.0, 1.0, 0.0);
        // glRotatef(-tilt, 1.0f, 0.0f, 0.0f);
        //
        //
        // glRotatef(spin, 0.0, 0.0, 1.0);
        // glColor4ub(stars[loop].r, stars[loop].g, stars[loop].b, 255);
        // glBegin(GL_QUADS);
        //     glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
		// 	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,-1.0f, 0.0f);
		// 	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 0.0f);
		// 	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
        // glEnd();
        //
        // stars[loop].angle += static_cast<float>(loop) / STAR_NUM;
        // stars[loop].dist -= 0.01;
        // spin += 0.01;
        // if (stars[loop].dist < 0.0f) {
    	// 	stars[loop].dist += 5.0f;
    	// 	stars[loop].r = rand() % 256;
    	// 	stars[loop].g = rand() % 256;
    	// 	stars[loop].b = rand() % 256;
        // }
        glColor4ub(stars[loop].r, stars[loop].g, stars[loop].b, 255);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
        glEnd();

    }
}















//
