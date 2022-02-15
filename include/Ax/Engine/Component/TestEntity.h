#ifndef AX_TEST_ENTITY_H
#define AX_TEST_ENTITY_H

#include "Ax/Engine/Component/Transform.h"

namespace Ax::Engine::Component {

    class TestEntity
    {
        public:
            TestEntity() 
            {
                this->transform.position = {0,0,0};
            }

            TestEntity(const V3& position) 
            {
                this->transform.position = position;
            }

            ~TestEntity() {}

            void update(double dt)
            {
                static float c = 0.0;
                c += 0.001;
            }

            Transform    transform;
            V3           color = {1,0,1};
    };
}


#endif // AX_ENTITY_H
