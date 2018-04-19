#include "EnemySpawner.h"
#include "Game.h"
#include "GameManager.h"
#include <fstream>

using json = nlohmann::json;

EnemySpawner::EnemySpawner()
{
	parseEnemyData();
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::parseEnemyData()
{
	std::ifstream pStream = std::ifstream("levelData.dat");
	std::string pData = std::string((std::istreambuf_iterator<char>(pStream)), std::istreambuf_iterator<char>());

	json pJsonOutput = json::parse(pData);
	json pWaves = pJsonOutput.at("waves");
	json pEnemies;
	size_t nWaves = pWaves.size();
	EnemyWaveData pWaveData;
	EnemyData pEnemyData;

	//Each wave
	for (json::iterator pWaveIterator = pWaves.begin(); pWaveIterator != pWaves.end(); ++pWaveIterator)
	{
		pWaveData = EnemyWaveData();
		pEnemies = pWaveIterator->at("enemies");

		//Each enemy
		for (json::iterator pEnemyIterator = pEnemies.begin(); pEnemyIterator != pEnemies.end(); ++pEnemyIterator)
		{
			pEnemyData = EnemyData();

			pEnemyData.m_pSpawnPosition.x = pEnemyIterator->at("x");
			pEnemyData.m_pSpawnPosition.y = pEnemyIterator->at("y");

			pWaveData.m_aEnemies.push_back(pEnemyData);
		}

		m_aEnemyWaveData.push_back(pWaveData);
	}
}

void EnemySpawner::SpawnNextWave()
{
	if (m_nCurrentWave >= m_aEnemyWaveData.size())
	{
		printf("End of game");
		return;
	}

	EnemyData pEnemy;
	EnemyWaveData pWave = m_aEnemyWaveData[m_nCurrentWave];

	for (int i = 0; i < pWave.m_aEnemies.size(); i++)
	{
		pEnemy = pWave.m_aEnemies[i];

		EnemyObject* pEnemyObject = Game::AddGameObject<EnemyObject>();
		pEnemyObject->SetPosition(pEnemy.m_pSpawnPosition);
		pEnemyObject->SetRenderLayer(1);
		GameManager::m_pInstance->AddEnemy(pEnemyObject);
	}

	m_nCurrentWave++;
}