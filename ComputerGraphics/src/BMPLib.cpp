#include "BMPLib.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <memory>

BMPLib::BmpInfo::BmpInfo() : imageData(nullptr) {}
BMPLib::BmpInfo::~BmpInfo() {
    delete imageData;
}

void BMPLib::BmpInfo::show() {
    std::cout << "bfType: "<< this->bmp.bfType << std::endl;
    std::cout  << "bfSize: "<< this->bmp.bfSize << std::endl;
    std::cout << "bfReservedFirst: "<< this->bmp.bfReservedFirst << std::endl;
    std::cout << "bfReservedSecond: "<< this->bmp.bfReservedSecond << std::endl;
    std::cout << "bfOffBits: "<< this->bmp.bfOffBits << std::endl;
    std::cout << "biSize: "<< this->bmp.biSize << std::endl;
    std::cout << "biWidth: "<< this->bmp.biWidth << std::endl;
    std::cout<< "biHeight: " << this->bmp.biHeight << std::endl;
    std::cout<< "biSizeImage: " << this->bmp.biSizeImage << std::endl;
}

std::shared_ptr<BMPLib::BmpInfo> BMPLib::makeBmpInfo(const std::string & filename) {
    FILE * file = fopen(filename.c_str(), "r");
    if (!file) {
        std::cerr << "FILE IS NOT EXISTS:" << filename << std::endl;
        return nullptr;
    }

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
