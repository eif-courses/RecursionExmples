#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void recursive_draw(sf::RenderTarget &target, float x, float y, float width, float height) {
  sf::RectangleShape rectangle{{x, y}};
  rectangle.setFillColor(sf::Color::White);
  rectangle.setOutlineColor(sf::Color::Blue);
  rectangle.setOutlineThickness(5);
  rectangle.setPosition(
      {target.getSize().x / 2 - rectangle.getSize().x / 2, target.getSize().y / 2 - rectangle.getSize().y / 2});

  target.draw(rectangle);

  if (x >= 0) {
    recursive_draw(target, x - 50, y - 50, width - 50, height - 50);
  }

}

void drawCircle(sf::RenderTarget &target, float x, float y, float radius) {

  sf::CircleShape circle;
  circle.setRadius(radius);
  circle.setOutlineColor(sf::Color::Red);
  circle.setOutlineThickness(5);
  circle.setPosition(x, y);

  target.draw(circle);

  if (radius > 2) {
    drawCircle(target, x + radius / 2, y, radius / 2);
    drawCircle(target, x - radius / 2, y, radius / 2);
  }
}

void displayDrawingUsingSFMLLibrary() {
  sf::RenderWindow window{{800, 800}, "Main Loop"};
  window.setFramerateLimit(60);
  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear(sf::Color::White);
    //drawCircle(window, 300, 300, 300); // recursive circles function call
    recursive_draw(window, 600, 600, 800, 800);
    window.display();
  }
}

int factorial(int n) {
  return n == 0 ? 1 : factorial(n - 1) * n;
}

int ackerman(int m, int n) {
  if (m == 0) return n + 1;
  else if (n == 0) return ackerman(m - 1, 1);
  else return ackerman(m - 1, ackerman(m, n - 1));
}

void generate(char* arr, int i, std::string s, int len)
{
  // base case
  if (i == 0) // when len has been reached
  {
    // print it out
    std::cout << s << "\n";
    return;
  }

  // iterate through the array
  for (int j = 0; j < len; j++) {

    // Create new string with next character
    // Call generate again until string has
    // reached its len
    std::string appended = s + arr[j];
    generate(arr, i - 1, appended, len);
  }

}

// function to generate all possible passwords
void crack(char* arr, int len)
{
  // call for all required lengths
  for (int i = 1; i <= len; i++) {
    generate(arr, i, "", len);
  }
}

void generateAllPossibleCombinations(){
  char arr[] = { 'a', 'b'};
  int len = sizeof(arr) / sizeof(arr[0]);
  crack(arr, len);
}






int main() {

  // 1 example Linear recursion fatorial
  std::cout << "factorial: " << factorial(5) << std::endl;

  // 2 example Nested recursion Ackerman function
  std::cout << "ackerman: " << ackerman(2, 3) << std::endl;

  // 3 example All possible symbols combination
  generateAllPossibleCombinations();

  // 4 example using SFML graphics Library
  // You must install before run it https://www.sfml-dev.org/download.php

  displayDrawingUsingSFMLLibrary();



  return 0;
}
