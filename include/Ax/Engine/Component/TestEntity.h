#ifndef AX_TEST_ENTITY_H
#define AX_TEST_ENTITY_H

#include "Ax/Engine/Component/Transform.h"

namespace Ax::Engine::Component {

    class TestEntity
    {
    public:
                    TestEntity() {}
                    ~TestEntity() {}

        void update(double dt)
        {
            //transform.position.x = 790;
            //transform.position.y = 590;
            //transform.position.z = -5.0;
        }

        Transform    transform;
        V3           color = {0,0,0};
    };
}


#endif // AX_ENTITY_H
