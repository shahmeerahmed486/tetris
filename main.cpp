#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"

// ShahmeerAhmed
using namespace std;
using namespace sf;

int main()
{
    srand(time(0));
    RenderWindow window(VideoMode(640, 960), title);
    Texture obj1, obj2, obj3, obj4, obj5, obj6, obj7, obj8, obj9;
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background1.png");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/tiles.png");
    obj5.loadFromFile("img/tiles.png");
    obj6.loadFromFile("img/tiles.png");

    obj7.loadFromFile("img/pausemenu1.jpg");
    obj8.loadFromFile("img/instructions1.jpg");
    obj9.loadFromFile("img/mainmenu1.jpg");

    Sprite sprite(obj1), background(obj2), frame(obj3), piece1(obj4), piece2(obj5), shadows(obj6), pausemenu(obj7), help(obj8), startmenu(obj9);

    background.setScale(640.f / background.getGlobalBounds().width, 960.f / background.getGlobalBounds().height);
    frame.setScale(640.f / frame.getGlobalBounds().width, 960.f / frame.getGlobalBounds().height);
    pausemenu.setScale(640.f / pausemenu.getGlobalBounds().width, 960.f / pausemenu.getGlobalBounds().height);
    help.setScale(640.f / help.getGlobalBounds().width, 960.f / help.getGlobalBounds().height);
    startmenu.setScale(640.f / startmenu.getGlobalBounds().width, 960.f / startmenu.getGlobalBounds().height);

    // Load font for the "BOMB" text display
    Font font;
    if (!font.loadFromFile("font/arial.ttf")) { // Replace with your own font file
        cerr << "Error loading font!" << endl;
        return -1; // Terminate if the font is not found
    }

    // Create a Text object for displaying "BOMB"
    Text bombText("BOMB", font, 40);
    bombText.setFillColor(Color::Red);
    bombText.setPosition(700.f, 100.f); // Set outside the game grid (background area)

    int delta_x = 0, colorNum = 1;
    float timer = 0, delay = 0.3;
    bool rotate = 0;
    Clock clock;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        t_time += timer;

        time_min = t_time / 600;

        Event e;
        while (window.pollEvent(e))
        {                                
            if (e.type == Event::Closed)
                window.close();
            if (e.type == Event::KeyPressed)
            {                                          
                if (e.key.code == Keyboard::Up)
                    rotate = true;
                else if (e.key.code == Keyboard::Left)
                    delta_x = -1;
                else if (e.key.code == Keyboard::Right)
                    delta_x = 1;
            }
        }

        if ((Keyboard::isKeyPressed(Keyboard::Down)) && n != -7)
            delay = 0.05;

        if ((Keyboard::isKeyPressed(Keyboard::Space)) && n != -7)
        {
            hardfall();
        }

        if (Keyboard::isKeyPressed(Keyboard::P))
        {
            paused = true;
            gamepause = true;
        }

        if ((Keyboard::isKeyPressed(Keyboard::N)) && (paused == true))
        {
            newgame(timer, delay);
            paused = false;
            gamepause = false;
        }

        if ((Keyboard::isKeyPressed(Keyboard::Num1)) && (paused == true))
        {
            paused = false;
            gamepause = false;
        }

        if ((Keyboard::isKeyPressed(Keyboard::Num3)) && (paused == true))
        {
            window.draw(help);
            paused = false;
        }

        if ((Keyboard::isKeyPressed(Keyboard::Num4)) && (paused == true))
        {
            window.close();
        }

        if (gamebegin == false)
        {
            window.draw(startmenu);
        }

        if ((Keyboard::isKeyPressed(Keyboard::Num3)) && (gamebegin == false))
        {
            window.draw(help);
        }

        if ((Keyboard::isKeyPressed(Keyboard::Num4)) && (gamebegin == false))
        {
            window.close();
        }

        if ((Keyboard::isKeyPressed(Keyboard::Num1)) && (gamebegin == false))
        {
            gamebegin = true;
            newgame(timer, delay);
        }

        if (exitgame == true)
        {
            window.close();
        }

        if (gamebegin == true)
        {
            shape();
            fallingPiece(timer, delay, colorNum);
            if (n != -7)
            {
                movement(delta_x);
                rotation(rotate, n, rotations);
            }
            rowremove();
            bomb();
            gameover();
            if (exitgame == true)
            {
                window.close();
            }
            score();
            showing_shadow();
        }

        if (paused == true)
        {
            window.draw(pausemenu);
        }

        if (gamepause == false && gamebegin == true)
        {
            window.clear(Color::Black);
            window.draw(background);

            // If the bomb is falling, display the "BOMB" text
            if (n == -7)
            {
                window.draw(bombText); // Draw the "BOMB" text
            }
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (gameGrid[i][j] == 0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j] * 18, 0, 18, 18));
                sprite.setScale(2.f, 2.f); // Scale tiles 2x their original size (18 -> 36)
                sprite.setPosition(j * 36, i * 36);
                sprite.move(56, 62);

                if (gamepause == false && gamebegin == true)
                {
                    window.draw(sprite);
                }
            }
        }

        if (gamebegin && !gamepause)
        {
            for (int i = 0; i < 4; i++)
            {
                shadows.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
                shadows.setPosition(shadow[i][0] * 36, shadow[i][1] * 36);
                shadows.move(56, 62);

                shadows.setColor(Color(50, 50, 50));
                shadows.setScale(2.f, 2.f);

                window.draw(shadows);
            }
        }

        if (gamebegin && !gamepause)
        {
            for (int i = 0; i < 4; i++)
            {
                sprite.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
                sprite.setPosition(point_1[i][0] * 36, point_1[i][1] * 36);
                sprite.move(56, 62);

                sprite.setColor(Color(255, 255, 255));

                sprite.setScale(2.f, 2.f);

                window.draw(sprite);
            }
        }

        if (gamepause == false && gamebegin == true)
            window.draw(frame);

        window.display();
        delay = delayval;
        delta_x = 0;
    }
    return 0;
}
