#pragma once
#include "Component.h"

class MovementComponent : public Component
{
	private:
		float m_speed;	

	public:
		MovementComponent() : m_speed(0) {}
};

