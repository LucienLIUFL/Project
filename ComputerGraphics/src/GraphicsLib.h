#ifndef GRAPHICSLIB_H_
#define GRAPHICSLIB_H_

class GraphicsLib {
public:
    static void reSizeGLScene(int width, int height);
    static bool initGL();
    static void display();
    static void translate();
private:
    static bool loadGLTextures();

    static void drawTriangle(float x, float y, float z);
    static void drawQuads(float x, float y, float z);
    static void drawTexture(float x, float y, float z);


    static void drawTest(float x, float y, float z);
};

#endif
