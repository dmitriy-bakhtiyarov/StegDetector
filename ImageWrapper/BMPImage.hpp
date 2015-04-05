#pragma once

#include <vector>
#include <cstdint>
#include <string>

struct RgbPixel
{
	uint8_t r, g, b;
};

struct BMPHEAD;

class UnsupportedImageFormatException
{
public:
	std::string errStr;
	UnsupportedImageFormatException(const std::string& str);
};


class FileNameError
{};

struct BMPImage
{
	size_t width, height;
	//std::string filename;
	uint8_t* planes[3];//R,G,B;

	size_t getSize()const
	{
		return width * height * 3;
	}

	RgbPixel getPixel(size_t x, size_t y)const;
	void setPixel(size_t x, size_t y, RgbPixel p);

	explicit BMPImage(const char* filename);
	virtual ~BMPImage();

private:
	BMPHEAD* head;
};