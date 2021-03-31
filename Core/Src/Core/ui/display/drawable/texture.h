//
// Created by grzegorz on 3/28/21.
//

#ifndef VPET_TEXTURE_H
#define VPET_TEXTURE_H

#include "../PixelColor.h"

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
                    unsigned newX = i + position.y;
                    unsigned newY = j + position.x;
                    if (newX < width && newY < height)
                    {
                        this->data[newX][newY] = texture->data[i][j];
                    }
                }
            }
        }

        virtual ~Texture()
        {
            for (unsigned i = 0; i < height; ++i)
            {
                delete[] data[i];
            }
            delete[] data;
        }
    };
}

#endif //VPET_TEXTURE_H
