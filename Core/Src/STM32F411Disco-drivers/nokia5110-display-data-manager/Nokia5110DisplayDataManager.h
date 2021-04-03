//
// Created by grzegorz on 3/31/21.
//

#ifndef VPET_NOKIA5110DISPLAYDATAMANAGER_H
#define VPET_NOKIA5110DISPLAYDATAMANAGER_H

#include "../../Core/ui/display/display-data-manager/DisplayDataManager.h"
#include "../../Core/ui/display/display-data/DisplayData.h"
#include "../../Configuration/display.config.h"

namespace tama
{
    class Nokia5110DisplayDataManager : public DisplayDataManager
    {
    public:
        DisplayData getActiveSceneDisplayData(std::shared_ptr<Texture>) override;

    private:
        unsigned segmentSize = 8;
        unsigned segmentsInHeight = Config_Display_Height / segmentSize; // 6
        unsigned segmentsInWidth = Config_Display_Width;
        unsigned dataSize = segmentsInHeight * segmentsInWidth;
        unsigned dataFragmentSize = sizeof(uint8_t);

        void setPixel(uint8_t &, unsigned, PixelColor);
    };
}



#endif //VPET_NOKIA5110DISPLAYDATAMANAGER_H
