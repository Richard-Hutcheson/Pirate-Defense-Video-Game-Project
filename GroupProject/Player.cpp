/*
 * Author: Brandon Valiente
 * Assignment Title: Group Project
 * Assignment Description: This program creates a controllable player class
 * Due Date: 12/9/2019
 * Date Created: 12/9/19
 * Date Last Modified: 12/9/19
 */

#include "Player.h"



Player::Player(){
    cannonSizeX = 40;
    cannonSizeY = 20;
    speed = 25;
    cannonX = 250;
    cannonY = 750;
}

int Player::getX(){
    return cannonX;
}

int Player::getY(){
    return cannonY;
}

void Player::spawn(SDL_Plotter& g){
    //makes rectangle border
    int cannon[20][40] =
        {
        //       5          10         15         20         25         30         35         40
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 2,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,2,2, 2,2,2,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,2, 2,2,2,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},

        {0,0,0,0,0, 0,0,0,0,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {1,1,1,1,1, 1,1,1,1,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {1,1,1,1,1, 1,1,1,1,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {1,1,1,1,1, 1,1,1,1,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,1,1},

        {1,1,1,1,1, 1,1,1,1,1, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,1,1,1,1},
        {1,1,1,1,1, 1,1,1,1,1, 1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,1,1,1,1},
        {1,1,1,1,1, 1,1,1,1,1, 1,1,0,0,0, 0,0,0,0,2, 2,2,0,0,0, 0,0,0,0,0, 0,0,1,1,1, 1,1,1,1,1},
        {1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
        {0,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},

        {0,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,0},
        {0,0,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,0,0},
        {0,0,0,0,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,0,0,0,0},
        {0,0,0,0,0, 0,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 0,0,0,0,0, 0,0,0,0,0}
        };
    Color c = BLUE;
    p.x = cannonX;
    p.y = cannonY;
    bound.setColor(c);
    bound.setUpperLeft(Point(p.x,p.y));
    bound.setLowerRight(Point(p.x + 40,p.y + 20));
    bound.draw(g);
    //draw ship
    for(int r = 0; r < cannonSizeY; r++){
        for(int c = 0; c < cannonSizeX; c++){
            if(cannon[r][c] == 1){
                g.plotPixel(cannonX + c, cannonY + r, 139,69,19);
            }
            else if(cannon[r][c] == 2){
                g.plotPixel(cannonX + c, cannonY + r, 210,180,140);
            }
            else if(cannon[r][c] == 3){
                g.plotPixel(cannonX + c, cannonY + r, 192,192,192);
            }
        }
    }
}



void Player::ship(SDL_Plotter& g, char key){
     //erase ship

     int cannon[20][40] =
        {
        //       5          10         15         20         25         30         35         40
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 2,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,2,2, 2,2,2,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,2, 2,2,2,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},

        {0,0,0,0,0, 0,0,0,0,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {1,1,1,1,1, 1,1,1,1,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {1,1,1,1,1, 1,1,1,1,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {1,1,1,1,1, 1,1,1,1,0, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,0,0,1,1},

        {1,1,1,1,1, 1,1,1,1,1, 0,0,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,0,0, 0,0,0,0,0, 0,1,1,1,1},
        {1,1,1,1,1, 1,1,1,1,1, 1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,1,1,1,1},
        {1,1,1,1,1, 1,1,1,1,1, 1,1,0,0,0, 0,0,0,0,2, 2,2,0,0,0, 0,0,0,0,0, 0,0,1,1,1, 1,1,1,1,1},
        {1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
        {0,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},

        {0,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,0},
        {0,0,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,0,0},
        {0,0,0,0,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,0,0,0,0},
        {0,0,0,0,0, 0,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 0,0,0,0,0, 0,0,0,0,0}
        };
    for(int r = 0; r < cannonSizeY; r++){
        for(int c = 0; c < cannonSizeX; c++){
            if(cannon[r][c]) {
                g.plotPixel(cannonX + c, cannonY + r, 0,0,80);
            }
        }
    }

    //Move the ship
    switch(toupper(key)){
        case RIGHT_ARROW: if(cannonX < 453){
                             cannonX += speed;
                          }
                          break;
        case LEFT_ARROW:  if(cannonX > 12){
                              cannonX -= speed;
                          }
                          break;
        //case UP_ARROW:    speed++;
        //                  break;
        //case DOWN_ARROW:  if(speed > 1) {
        //                      speed--;
        //                  }
        //                  break;
    }
    //makes rectangle border
    Color c = BLUE;
    p.x = cannonX;
    p.y = cannonY;
    bound.setColor(c);
    bound.setUpperLeft(Point(p.x,p.y));
    bound.setLowerRight(Point(p.x + 40,p.y + 20));
    bound.draw(g);
    //draw ship
    for(int r = 0; r < cannonSizeY; r++){
        for(int c = 0; c < cannonSizeX; c++){
            switch(cannon[r][c]){
                case 0: break;
                case 1: g.plotPixel(cannonX + c, cannonY + r, 139,69,19);
                          break;
                case 2: g.plotPixel(cannonX + c, cannonY + r, 210,180,140);
                          break;
                case 3: g.plotPixel(cannonX + c, cannonY + r, 192,192,192);
                          break;
            }
        }
    }
}

Rectangle_t Player::getRect(){
    return bound;
}

