#ifndef AX_ENTITY_H
#define AX_ENTITY_H

#include "Ax/Component/Transform.h"

namespace Ax::Entity
{
class Entity
{
public:

    Entity() : transform() {}

    Entity(const glm::vec3& pos) :
        transform(pos) {}

    Entity(const glm::vec3& pos, const glm::vec3& color) : 
        transform(pos),
        color(color) {}

    ~Entity() {}

    Ax::Component::Transform transform; 

    glm::vec3 color = {0.0, 1.0, 1.0};
};
};


#endif // AX_ENTITY_H
