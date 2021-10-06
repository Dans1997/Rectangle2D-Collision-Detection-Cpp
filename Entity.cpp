#include "Entity.h"

/// <summary>
/// Adds the passed component to the component collection.
/// </summary>
/// <param name="componentToAdd"></param>
void Entity::TryAddComponent(Component& componentToAdd)
{
	try
	{
		m_components.insert(&componentToAdd);
	}
	catch (...)	
	{
		std::cerr << "Error inserting component to entity." << "\n";
	}
}

/// <summary>
/// Do the entity rects intersect?
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
bool Entity::CollidesWith(Entity& other)
{
	return m_boundingBox.IntersectsWith(other.m_boundingBox);
}
