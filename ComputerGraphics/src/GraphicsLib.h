#ifndef GRAPHICSLIB_H_
#define GRAPHICSLIB_H_

class GraphicsLib {
public:
    GraphicsLib() = default;
    virtual ~GraphicsLib() = default;

    static void reSizeGLScene(int width, int height);
    static bool initGL();
    static void display();
    static void spin();
private:
    static void drawTriangle();
    static void drawQuads();

    static void drawTexture();
};

#endif
