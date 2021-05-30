//
// Created by grzegorz on 5/17/21.
//
#include "displayPlacementUtils.h"

namespace tama
{
    namespace util
    {
        int dispWorkspaceLeft = 15;
        int dispWorkspaceRight = 68;
        int dispWorkspaceBottom = 47;

        Vec2d toContentArea(const Vec2d & coords)
        {
            return Vec2d(dispWorkspaceLeft + coords.x, coords.y);
        }

        Vec2d fromBottomLeft(const Vec2d &coords)
        {
            return Vec2d(dispWorkspaceLeft + coords.x, dispWorkspaceBottom + coords.y);
        }

        Vec2d fromBottomRight(const Vec2d &coords)
        {
            return Vec2d(dispWorkspaceRight + coords.x, dispWorkspaceBottom + coords.y);
        }

        Vec2d fromTopRight(const Vec2d & coords)
        {
            return Vec2d(dispWorkspaceRight + coords.x, coords.y);
        }

        bool fitsInContent(const Vec2d & coords)
        {
            return coords.x >= dispWorkspaceLeft && coords.x <= dispWorkspaceRight && coords.y >= 0 && coords.y <= dispWorkspaceBottom;
        }
    }
}

