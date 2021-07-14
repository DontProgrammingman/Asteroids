#include "Engine.h"
#include <stdlib.h>
#include <memory.h>
#include <Windows.h>
#include <conio.h>

//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'A', 'B')
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  clear_buffer() - set all pixels in buffer to 'black'
//  is_window_active() - returns true if window is active
//  schedule_quit_game() - quit game after act()


// initialize game data in this function
void initialize()
{
    class Player {
        int x = 0, y = 0;
        bool fire;
        bool ToLine(HDC hdc, int x = 0, int y = 0);
        int bias(int x, int y) { //function direction of movement of the player
            int button_vk_code;
            switch (is_key_pressed(button_vk_code)) {
            case VK_RIGHT:
                x++;
                break;
            case VK_LEFT:
                x--;
                break;
            case VK_UP:
                y++;
                break;
            case VK_DOWN:
                y--;
                break;
            }
            if (x > 1024)
                x = 0;
            if (y > 768)
                y = 0;
            if (x < 0)
                x = 1024;
            if (y < 0)
                y = 768;
        }
    };
    class Bullet : Player {
        int x, y;
        bool fire() { //function reading whether the button is pressed
            if (is_key_pressed(VK_SPACE))
                Bullet bullet;
        }
    };
    class Asteroid {
        int x, y, size;
        int trafic(int x, int y) { //function responsible for creating asteroids
            Asteroid asteroid;
            x = rand() * 1.0 *(1024 - 0 + 1) + 0;
            y = rand() * 1.0 *(768 - 0 + 1) + 0;
            return x, y;
        }
    };
    int score = 0, lives = 3;
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
  if (is_key_pressed(VK_ESCAPE))
    schedule_quit_game();
}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)
void draw()
{
  // clear backbuffer
  memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
}

// free game data in this function
void finalize()
{
    
}