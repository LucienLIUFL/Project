#include "BMPLib.h"
#include <cstdio>
#include <string>
#include <memory>

std::shared_ptr<BMPLib::BmpInfo> BMPLib::makeBmpInfo(const std::string & filename) {
    FILE * file = fopen(filename.c_str(), "r");
    std::shared_ptr<BMPLib::BmpInfo> bmpInfo = std::make_shared<BMPLib::BmpInfo>();

    BMPLib::Bmp bmp;
    fseek(file, 0, 0);
    fread(&bmp, sizeof(BMPLib::Bmp), 1, file);
    bmpInfo->imageData = new unsigned char[bmp.biSizeImage];
    fseek(file, (long)bmp.bfOffBits, 0);
    fread(bmpInfo->imageData, sizeof(unsigned char), bmp.biSizeImage, file);
    fclose(file);

    bmpInfo->bmp = bmp;
    return bmpInfo;
}
