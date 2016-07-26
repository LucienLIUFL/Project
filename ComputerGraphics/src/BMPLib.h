#ifndef BMPLIB_H_
#define BMPLIB_H_
#include <string>
#include <memory>


namespace BMPLib {
    #pragma pack(push, 1)
    struct Bmp {
        // 14 Bytes (BMP File Header)
        unsigned short bfType; // Label of BMP file
        unsigned int bfSize;
        unsigned short bfReservedFirst;
        unsigned short bfReservedSecond;
        unsigned int bfOffBits;

        // 40 Bytes (BMP File Information Header)
        unsigned int  biSize;
        int    biWidth;
        int    biHeight;
        unsigned short   biPlanes;            // Always 1
        unsigned short   biBitCount;        //Bits of BMP File (1 4 8 16 24 32)
        unsigned int  biCompression;
        unsigned int  biSizeImage;
        int   biXPelsPerMeter;
        int   biYPelsPerMeter;
        unsigned int  biClrUsed;
        unsigned int  biClrImportant;
    };
    #pragma pack(pop)
    class BmpInfo {
    public:
        friend std::shared_ptr<BmpInfo> makeBmpInfo(const std::string & filename);

        BmpInfo();
        virtual ~BmpInfo();

        void show();

        Bmp bmp;
        unsigned char * imageData;
    };

    std::shared_ptr<BmpInfo> makeBmpInfo(const std::string & filename);
}

#endif
