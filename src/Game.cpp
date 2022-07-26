#include "stdafx.h"
#include "Game.h"

Game::Game() : _window(sf::VideoMode(800, 700), "Proyectazo"), _mainMenu(float(_window.getSize().x), float(_window.getSize().y)), _map(_window) {
	_window.setFramerateLimit(60);
	_background.setTextureRect({ 0,0,800,700 });
	_option = 0;
	_loadGameOption = 0;
}

void Game::Play() {
	while (_window.isOpen()) {
		while (_window.pollEvent(event)) {
			_window.clear();
			if (event.type == sf::Event::Closed) {
				_window.close();
			}
		}
		_window.clear();
		switch (_option) {
		case 0:
			_option = _mainMenu.update();
			_backgroundTexture.loadFromFile("./Textures/Backgrounds/MenuInicio.jpg");
			_background.setTexture(_backgroundTexture);
			_window.draw(_background);
			_window.draw(_mainMenu);
			break;
		case 1:
			_option = _map.update(_window, _loadGameOption);
			if (_option == 4) {
				_mainMenu.setOption(4);
			}
			break;
		case 2:
			_option = _mainMenu.update();
			_loadGameOption = _mainMenu.getLoadGameIndex();
			_window.draw(_background);
			_window.draw(_mainMenu);
			break;
		case 3:
			_window.close();
			break;
		case 4:
			_mainMenu.setErrorLoadGame();
			_option = _mainMenu.update();
			_loadGameOption = 0;
			_window.draw(_background);
			_window.draw(_mainMenu);
			break;
		}
		_window.display();
	}
}

Game::~Game() {
	std::cout << "Gracias por jugar a nuestro juego\n";
	std::cin;
}
