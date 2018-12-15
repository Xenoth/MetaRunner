#ifndef _GAME_CONTROLLER_H_
#define _GAME_CONTROLLER_H_

#include <Gamebuino-Meta.h>
#include "Obstacle.h"
#include "Physics.h"
#include "Player.h"
#include "UserController.h"

class GameController {
  
  private:
    UserController* userController;
    Player *player;

    const int floorHeight = 60;
    
    uint8_t tileSize = 8;

    const int playerPositionXSpawn = 5;
    const int playerPositionYSpawn = floorHeight - (2 * tileSize);

    const int obstaclesSize = 3;
    Obstacle *obstacles[3];

    float speed = 1.6;
    unsigned long score;

    float gravityPlusYAcceleration = 0.8;

    float difficulty = 80;
    float separationBetweenObstacles;
    float randomObstacleDistance = 20;
    

  public:
    GameController()
    {
      initUserController();
    }

    void initUserController() {
      userController = new UserController(this);
    }
  
    void begin()
    {
      speed = 1.6;
      score = 0;
      player = new Player(Player::STATE_RUNNING, playerPositionXSpawn, playerPositionYSpawn, tileSize, tileSize * 2);
      separationBetweenObstacles = difficulty * log(speed);

      populateObstacles();
    }
  
    void loop()
    {
      userController->loop();
      updatePlayer();
      updateObstacles();

      checkCollisions();

      drawGame();
      
      
    }

    Obstacle* generateObstacle()
    {
      float mostFarObstaclePositionX = 0;
      for(int i = 0; i < obstaclesSize; i++)
      {
        if(obstacles[i]->positionX > mostFarObstaclePositionX)
          mostFarObstaclePositionX = obstacles[i]->positionX;
      }

      
      bool typeObstacle = (random(randomObstacleDistance) < randomObstacleDistance/2);

      float positionY;
      float positionX;
      
      (typeObstacle ? positionY = floorHeight - tileSize : positionY = floorHeight - tileSize * 2 - 1);
      positionX = Obstacle::generateNextPositionXObstacle(mostFarObstaclePositionX, separationBetweenObstacles);

      Obstacle *obstacle = new Obstacle(positionX, positionY, tileSize, tileSize);
    
      return obstacle;
    }
    
    void populateObstacles()
    {
      obstacles[0] = new Obstacle(100, floorHeight - tileSize, tileSize, tileSize);
      obstacles[1] = new Obstacle(160, floorHeight - tileSize, tileSize, tileSize);
      obstacles[2] = new Obstacle(220, floorHeight - tileSize, tileSize, tileSize);
    }

    void updateObstacles()
    {
      for(int i = 0; i < obstaclesSize; i++)
      {
          if(obstacles[i]->positionX < 0 - obstacles[i]->width)
          {
            Obstacle *current = generateObstacle();
            obstacles[i] = current;
          }
    
          obstacles[i]->positionX -= speed;
      }
    }

    void onButtonUpRepeat()
    {
      player->jump();
    }
    
    void onButtonDownRepeat()
    {
      player->crouch();
    }
    
    void onButtonDownReleased()
    {
      player->run();
    }

    void updatePlayer()
    {
      if(player->state == Player::STATE_JUMPING || player->state == Player::STATE_FALLING)
      {
        Physics::applyForce(player , 0, gravityPlusYAcceleration);
        Physics::moveObject(player);
        
        if(player->velocityY < 0)
        {
          player->state = Player::STATE_FALLING;
        }
        
        if(player->positionY > floorHeight - player->height)
        {
          player->positionY = floorHeight - player->height;
          player->state = Player::STATE_RUNNING;
          gb.sound.playCancel();
        }
      }
    }

    void checkCollisions()
    {
      for(int i = 0; i < obstaclesSize; i++)
      {
        if(Physics::collides(*player, *obstacles[i]))
          speed = 0;
      }
    }

    void drawGame()
    {
      gb.display.clear();
      drawObstacles();      
      gb.display.setColor(WHITE);
      gb.display.print("Score=");
      gb.display.print(score);
      gb.display.drawRect(0, floorHeight, gb.display.width(), gb.display.height() - floorHeight);
      
      gb.display.setColor(ORANGE);
      gb.display.fillRect(player->positionX, player->positionY, player->width, player->height);
    }

    void drawObstacles()
    {
        gb.display.setColor(RED);
        for(int i = 0; i < obstaclesSize; i++)
        {
          if(obstacles[i]->positionX > gb.display.width())
            continue;
         
          gb.display.fillRect(obstacles[i]->positionX, obstacles[i]->positionY, obstacles[i]->width, obstacles[i]->height);
        }
    }

  
};

#endif
