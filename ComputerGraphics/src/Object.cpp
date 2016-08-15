#include "Object.h"

#include <cmath>

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void Object3D::init() {
    // Light Section
    float ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
    float diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float position[] = {0.0f, 0.0f, 2.0f, 1.0f};
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);

    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST); // Enable Depth Test
    this->angles[0] = 0.3;
    this->angles[1] = 0.2;
    this->angles[2] = 0.4;

    this->coords[0] = 0;
    this->coords[1] = 0;
    this->coords[2] = 0;
}

void Cube::idle() {
    this->angles[0] += 0.3;
    this->angles[1] += 0.2;
    this->angles[2] += 0.4;
}

void Cube::draw(float x, float y, float z, unsigned int texture) {
    glPushMatrix();
    // this->setMaterial();
    GLfloat noMat[] = { 0.0, 0.0, 0.0, 1.0 };
    // GLfloat maAambient[] = { 0.7, 0.7, 0.7, 1.0 };
    // GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
    GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
    // GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat no_shininess[] = { 0.0 };
    // GLfloat low_shininess[] = { 5.0 };
    // GLfloat high_shininess[] = { 100.0 };
    // GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, noMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, noMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, noMat);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    glPushMatrix();
    glTranslatef(
        x + this->coords[0],
        y + this->coords[1],
        z + this->coords[2]
    );
    glRotatef(this->angles[0], 1.0f, 0.0f, 0.0f);
	glRotatef(this->angles[1], 0.0f, 1.0f, 0.0f);
	glRotatef(this->angles[3], 0.0f, 0.0f, 1.0f);


    // glColor3f(0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, texture);
    float vertex[3], direction[3];
    int pivot, next, prior;
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; ++i) {
        pivot = i % 3;
        next = (pivot + 1) > 2 ? 0 : (pivot + 1);
        prior = (pivot - 1) < 0 ? 2 : (pivot - 1);
        vertex[pivot] = pow(-1.0, i);
        direction[prior] = 0;
        direction[next] = 0;
        direction[pivot] = pow(-1.0, i);
        glNormal3fv(direction);
        for (int j = 0; j < 4; ++j) {
            vertex[prior] = (j % 3 == 0) ? -1 : 1;
            vertex[next] = (j > 1) ? -1 : 1;
            glVertex3fv(vertex);
        }
    }
    glEnd();
    glPopMatrix();

    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
    glLoadIdentity();
}

void Cube::keyEvent(unsigned char key, int x, int y) {

}

void Cube::setMaterial() {
    GLfloat noMat[] = { 0.0, 0.0, 0.0, 1.0 };
    // GLfloat maAambient[] = { 0.7, 0.7, 0.7, 1.0 };
    // GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
    GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
    // GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat no_shininess[] = { 0.0 };
    // GLfloat low_shininess[] = { 5.0 };
    // GLfloat high_shininess[] = { 100.0 };
    // GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, noMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, noMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, noMat);
}
