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
            Entity(const glm::vec3& pos, const glm::vec3& color)
                : position(pos),
                  color(color)
            {}
            ~Entity() {}

            glm::vec3 position = {0,0,0};
            glm::vec3 color = {0.2,0.2,0.2};
            double scale = 2.0f;
    };
};


#endif // AX_ENTITY_H
