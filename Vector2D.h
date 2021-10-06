#pragma once

/// <summary>
/// This class represents a floating point 2D Vector.
/// </summary> 
class Vector2D
{
    public:
        float x;
        float y;

        Vector2D() : x(0), y(0) {}
        Vector2D(float x, float y) : x(x), y(y) {}

        friend bool operator==(const Vector2D& a, const Vector2D& b)
        {
            return (a.x == b.x) && (a.y == b.y);
        }

        friend bool operator!=(const Vector2D& a, const Vector2D& b)
        {
            return !(a == b);
        }
};

