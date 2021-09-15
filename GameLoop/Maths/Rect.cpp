#include "rect.h"

bool Rect::Contains(Vec2 vec2)
{
    return vec2.x >= x && vec2.x <= x + w && vec2.y >= y && vec2.y <= y + h;
}
