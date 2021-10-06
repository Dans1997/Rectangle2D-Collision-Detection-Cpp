#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "Rectangle2D.h"
#include "Component.h"

/// <summary>
/// Copyable 2D Entity where each has a Rectangle2D bounding box and optional Components.
/// Entities can have up to one of each Component type.
/// </summary>
class Entity
{
	private:
		Rectangle2D m_boundingBox;
		std::unordered_set<Component*> m_components;

	public:
		Entity() : m_boundingBox(), m_components() {}
		Entity(Rectangle2D boundingBox) : m_boundingBox(boundingBox), m_components() {}
		Entity(const Entity& e) : m_boundingBox(e.m_boundingBox), m_components(e.m_components) {}
		Entity& operator = (const Entity& t) { return *this; }
		~Entity() { m_components.clear(); }

		bool CollidesWith(Entity&);

		void TryAddComponent(Component&);
		// TODO: void GetComponent
		// TODO: void RemoveComponent
};

