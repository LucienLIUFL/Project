#ifndef GRAPHICSLIB_H_
#define GRAPHICSLIB_H_

class GraphicsLib {
public:
    GraphicsLib() = default;
    virtual ~GraphicsLib() = default;
    // void drawStar();
    // void drawCycle(int n, double extend);
    static void reSizeGLScene(int width, int height);
    static bool initGL();
    static void drawGLScene();
    static void spin();
// private:
};

#endif
