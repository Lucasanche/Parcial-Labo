#pragma once
#include "Dragon.h"
#include "AbilityFactory.h"
#include "Ability.h"


class Enemy : public Dragon
{
private:
	int _frameY;
	//AbilityFactory* abilityFactory;
	AbilityFactory abilityFactory;
public:
	Enemy(std::string path, int widht, int height, int totalFrames);
	void setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalDefense, int magicResist, elements elementWeak);
	void setAbility(Ability& ability, abilityName abName);
	void setAbility1(abilityName);
	void setAbility2(abilityName);
	void update(bool) override;
	void Die() override;
};
