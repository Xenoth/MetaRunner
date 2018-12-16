#ifndef _ABSTRACT_DYNAMIC_H_
#define _ABSTRACT_DYNAMIC_H_

class AbstractDynamic {
  public:

  float positionX;
  float positionY;

  uint8_t height;
  uint8_t width;

  float velocityX;
  float velocityY;

  virtual void onInteract(AbstractDynamic);

  AbstractDynamic(float positionX, float positionY, uint8_t width, uint8_t height) : AbstractDynamic(positionX, positionY, width, height, 0.0, 0.0)
  {  }

  AbstractDynamic(float positionX, float positionY, uint8_t width, uint8_t height, float velocityX, float velocityY)
  {
    this->positionX = positionX;
    this->positionY = positionY;
    this->height = height;
    this->width = width;
    this->velocityX = velocityX;
    this->velocityY = velocityY;
  }
};

#endif

