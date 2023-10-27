#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    // Load the font file.
    sf::Font font;

    if (!font.loadFromFile("../assets/fonts/font.ttf"))
    {
        std::cout << "Error loading font file." << std::endl;
        return 1;
    }

    // Create a new render window.
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Text Example");
    window.setFramerateLimit(60);

    // Create a clock to track the time.
    sf::Clock clock;

    // Create a text object to display the FPS.
    sf::Text fpsText("0 FPS", font, 24);

    // Start the game loop.
    while (window.isOpen())
    {
        // Clear the window.
        window.clear();

        // Calculate the FPS.
        float fps = 1.f / clock.getElapsedTime().asSeconds();
        clock.restart();

        // Update the FPS text.
        fpsText.setString(std::to_string(static_cast<int>(fps)) + " FPS");

        // Draw the text to the window.
        window.draw(fpsText);

        // Display the window.
        window.display();

        // Handle events.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}