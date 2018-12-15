#ifndef _ABSTRACT_STATIC_H_
#define _ABSTRACT_STATIC_H_

class AbstractStatic {
  public:

  float positionX;
  float positionY;

  uint8_t height;
  uint8_t width;

  AbstractStatic(float positionX, float positionY, uint8_t width, uint8_t height)
  {
    this->positionX = positionX;
    this->positionY = positionY;
    this->width = width;
    this->height = height;
  }

  virtual void onInteract();
};

#endif
