//
// Created by cezar on 23.11.2021.
//

#ifndef GKLAB_SHAPOBJECT_H
#define GKLAB_SHAPOBJECT_H
#include <SFML/Graphics.hpp>
#include "TransformableObject.h"
#include "DrawableObject.h"
#include "PrimitiveRenderer.h"
class ShapObject : public DrawableObject , public TransformableObject{
protected:
    PrimitiveRenderer render;
public:
    PrimitiveRenderer* getRenderer();
};
#endif //GKLAB_SHAPOBJECT_H
