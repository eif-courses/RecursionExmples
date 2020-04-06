#include <SFML/Graphics.hpp>

using namespace sf;

void recursive_draw(sf::RenderTarget &target, float x, float y, float width, float height){
  sf::RectangleShape rectangle{ { x, y } };
  rectangle.setFillColor(sf::Color::White);
  rectangle.setOutlineColor(sf::Color::Blue);
  rectangle.setOutlineThickness(5);
  rectangle.setPosition({ target.getSize().x / 2 - rectangle.getSize().x / 2, target.getSize().y /2 - rectangle.getSize().y / 2 });

  target.draw(rectangle);

  if(x >= 0) {
    recursive_draw(target,x - 50, y - 50, width-50, height-50);
  }

}

void drawCircle(sf::RenderTarget &target, float x, float y, float radius){

  sf::CircleShape circle;
  circle.setRadius(radius);
  circle.setOutlineColor(sf::Color::Red);
  circle.setOutlineThickness(5);
  circle.setPosition(x, y);

  target.draw(circle);

  if(radius > 2){
    drawCircle(target, x + radius/2, y, radius/2);
    drawCircle(target, x - radius/2, y, radius/2);
  }
}




int main() {
  sf::RenderWindow window{ { 800, 800 }, "Main Loop" };
  window.setFramerateLimit(60);
  while (window.isOpen())
  {
    sf::Event event{};
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }
    window.clear(sf::Color::White);

    //drawCircle(window, 300, 300, 300); // recursive circles function call
    recursive_draw(window, 600, 600, 800, 800);
    window.display();
  }
  return 0;
}
