//
// Created by grzegorz on 3/25/21.
//

#ifndef VPET_NOKIA5510DISPLAY_H
#define VPET_NOKIA5510DISPLAY_H


#include "DisplayConfig.h"
#include "../../Core/ui/display/PixelColor.h"
#include "../../Core/ui/display/Display.h"

namespace tama
{
    class Nokia5510Display : public Display
    {

    public:
        void displayData() override;

        void setData(DisplayData &) override;

        explicit Nokia5510Display(DisplayConfig &);

    private:
        DisplayConfig cfg;
        const unsigned width = 84;
        const unsigned height = 48;
        void displayPixel(uint8_t);
        void writeCommand(uint8_t);
    };
}



#endif //VPET_NOKIA5510DISPLAY_H
