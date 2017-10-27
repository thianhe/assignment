#include "Vector2D.h"

Vector2D::Vector2D()
{
    _x = 0;
    _y = 0;
}
Vector2D::Vector2D(int x, int y)
{
    _x = x;
    _y = y;
}

void Vector2D::SetXY(int x, int y)
{
    _x = x;
    _y = y;
}

int Vector2D::GetX()
{
    return _x;
}
int Vector2D::GetY()
{
    return _y;
}

int Vector2D::operator* (const Vector2D& v)
{
    return (_x * v._x) + (_y * v._y);
}


