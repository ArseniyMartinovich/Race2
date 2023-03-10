#include <SFML/Graphics.hpp>
#include "settings.h"
#include "road.h"
#include "car.h"

using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, Style::Titlebar | Style::Close);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	RoadLayer grass1, grass2;
	roadLayerInit(grass1, sf::Vector2f(0.f, 0.f), "grass.jpg", 0.f);
	roadLayerInit(grass2, sf::Vector2f(0.f, -WINDOW_HEIGHT), "grass.jpg", 0.f);


	RoadLayer send1, send2;
	roadLayerInit(send1, sf::Vector2f(50.f, 0.f), "send.jpg", 50.f);
	roadLayerInit(send2, sf::Vector2f(50.f, -WINDOW_HEIGHT), "send.jpg", 50.f);

	RoadLayer road1, road2;
	roadLayerInit(road1, sf::Vector2f(100.f, 0.f), "road.jpg", 100.f);
	roadLayerInit(road2, sf::Vector2f(100.f, -WINDOW_HEIGHT), "road.jpg", 100.f);


	Car car;
	carInit(car, CAR_POS, "car.jpg");

	

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		roadLayerUpdate(grass1);
		roadLayerUpdate(grass2);
		roadLayerUpdate(send1);
		roadLayerUpdate(send2);
		roadLayerUpdate(road1);
		roadLayerUpdate(road2);
		carUpdate(car);

		// Отрисовка окна 
		window.clear();
		roadLayerDraw(window, grass1);
		roadLayerDraw(window, grass2);
		roadLayerDraw(window, send1);
		roadLayerDraw(window, send2);
		roadLayerDraw(window, road1);
		roadLayerDraw(window, road2);
		carDraw(window, car);
		window.display();
	}

	return 0;
}