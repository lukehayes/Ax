#ifndef AX_ENTITY_H
#define AX_ENTITY_H

#include "Ax/Common/Types.h"

namespace Ax::Entity
{
    class Entity
    {
        public:
            Entity() {}
            Entity(const glm::vec3& pos) : position(pos) {}
            ~Entity() {}

            glm::vec3 position = {0,0,0};
            glm::vec3 color = {0,1,0};
    };
};


#endif // AX_ENTITY_H
