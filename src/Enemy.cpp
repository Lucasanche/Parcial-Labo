#include "stdafx.h"
#include "Enemy.h"
#include "AbilityFactory.h"


Enemy::Enemy(std::string path, int rectWidth, int rectHeight, int totalFrames, float scale, int filas) {
	_filas = filas;
	_frameY = 0;
	_texture.loadFromFile(path);
	_sprite.setTexture(_texture);
	_totalFrames = totalFrames;
	_rectWidth = rectWidth;
	_rectHeight = rectHeight;
	_sprite.setTextureRect({ int(_frame) * _rectWidth, 0, _rectHeight, _rectWidth });
	_sprite.setTextureRect({ int(_frame) * 100, int(_frameY) * 100, 100, 100 });
	_sprite.setScale(scale, scale);
	_sprite.setPosition(750 - _sprite.getGlobalBounds().width, 480 - _sprite.getGlobalBounds().height);
	std::cout << _sprite.getGlobalBounds().height << std::endl;

	//Posici�n de los sprites de estados
	_spriteStatesPosition[int(statesSprites::stun)] =		{ 610, 68 };
	_spriteStatesPosition[int(statesSprites::burns)] =		{ 650, 75 };
	_spriteStatesPosition[int(statesSprites::poison)] =		{ 685, 75 };
	_spriteStatesPosition[int(statesSprites::MRincrease)] = { 720, 75 };
	_spriteStatesPosition[int(statesSprites::MDincrease)] = { 755, 75 };
	_spriteStatesPosition[int(statesSprites::PDincrease)] = { 615, 95 };
	_spriteStatesPosition[int(statesSprites::PRincrease)] = { 650, 110 };
	_spriteStatesPosition[int(statesSprites::PDdecrease)] = { 685, 110 };
	_spriteStatesPosition[int(statesSprites::MDdecrease)] = { 720, 110 };
	_spriteStatesPosition[int(statesSprites::PRdecrease)] = { 755, 110 };
	_spriteStatesPosition[int(statesSprites::MRdecrease)] = { 615, 125 };
	_spriteStatesPosition[int(statesSprites::DamageMultiplier)] = { 615, 510 };
	_spriteStatesPosition[int(statesSprites::Bleeding)]	 =  { 650, 510 };
//	_spriteStun.setPosition		   (610, 68);
//	_spriteBurns.setPosition	   (650, 75);
//	_spritePoisoned.setPosition    (685, 75);
//	_spriteMRincrease.setPosition  (720, 75);
//	_spriteMDincrease.setPosition  (755, 75);
//	_spritePDincrease.setPosition  (615, 95);
//	_spritePRincrease.setPosition  (650, 110);
//	_spritePDdecrease.setPosition  (685, 110);
//	_spriteMDdecrease.setPosition  (720, 110);
//	_spritePRdecrease.setPosition  (755, 110);
//	_spriteMRdecrease.setPosition  (615, 125);
//_spriteDamageMultiplier.setPosition(615, 510);
//	_spriteBleeding.setPosition    (650, 510);
}

void Enemy::setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalResistance, int magicResistance, elements elementWeak, elements elementResist, int XP) {
	_HP = HP;
	_HPbase = _HP;
	_MP = MP;
	_MPbase = _MP;
	_physicalDamage = physicalDamage;
	_physicalDamagebase = _physicalDamage;
	_magicDamage = magicDamage;
	_magicDamagebase = _magicDamage;
	_physicalResistance = physicalResistance;
	_physicalResistancebase = _physicalResistance;
	_magicResistance = magicResistance;
	_magicResistancebase = _magicResistance;
	_elementWeak = elementWeak;
	_elementResist = elementResist;
	_XP = XP;
}


void Enemy::Die() {
	if (_flagDie) {
		_frame = 0;
		_frameY = 0;
		_flagDie = false;
		_texture.loadFromFile("./Textures/Characters/spritesheets/EnemyDeath.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(4, 4);
		_sprite.setPosition(400, 150);
	}
	_frame += 0.5;
	if (_frame >= 8) {
		_frame = 0;
		_frameY++;
		if (_frameY >= 9) {
			_frameY = 9;
			_frame = 9;
		}
	}
	_sprite.setTextureRect({ int(_frame) * 100, int(_frameY) * 100, 100, 100 });
}

void Enemy::update(bool dyvirIsAlive, int XP) {
	if (dyvirIsAlive) {
		if (_isAlive) {
			if (_filas == 1) {
				_frame += 0.15;
				if (_frame >= _totalFrames && _isAlive) {
					_frame = 0;
				}
				_sprite.setTextureRect({ int(_frame) * _rectWidth, 0, _rectWidth, _rectHeight });
			}
			if (_filas > 1) {
				_frame += 0.15;
				if (_frame >= _totalFrames && _isAlive) {
					_frame = 0;
					std::cout << _frameY << std::endl;
					_frameY++;
					if (_frameY >= _filas) {
						_frameY = 0;
						_frame = 0;
					}
				}
				_sprite.setTextureRect({ int(_frame) * _rectWidth, int(_frameY) * _rectHeight, _rectWidth, _rectHeight });
			}
			_sprite.setPosition(750 - _sprite.getGlobalBounds().width, 480 - _sprite.getGlobalBounds().height);
		}
		else {
			this->Die();
		}
	}
}

//UPDATE VIEJO
/*void Enemy::update(bool dyvirIsAlive) {
	if (dyvirIsAlive) {
		if (_isAlive) {
			_frame += 0.15;
			if (_frame >= _totalFrames && _isAlive) {
				_frame = 0;
			}
			_sprite.setPosition(750 - _sprite.getGlobalBounds().width, 480 - _sprite.getGlobalBounds().height);
			_sprite.setTextureRect({ int(_frame) * _rectWidth, 0, _rectWidth, _rectHeight });
		}
		else {
			this->Die();
		}
	}
}*/