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
                static float c = 0.0;
                c += 0.0001;
                transform.position.x = std::cos(c) * 10.0f;
                transform.position.y = std::sin(c) * 10.0f;
                transform.position.z = -100.0f + std::cos(c) * 10.0f;
            }

            Transform    transform;
            V3           color = {0,0,0};
    };
}


#endif // AX_ENTITY_H
