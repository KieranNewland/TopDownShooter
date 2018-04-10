#include "EnemySpawner.h"
#include "Game.h"
#include "GameManager.h"
#include <fstream>

using json = nlohmann::json;

EnemySpawner::EnemySpawner()
{
	std::ifstream pStream = std::ifstream("levelData.dat");
	std::string pData = std::string((std::istreambuf_iterator<char>(pStream)), std::istreambuf_iterator<char>());
	printf(pData.c_str());

	json pJsonOutput = json::parse(pData);
	json pWaves = pJsonOutput["waves"];
	json pEnemies = pWaves["enemies"];
	for (int i = 0; i < pEnemies.size(); i++)
		printf(pEnemies[i]["name"].get<std::string>().c_str());
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::SpawnNextWave()
{
	for (int i = 0; i < 5; i++)
	{
		EnemyObject* pEnemyObject = Game::AddGameObject<EnemyObject>();
		pEnemyObject->SetPosition(sf::Vector2f(200 + i * 100, 100));
		pEnemyObject->SetRenderLayer(1);
		GameManager::m_pInstance->AddEnemy(pEnemyObject);
	}
}