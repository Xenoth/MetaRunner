#ifndef RUNNER_GAMEBUINO_SCENE_H
#define RUNNER_GAMEBUINO_SCENE_H

#include "AbstractStatic.h"
#include "AbstractDynamic.h"

class AbstractScene
{
public:
    uint8_t numberDynamicObjects;
    uint8_t numberStaticObjects;

    AbstractStatic **staticsObject;
    AbstractDynamic **dynamicObjects;

    void init(uint8_t numberStaticObjects, uint8_t numberDynamicObjects);

    virtual ~AbstractScene() = 0;
};

AbstractScene::~AbstractScene() = default {}

#endif
