#include "stdafx.h"
#include "DyvirFight.h"
#include "AbilityFactory.h"

DyvirFight::DyvirFight() {
	_abilityInventory.push_back(_abilityFactory.createFireball());
	_abilityInventory.push_back(_abilityFactory.createInferno());
	_abilityInventory.push_back(_abilityFactory.createBubble());
	_abilityInventory.push_back(_abilityFactory.createDoton());
	_abilityInventory.push_back(_abilityFactory.createPoisonGas());
	_level = 1;
	_XP = 0;
	_HPbase = 20000;
	_MPbase = 2000;
	_physicalDamagebase = 200000;
	_magicDamagebase = 150;
	_physicalResistancebase = 50;
	_magicResistancebase = 50;
	_HP = _HPbase;
	_MP = _MPbase;
	_physicalDamage = _physicalDamagebase;
	_magicDamage = _magicDamagebase;
	_physicalResistance = _physicalResistancebase;
	_magicResistance = _magicResistancebase;
	_wins = 0;
	this->setFightSprite();
	int i = stun;
	_spriteStatesPosition[int(statesSprites::stun)] = { 230, 510 };
	_spriteStatesPosition[int(statesSprites::burns)] = { 265, 510 };
	_spriteStatesPosition[int(statesSprites::poison)] = { 300, 510 };
	_spriteStatesPosition[int(statesSprites::MRincrease)] = { 335, 510 };
	_spriteStatesPosition[int(statesSprites::MDincrease)] = { 370, 510 };
	_spriteStatesPosition[int(statesSprites::PDincrease)] = { 405, 510 };
	_spriteStatesPosition[int(statesSprites::PRincrease)] = { 440, 510 };
	_spriteStatesPosition[int(statesSprites::PDdecrease)] = { 475, 510 };
	_spriteStatesPosition[int(statesSprites::MDdecrease)] = { 510, 510 };
	_spriteStatesPosition[int(statesSprites::PRdecrease)] = { 545, 510 };
	_spriteStatesPosition[int(statesSprites::MRdecrease)] = { 580, 510 };
	_spriteStatesPosition[int(statesSprites::DamageMultiplier)] = { 615, 510 };
	_spriteStatesPosition[int(statesSprites::Bleeding)] = { 650, 510 };



	////Posici�n de los sprites de estados
	//_spriteStun.setPosition(230, 510);
	//_spriteBurns.setPosition(265, 510);
	//_spritePoisoned.setPosition(300, 510);
	//_spriteMRincrease.setPosition(335, 510);
	//_spriteMDincrease.setPosition(370, 510);
	//_spritePDincrease.setPosition(405, 510);
	//_spritePRincrease.setPosition(440, 510);
	//_spritePDdecrease.setPosition(475, 510);
	//_spriteMDdecrease.setPosition(510, 510);
	//_spritePRdecrease.setPosition(545, 510);
	//_spriteMRdecrease.setPosition(580, 510);
	//_spriteDamageMultiplier.setPosition(615, 510);
	//_spriteBleeding.setPosition(650, 510);
}

void DyvirFight::update(bool enemyIsAlive, int enemyXP) {
	_physicalDamagebase = 200000;
	if (enemyIsAlive) {
		if (_isAlive) {
			_frame += 0.15;
			if (_frame >= 8 && _isAlive) {
				_frame = 0;
			}
			_sprite.setTextureRect({ int(_frame) * 260, 0, 260, 230 });
		}
		else {
			this->Die();
		}
	}
	else {
		this->Win(enemyXP);
		this->resetStats();
	}
}

void DyvirFight::getAbilityDrop(abilityName abilityDrop) {
	_abilityInventory.push_back(_abilityFactory.createAbility(abilityDrop));
}

void DyvirFight::Die() {
	if (_flagDie) {
		_frame = 0;
		_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirDead.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(1, 1);
		_flagDie = false;
	}
	_frame += 0.15;
	if (_frame >= 9) {
		_frame = 9;
	}
	_sprite.setTextureRect({ int(_frame) * 170, 0, 170, 110 });
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}

void DyvirFight::Win(int enemyXP) {
	this->increaseXP(enemyXP);
	if (_flagWin) {
		_frame = 0;
		_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirWin 110x200.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(1, 1);
		_flagWin = false;
	}
	_frame += 0.15;
	if (_frame >= 6) {
		_frame = 0;
	}
	_sprite.setTextureRect({ int(_frame) * 110, 0, 110, 200 });
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}

std::string DyvirFight::increaseXP(int XP) {
	_XP += XP;
	if (_level == 20) {
		return "Nivel m�ximo alcanzado";
	}
	if (XP >= _XPrequired[_level - 1]) {
		_level++;
		this->levelUp(_level);
		return "Ganaste " + std::to_string(XP) + " puntos de experiencia. Subiste a nivel " + std::to_string(_level);
	}
	else {
		return "Ganaste " + std::to_string(XP) + " puntos de experiencia.";
	}
}

