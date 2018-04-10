#pragma once
#include "EnemyObject.h"
#include "nlohmann\json.hpp"

class EnemySpawner
{
public:
	EnemySpawner();
	~EnemySpawner();

public:
	void SpawnNextWave();
};

