#include "Rectangle2D.h"

/// <summary>
/// Checks if two Rectangle2Ds intersect.
/// </summary>
/// <param name="otherRect"></param>
/// <returns></returns>
bool Rectangle2D::IntersectsWith(Rectangle2D& otherRect)
{
	if (!otherRect.IsValid()) return false;
	else if (otherRect.MinX() >= MaxX() || otherRect.MaxX() <= MinX()) return false;
	else if (otherRect.MinY() >= MaxY() || otherRect.MaxY() <= MinY()) return false;
	return true;
}
