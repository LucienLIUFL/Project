#include "GraphicsLib.h"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void GraphicsLib::drawStar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.4, 0.2);
    glBegin(GL_LINE_LOOP);
        glVertex2i(50, 100);
        glVertex2i(150, 100);
        glVertex2i(70, 40);
        glVertex2i(100, 140);
        glVertex2i(130, 40);
    glEnd();
    glFlush();
}

void GraphicsLib::generatePoints() {

}
