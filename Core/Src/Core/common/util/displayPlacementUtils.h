//
// Created by grzegorz on 5/17/21.
//

#ifndef VPET_DISPLAYPLACEMENTUTILS_H
#define VPET_DISPLAYPLACEMENTUTILS_H

#include "../Vec2d/Vec2d.h"

namespace tama
{
    namespace util
    {
        extern int dispWorkspaceLeft;
        extern int dispWorkspaceRight;

        Vec2d toContentArea(const Vec2d & coords);
        Vec2d fromBottomLeft(const Vec2d & coords);
        Vec2d fromTopRight(const Vec2d & coords);

        Vec2d fromBottomRight(const Vec2d &coords);
        bool fitsInContent(const Vec2d & coords);
    }
}

#endif //VPET_DISPLAYPLACEMENTUTILS_H
