//
// Created by grzegorz on 3/31/21.
//

#include "Nokia5110DisplayDataManager.h"

tama::DisplayData tama::Nokia5110DisplayDataManager::getActiveSceneDisplayData(std::shared_ptr<Texture> texture)
{
    uint8_t * data = new uint8_t[dataSize];
    for (unsigned i = 0; i < texture->height; ++i)
    {
        for (unsigned j = 0; j < texture->width; ++j) //i = 32, j = 60
        {
            unsigned segmentHeightNumber = i / segmentSize; // 0, 1, .., 6 -> 4
            unsigned bitInSegment = i % segmentSize; // 0 ... 7 -> 0
            setPixel(data[segmentHeightNumber * segmentsInWidth + j], bitInSegment, texture->data[i][j]);
        }
    }
    return DisplayData{data, dataSize, dataFragmentSize};
}

void tama::Nokia5110DisplayDataManager::setPixel(uint8_t & pixelSegment, unsigned position, tama::PixelColor color)
{
    if (color == PixelColor::WHITE)
    {
       pixelSegment |= 1 << position;
    } else {
        pixelSegment&= ~(1 << position);
    }
}
