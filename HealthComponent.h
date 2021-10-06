#pragma once
#include "Component.h"

/// <summary>
/// Health handling component.
/// </summary>
class HealthComponent : public Component
{
	private:
		int m_health;

	public:
		HealthComponent() : m_health(0) {}
};

