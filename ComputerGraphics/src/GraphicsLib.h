#ifndef GRAPHICSLIB_H_
#define GRAPHICSLIB_H_

class GraphicsLib {
public:
    static void reSizeGLScene(int width, int height);
    static bool initGL();
    static void display();
    static void translate();
    static void keyEvent(unsigned char key, int x, int y);
private:
    static bool loadGLTextures();

    static void drawTriangle(float x, float y, float z);
    static void drawQuads(float x, float y, float z);
    static void drawTexture(float x, float y, float z);
    static void drawTest(float x, float y, float z);
    static void drawStars(float x, float y, float z);
};

class Star {
public:
    int r;
    int g;
    int b;
    float dist;
    float angle;
};

#endif
