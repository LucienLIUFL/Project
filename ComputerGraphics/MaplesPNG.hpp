#ifndef SVPNG_INC_
#define SVPNG_INC_

#ifndef SVPNG_LINKAGE
#define SVPNG_LINKAGE
#endif

#ifndef SVPNG_OUTPUT
#include <stdio.h>
#define SVPNG_OUTPUT FILE* fp
#endif

#ifndef SVPNG_PUT
#define SVPNG_PUT(u) fputc(u, fp)
#endif

SVPNG_LINKAGE void svpng(SVPNG_OUTPUT, unsigned w, unsigned h, const unsigned char* img, int alpha) {
    static const unsigned t[] = { 0, 0x1db71064, 0x3b6e20c8, 0x26d930ac, 0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c, 
    /* CRC32 Table */    0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c, 0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c };
    unsigned a = 1, b = 0, c, p = w * (alpha ? 4 : 3) + 1, x, y, i;   /* ADLER-a, ADLER-b, CRC, pitch */
#define SVPNG_U8A(ua, l) for (i = 0; i < l; i++) SVPNG_PUT((ua)[i]);
#define SVPNG_U32(u) do { SVPNG_PUT((u) >> 24); SVPNG_PUT(((u) >> 16) & 255); SVPNG_PUT(((u) >> 8) & 255); SVPNG_PUT((u) & 255); } while(0)
#define SVPNG_U8C(u) do { SVPNG_PUT(u); c ^= (u); c = (c >> 4) ^ t[c & 15]; c = (c >> 4) ^ t[c & 15]; } while(0)
#define SVPNG_U8AC(ua, l) for (i = 0; i < l; i++) SVPNG_U8C((ua)[i])
#define SVPNG_U16LC(u) do { SVPNG_U8C(u); SVPNG_U8C(((u) >> 8) & 255); } while(0)
#define SVPNG_U32C(u) do { SVPNG_U8C((u) >> 24); SVPNG_U8C(((u) >> 16) & 255); SVPNG_U8C(((u) >> 8) & 255); SVPNG_U8C((u) & 255); } while(0)
#define SVPNG_U8ADLER(u) do { SVPNG_U8C(u); a = (a + (u)) % 65521; b = (b + a) % 65521; } while(0)
#define SVPNG_BEGIN(s, l) do { SVPNG_U32(l); c = ~0U; SVPNG_U8AC(s, 4); } while(0)
#define SVPNG_END() SVPNG_U32(~c)
    SVPNG_U8A("\x89PNG\r\n\32\n", 8);           /* Magic */
    SVPNG_BEGIN("IHDR", 13);                    /* IHDR chunk { */
    SVPNG_U32C(w); SVPNG_U32C(h);               /*   Width & Height (8 bytes) */
    SVPNG_U8C(8); SVPNG_U8C(alpha ? 6 : 2);     /*   Depth=8, Color=True color with/without alpha (2 bytes) */
    SVPNG_U8AC("\0\0\0", 3);                    /*   Compression=Deflate, Filter=No, Interlace=No (3 bytes) */
    SVPNG_END();                                /* } */
    SVPNG_BEGIN("IDAT", 2 + h * (5 + p) + 4);   /* IDAT chunk { */
    SVPNG_U8AC("\x78\1", 2);                    /*   Deflate block begin (2 bytes) */
    for (y = 0; y < h; y++) {                   /*   Each horizontal line makes a block for simplicity */
        SVPNG_U8C(y == h - 1);                  /*   1 for the last block, 0 for others (1 byte) */
        SVPNG_U16LC(p); SVPNG_U16LC(~p);        /*   Size of block in little endian and its 1's complement (4 bytes) */
        SVPNG_U8ADLER(0);                       /*   No filter prefix (1 byte) */
        for (x = 0; x < p - 1; x++, img++)
            SVPNG_U8ADLER(*img);                /*   Image pixel data */
    }
    SVPNG_U32C((b << 16) | a);                  /*   Deflate block end with adler (4 bytes) */
    SVPNG_END();                                /* } */
    SVPNG_BEGIN("IEND", 0); SVPNG_END();        /* IEND chunk {} */
}

#include <cstdlib>
#include <cstdint>
#include <array>
#include <string>


class Color3D
{
    using Byte = std::int8_t;
public:
    Color3D(Byte r, Byte g, Byte b) : R(r), G(g), B(b) {}

    Byte R;
    Byte G;
    Byte B;
};

template<int W, int H>
class BitMap
{
    using Byte = std::int8_t;
public:
    BitMap()
    {
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                int index = i * H * 3 + j * 3;
                this->Pixels[index + 0] = 0;
                this->Pixels[index + 1] = 0;
                this->Pixels[index + 2] = 0;
            }
        }
    }

    void SetPixel(int x, int y, Color3D color)
    {
        int index = (H - y - 1) * W * 3 + x * 3;
        this->Pixels.at(index + 0) = color.R;
        this->Pixels.at(index + 1) = color.G;
        this->Pixels.at(index + 2) = color.B;
    }

    Color3D GetPixel(int x, int y)
    {
        int index = (H - y - 1) * W * 3 + x * 3;
        return Color3D(Pixels.at(index + 0), Pixels.at(index + 1), Pixels.at(index + 2));
    }

    void Save(const char * filename)
    {
        std::string name(filename);
        name.append(".png");
        FILE * fp = fopen(name.c_str(), "wb");     
        svpng(fp, W, H, (const unsigned char *)this->Pixels.data(), 0);
        fclose(fp);
    }

private:
    std::array<Byte, W * H * 3> Pixels;
};

#endif /* SVPNG_INC_ */
