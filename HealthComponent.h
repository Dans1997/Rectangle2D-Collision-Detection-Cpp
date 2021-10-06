#pragma once
#include "Component.h"

class HealthComponent : public Component
{
	private:
		int m_health;

	public:
		HealthComponent() : m_health(0) {}
};

