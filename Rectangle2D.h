#pragma once
#include "Vector2D.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

/// <summary>
/// This class represents an axis-aligned Rectangle2D with floating-point coordinates.
/// </summary>
class Rectangle2D
{
	private:
		Vector2D center;
		float width, height;

	public:
		Rectangle2D() : center(0, 0), width(1), height(1) {}
		Rectangle2D(Vector2D c, float w, float h) : center(c), width(w), height(h) {}

		float MinX() const { return center.x - width / 2; }
		float MaxX() const { return center.x + width / 2; }
		float MinY() const { return center.y - height / 2; }
		float MaxY() const { return center.y + height / 2; }
		float Area() const { return width * height; }

		Vector2D GetCenter() const { return center; }
		Vector2D GetTopLeft() const { return Vector2D(MinX(), MaxY()); }
		Vector2D GetTopRight() const { return Vector2D(MaxX(), MaxY()); }
		Vector2D GetBottomLeft() const { return Vector2D(MinX(), MinY()); }
		Vector2D GetBottomRight() const { return Vector2D(MaxX(), MinY()); }

		bool IsValid() const { return width != 0 && height != 0; }
		bool IntersectsWith(Rectangle2D&);

		friend bool operator==(const Rectangle2D& a, const Rectangle2D& b)
		{
			if (a.GetCenter() != b.GetCenter()) return false;
			if (a.Area() != b.Area()) return false;
			if (a.GetTopLeft() != b.GetTopLeft()) return false;
			if (a.GetTopRight() != b.GetTopRight()) return false;
			if (a.GetBottomLeft() != b.GetBottomLeft()) return false;
			if (a.GetBottomRight() != b.GetBottomRight()) return false;
			return true;
		}
};

#endif

