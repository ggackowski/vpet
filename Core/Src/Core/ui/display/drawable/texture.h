//
// Created by grzegorz on 3/28/21.
//

#ifndef VPET_TEXTURE_H
#define VPET_TEXTURE_H

#include <memory>
#include "../PixelColor.h"
#include "../../../common/Vec2d/Vec2d.h"

namespace tama
{
    struct Texture
    {
        unsigned width;
        unsigned height;
        PixelColor ** data;

        Texture(unsigned int width, unsigned int height) : width(width), height(height)
        {
            data = new PixelColor*[height];
            for (unsigned i = 0; i < height; ++i)
            {
                data[i] = new PixelColor[width];
                for (unsigned j = 0; j < width; ++j)
                {
                    data[i][j] = PixelColor::WHITE;
                }
            }
        }

        Texture(unsigned int width, unsigned int height, PixelColor **data) : width(width), height(height), data(data)
        {}

        void insertAt(Vec2d position, std::shared_ptr<Texture> texture)
        {
            for (unsigned i = 0; i < texture->height; ++i)
            {
                for (unsigned j = 0; j < texture->width; ++j)
                {
                    unsigned newY = i + position.y;
                    unsigned newX = j + position.x;
                    if (shouldDrawPixel(texture, i, j, newY, newX))
                    {
                        this->data[newY][newX] = texture->data[i][j];
                    }
                }
            }
        }

        void setData(PixelColor ** d)
        {
            deleteTextureData();
            this->data = d;
        }


        void deleteTextureData()
        {
            for (unsigned i = 0; i < height; ++i)
            {
            	if (data[i] != nullptr)
            		delete[] data[i];
            }
            if (data != nullptr)
            	delete[] data;
        }


        bool shouldDrawPixel(const std::shared_ptr<Texture> &texture, unsigned int i, unsigned int j, unsigned int newY,
                             unsigned int newX) const
        { return newX < width && newY < height && texture->data[i][j] != PixelColor::TRANSPARENT; }

        ~Texture()
        {
            deleteTextureData();
        }
    };
}

#endif //VPET_TEXTURE_H
