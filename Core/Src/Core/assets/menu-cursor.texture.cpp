//
// Created by grzegorz on 5/26/21.
//
#include "menu-cursor.texture.h"

namespace tama
{
    namespace asset
    {
        const short menuCursor_data[] = {0x00,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x00,0x00,0x0f,0x0f,0x0f,0x0f,0x0f,0x00,0x00,0x00,0x0f,0x0f,0x0f,0x0f,0x00,0x00,0x00,0x00,0x0f,0x0f,0x0f,0x00,0x00,0x00,0x0f,0x0f,0x0f,0x0f,0x00,0x00,0x0f,0x0f,0x0f,0x0f,0x0f,0x00,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f};
        TextureAsset menuCursor { const_cast<short *>(menuCursor_data), 7, 7 };

    }
}