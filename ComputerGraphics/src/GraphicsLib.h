#ifndef GRAPHICSLIB_H_
#define GRAPHICSLIB_H_

class GraphicsLib {
public:
    GraphicsLib() = default;
    virtual ~GraphicsLib() = default;

    void drawStar();
// private:
    void generatePoints(int n, double extend);
};

#endif
