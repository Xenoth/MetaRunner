#include <malloc.h>
#include "AbstractScene.h"

void AbstractScene::init(uint8_t numberStaticObjects, uint8_t numberDynamicObjects)
{
    this->numberDynamicObjects = numberDynamicObjects;
    this->numberStaticObjects = numberStaticObjects;

    this->dynamicObjects = new AbstractDynamic*[numberDynamicObjects];
    this->staticsObject = new AbstractStatic*[numberStaticObjects];
}
