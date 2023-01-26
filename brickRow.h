#pragma once
#include "settings.h"
#include "brick.h"
#include "SFML/Graphics.hpp"


struct BrickField {
	Brick arr[rows][columns];

};

void brick_field_init(BrickField& brickfield) {
	sf::Color color;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			  
			if (i == 0 || i == 1) color = sf::Color::Red;
			else if (i == 2 || i == 3) color = sf::Color{255,102,0};
			else if(i == 4 || i == 5) color = sf::Color::Green;
			else if (i == 6 || i == 7) color = sf::Color::Yellow;
			sf::Vector2f brick_pos{
				j * brick_width,60.f+i*brick_height };
			brick_init(brickfield.arr[i][j], color, brick_pos);
		}
	}
}
void brick_field_update(BrickField& brickfield) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			brick_update(brickfield.arr[i][j]);
		}
	}
}


	void brick_field_draw(sf::RenderWindow & window, const BrickField & brickfield){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			brick_draw(brickfield.arr[i][j], window);
		}
	}
}