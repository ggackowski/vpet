//
// Created by grzegorz on 6/4/21.
//

#include "heal.texture.h"

namespace tama
{
    namespace asset
    {
        extern const short heal0_data[] = {0x05,0x05,0x00,0x05,0x00,0x05,0x05,0x05,0x05,0x00,0x05,0x00,0x05,0x05,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x05,0x05,0x00,0x05,0x00,0x05,0x05,0x05,0x05,0x00,0x05,0x00,0x05,0x05};
        extern const short heal1_data[] = {0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x00,0x05,0x05,0x05,0x05,0x05,0x05,0x00,0x05,0x05,0x05,0x05,0x00,0x00,0x00,0x00,0x00,0x05,0x05,0x05,0x05,0x00,0x05,0x05,0x05,0x05,0x05,0x05,0x00,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05};

        TextureAsset heal0 { const_cast<short *>(heal0_data), 7, 7 };
        TextureAsset heal1 { const_cast<short *>(heal1_data), 7, 7 };

    }
}