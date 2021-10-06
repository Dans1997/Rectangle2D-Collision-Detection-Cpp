#pragma once
#include "Component.h"

/// <summary>
/// Movement handling component.
/// </summary>
class MovementComponent : public Component
{
	private:
		float m_speed;	

	public:
		MovementComponent() : m_speed(0) {}
};

