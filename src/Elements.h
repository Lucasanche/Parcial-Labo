#pragma once
#ifndef ELEMENTS_H
#define ELEMENTS_H


enum elements
{
	Neutral = 0,
	Fire,
	Water,
	Air,
	Earth
};

enum abilityName
{
	Fireball = 0,
	Bubble,
	WindBlow,
	EarthArmor,
	Barrier,
	Heal,
	Restore,
	EarthBarrier,
	WindBarrier,
	WaterBarrier,
	FireBarrier,
	Mirror,
	Tsunami,
	FireTornado,
	HotVampire,
	Earthquake,
	Geiser,
	PoisonGas,
	MagmaWave,
	Inferno,
	Swirl,
	SabakuKyu,
	Doton
};

enum positiveStates
{
	increasePD = 0,
	increaseMR,
	increaseMD,
	heal,
	restore,
	doton,
	waterResist,
	fireResist,
	airResist,
	earthResist,
	damageMultiplier,
	trueDamage
};

enum negativeStates
{
	vampireishon = 0,
	stun,
	burns,
	poison,
	reducePD,
	reduceMR,
	reduceAtt,
};

enum turns
{
	start = 0,
	wait,
	attack,
	ability1,
	ability2,
	ability3,
	enemyUpdateText,
	enemyWait,
	enemyAttack,
	enemyAbility1,
	enemyAbility2,
	updateText
};

#endif