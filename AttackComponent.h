#pragma once
#include "Component.h"

/// <summary>
/// Attack handling component.
/// </summary>
class AttackComponent : public Component
{
	unsigned int m_attackPower;

	public:
		AttackComponent() : m_attackPower(0) {}
};

