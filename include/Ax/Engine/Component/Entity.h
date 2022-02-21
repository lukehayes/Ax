#ifndef AX_ENTITY_H
#define AX_ENTITY_H

#include "Ax/Engine/Component/Transform.h"

namespace Ax::Engine::Component {

    /**
     * The base component class for all to be Entities.
     */
    class Entity
    {
    public:
                    Entity() {}
                    ~Entity() {}

        virtual void update(double dt) = 0;

        virtual Transform getTransform() = 0;
        virtual V3 getColor() = 0;
        virtual int getVerticies() = 0;
        virtual GLenum getPrimitive() = 0;

        Transform    transform;
    };
}


#endif // AX_ENTITY_H
