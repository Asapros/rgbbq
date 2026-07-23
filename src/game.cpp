#include "game.h"
#include "systems/camera.h"
#include "systems/tilemap.h"
#include "systems/counter.h"
#include "systems/obstacle.h"
#include "systems/player.h"
#include "systems/level.h"

#include <raylib.h>

Game::Game() {
    this->systems.emplace_back(std::make_unique<TilemapSystem>(this->state));
    this->systems.emplace_back(std::make_unique<CameraSystem>(this->state));
    this->systems.emplace_back(std::make_unique<CounterSystem>(this->state));
    this->systems.emplace_back(std::make_unique<ObstacleSystem>(this->state));
    this->systems.emplace_back(std::make_unique<PlayerSystem>(this->state));
    this->systems.emplace_back(std::make_unique<LevelSystem>(this->state));
}

void Game::init() {
    for (auto& system : this->systems) {
        system->init();
    }
}

void Game::tick() {
    for (auto& system : this->systems) {
        system->tick();
    }
}

void Game::draw() {
    for (auto& system : this->systems) {
        system->before_draw();
    }
    for (auto& system : this->systems) {
        system->draw();
    }
    for (auto& system : this->systems) {
        system->after_draw();
    }
}
