//
// Created by grzegorz on 3/25/21.
//

#ifndef VPET_VEC2D_H
#define VPET_VEC2D_H

namespace tama
{
    class Vec2d
    {
    public:
        Vec2d(int x, int y);
        Vec2d(): x(0), y(0) {}

        int x;
        int y;
        Vec2d operator+(Vec2d);
    };
}



#endif //VPET_VEC2D_H
