#pragma once
#include "Component.h"

class AttackComponent : public Component
{
	unsigned int m_attackPower;

	public:
		AttackComponent() : m_attackPower(0) {}
};

