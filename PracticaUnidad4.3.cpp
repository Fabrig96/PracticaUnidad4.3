//MAVI - Unidad 4 - Ejercicio 3
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture rcircle_tex;  //textura círculo rojo
Texture bcircle_tex; //textura círculo azul
Sprite rcircle_sprite; //sprite círculo rojo
Sprite bcircle_sprite; //sprite círculo azul

int main() {
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Splats");

	rcircle_tex.loadFromFile("Unidad4_Assets/rcircle.png");
	bcircle_tex.loadFromFile("Unidad4_Assets/rcircleb.png"); 
	rcircle_sprite.setTexture(rcircle_tex);
	bcircle_sprite.setTexture(bcircle_tex);

	//Vectores para almacenar posiciones de sprites
	std::vector<sf::Vector2f> rcircle_positions;  
	std::vector<sf::Vector2f> bcircle_positions;

	//Ajustar origen al centro del sprite
	rcircle_sprite.setOrigin(rcircle_sprite.getLocalBounds().width / 2, rcircle_sprite.getLocalBounds().height / 2);
	bcircle_sprite.setOrigin(bcircle_sprite.getLocalBounds().width / 2, bcircle_sprite.getLocalBounds().height / 2);
	while (App.isOpen())
	{
		sf::Event event;
		while (App.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				App.close();
				break;
			}
			
			if ( sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				
				sf::Vector2i posicionMouse = sf::Mouse::getPosition(App); //Obtener posición de mouse respecto a la ventana
				rcircle_positions.push_back(App.mapPixelToCoords(posicionMouse)); //Guardar posición del sprite respecto a posición de mouse

			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				
				sf::Vector2i posicionMouse = sf::Mouse::getPosition(App);
				bcircle_positions.push_back(App.mapPixelToCoords(posicionMouse));
			}
		
		}

		
		App.clear();
		
		for (const auto& position : rcircle_positions) {
			rcircle_sprite.setPosition(position.x, position.y); //Setear posición de cada sprite 
			App.draw(rcircle_sprite);
		}

		for (const auto& position : bcircle_positions) {
			bcircle_sprite.setPosition(position.x, position.y);
			App.draw(bcircle_sprite);
		}
		App.display();

	}
	return 0;
}
