#include <cmath>
#include <iostream>
#include "Algorithm/MaplesPNG.hpp"

inline int GetRound(const double a)
{
    return int(a + 0.5);
}

void LineDDA(int x0, int y0, int xEnd, int yEnd, BitMap<512, 512> & bitMap)
{
    int dx = xEnd - x0;
    int dy = yEnd - y0;

    double steps = std::abs(std::abs(dx) > std::abs(dy) ? dx : dy);
    double xIncrement = double(dx) / steps;
    double yIncrement = double(dy) / steps;

    Color3D white(std::int8_t(255), std::int8_t(255), std::int8_t(255));

    double x = x0, y = y0;
    bitMap.SetPixel(GetRound(x), GetRound(y), white);
    for(int i = 0; i < steps; i++)
    {
        x += xIncrement;
        y += yIncrement;
        bitMap.SetPixel(GetRound(x), GetRound(y), white);
    }
}

int main(int argc, char * argv[])
{
    BitMap<512, 512> bitMap;
    LineDDA(0, 0, 256, 511, bitMap);
    bitMap.Save("My");
    return 0;
}
