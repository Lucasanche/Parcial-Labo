#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H
#include <string>
#include "Enemy.h"

class EnemyFactory
{
public:
    Enemy* getBoss(int);

private:
    Enemy* _enemy;
};
#endif // ENEMYFACTORY_H