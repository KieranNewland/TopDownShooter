#pragma once
#include "EnemyObject.h"
#include "EnemyWaveData.h"
#include "nlohmann\json.hpp"

class EnemySpawner
{
public:
	EnemySpawner();
	~EnemySpawner();

public:
	void SpawnNextWave();

private:
	void parseEnemyData();

	std::vector<EnemyWaveData> m_aEnemyWaveData;
	int m_nCurrentWave;
};