void DyvirFight::levelUp(int level) {
	switch (level) {
		//---------------------- STAGE 1 -----------------------------------
		//BASE -> setStats(2000, 60, 150, 50, 50, 50, _XP);
		//Enemies -> _enemy->setStats(700, 200, 35, 35, 30, 30, Air, 100); 
	case 2: this->setStats(3000, 75, 50, 50, 25, 25, _XP);
		break;
		//Boss 1|lvl 3 -> _enemy->setStats(3500, 1000, 100, 100, 50, 50, Fire, 100);
	case 3: this->setStats(3500, 100, 100, 70, 50, 50, _XP);
		break;
		//---------------------- STAGE 2 -----------------------------------
		//Enemies -> _enemy->setStats(1100, 600, 80, 80, 50, 50, Earth, 150);
	case 4: this->setStats(4000, 100, 100, 100, 70, 70, _XP);
		break;
	case 5: this->setStats(4500, 100, 100, 130, 70, 70, _XP);
		break;
		//Boss 2|lvl 6 -> _enemy->setStats(5000, 1250, 150, 150, 120, 100, Air, 300);
	case 6: this->setStats(5000, 125, 150, 150, 120, 100, _XP);
		break;
		//---------------------- STAGE 3 -----------------------------------
		//Enemies -> _enemy->setStats(1700, 700, 150, 80, 80, 100, Air, 300);  
	case 7: this->setStats(5500, 125, 150, 170, 120, 120, _XP);
		break;
	case 8: this->setStats(6000, 125, 170, 170, 150, 120, _XP);
		break;
		//Boss 3 | lvl 9 -> _enemy->setStats(6500, 1250, 200, 200, 150, 150, Water, 450);
	case 9: this->setStats(6500, 125, 200, 200, 150, 120, _XP);
		break;
		//---------------------- STAGE 4 -----------------------------------
		//Enemies -> _enemy->setStats(3000, 700, 150, 150, 500, 300, Fire, 500);
	case 10: this->setStats(7500, 150, 300, 200, 150, 150, _XP);
		break;
		// Boss 4 | lvl 11 -> _enemy->setStats(8000, 2000, 300, 400, 200, 300, Water, 800);
	case 11: this->setStats(8000, 200, 400, 300, 200, 150, _XP);
		break;
		//---------------------- STAGE 5 -----------------------------------
		//Enemies -> _enemy->setStats(3500, 1000, 400, 300, 300, 250, Fire, 650);
	case 12: this->setStats(8500, 250, 500, 400, 250, 200, _XP);
		break;
		// Boss 5 | lvl 13 -> _enemy->setStats(10000, 2000, 750, 750, 350, 350, Neutral, 1500);
	case 13: this->setStats(10000, 250, 700, 500, 300, 300, _XP);
		break;
		//---------------------- STAGE EXTRA -----------------------------------
		//Enemies ->_enemy->setStats(1700, 700, 150, 80, 80, 100, Air, 300);
	case 14: this->setStats(10000, 250, 700, 700, 350, 350, _XP);
		break;
	case 15: this->setStats(10000, 250, 750, 750, 350, 350, _XP);
		break;
	case 16: this->setStats(10000, 250, 750, 750, 450, 450, _XP);
		break;
	case 17: this->setStats(10000, 250, 800, 800, 500, 500, _XP);
		break;
	case 18: this->setStats(10000, 250, 850, 850, 550, 550, _XP);
		break;
	case 19: this->setStats(10000, 250, 900, 900, 900, 900, _XP);
		break;
	case 20: this->setStats(10000, 300, 1000, 1000, 1000, 1000, _XP);
		break;
	}
}

void DyvirFight::setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalResistance, int magicResistance, int XP) {
	_HPbase = HP;
	_MPbase = MP;
	_physicalDamagebase = physicalDamage;
	_magicDamagebase = magicDamage;
	_physicalResistancebase = physicalResistance;
	_magicResistancebase = magicResistance;
}

void DyvirFight::restoreLife() {
	_HP = _HPbase;
	_MP = _MPbase;
}


std::string DyvirFight::setAbilityEquipedElement(int i, int ability) {
	{
		if (ability < _abilityInventory.size()) {
			_ability[i] = _abilityInventory[ability];
			return _ability[i].getName();
		}
		else return _ability[i].getName();
	}
}

void DyvirFight::setAbilityEquiped(Ability ability, int pos) {
	_ability[pos] = ability;
}

std::string DyvirFight::getInventoryElementName(int i) {
	if (i >= _abilityInventory.size()) {
		return "Empty";
	}
	else return _abilityInventory[i].getName();
}

std::string DyvirFight::getInventoryElementDescription(int i) {
	if (i >= _abilityInventory.size()) {
		return "Empty";
	}
	else return _abilityInventory[i].getDescription();
}

bool DyvirFight::craftAbility(std::string ab1, std::string ab2, int indexAb1, int indexAb2) {
	if (_abilityFactory.craftAbility(ab1, ab2) != CraftError) {
		if (indexAb1 < indexAb2) {
			_abilityInventory.erase(_abilityInventory.begin() + indexAb1);
			_abilityInventory.erase(_abilityInventory.begin() + indexAb2 - 1);
		}
		else {
			_abilityInventory.erase(_abilityInventory.begin() + indexAb2);
			_abilityInventory.erase(_abilityInventory.begin() + indexAb1 - 1);
		}
		_abilityInventory.push_back(_abilityFactory.createAbility(_abilityFactory.craftAbility(ab1, ab2)));
		return true;
	}
	else { return false; }
}

void DyvirFight::setFightSprite() {
	_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirFight.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,260,230 });
	_sprite.setScale(0.5, 0.5);
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
	_flagWin = true;
}
