#include "game.h"
#include "camera.h"
#include "controls.h"
#include "player.h"
#include "tilemap.h"
#include <memory>
#include <raylib.h>

Game::Game() {
    this->systems.emplace_back(std::make_unique<CameraSystem>(this->state));
    this->systems.emplace_back(std::make_unique<TilemapSystem>(this->state));
    this->systems.emplace_back(std::make_unique<ControlsSystem>(this->state));
    this->systems.emplace_back(std::make_unique<PlayerSystem>(this->state));
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
