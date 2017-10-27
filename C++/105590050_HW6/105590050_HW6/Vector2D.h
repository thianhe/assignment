#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
    public:
        Vector2D();
        Vector2D(int x, int y);
        void SetXY(int x, int y);
        int GetX();
        int GetY();
        int operator *(const Vector2D& v);		//Multiply function

    private:
        int _x;
        int _y;
};
#endif