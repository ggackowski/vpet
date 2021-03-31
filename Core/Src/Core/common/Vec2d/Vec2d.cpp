//
// Created by grzegorz on 3/25/21.
//

#include "Vec2d.h"

tama::Vec2d tama::Vec2d::operator+(tama::Vec2d delta)
{
    return Vec2d(this->x + delta.x, this->y + delta.y);
}

tama::Vec2d::Vec2d(int i, int j)
{
    x = i;
    y = j;
}
