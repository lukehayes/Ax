#ifndef AX_ENTITY_H
#define AX_ENTITY_H

#include "Ax/System/Component/Transform.h"

namespace Ax::System::Entity {

    /**
     * The base component class for all to be Entities.
     */
    class Entity
    {
    public:
                    Entity() {}
                    ~Entity() {}

        virtual void update() = 0;

        Transform    transform;
    };
}


#endif // AX_ENTITY_H
