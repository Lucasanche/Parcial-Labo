#pragma once
#include <SFML/Graphics.hpp>

class DyvirFight : public sf::Drawable
{
private:
	int _HP;
	int _BaseDamage;
	int _statusHP;
	int _lenghtHP;
	/*int BaseDefense;
	int ElectricDamage;
	int FireDamage;*/
	bool _isAlive;
	bool _flagDie;
	float _frame;
	sf::Texture _texture;
	sf::Sprite _sprite;

	//Barra de vida
	sf::Texture _textureHP;
	sf::Sprite _spriteHP;
	sf::Sprite _spriteHPFill;
	
public:
	DyvirFight();
	/// Getters
	int getHP() { return _HP; }
	int getBaseDamage() { return _BaseDamage; }
	bool getIsAlive() { return _isAlive; }
	void update();
	//bool changeStatus();
	void Die();
	int doDamage();
	void updateSpriteHP();
	void damageTaken(int);

	///Setters
	void setHP(int hp) { _HP = hp; }
	void setIsAlive(bool isAlive) { _isAlive = isAlive; }

	//Functions
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


