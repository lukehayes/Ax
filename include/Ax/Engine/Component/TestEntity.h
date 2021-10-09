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
            std::cout << "Delta " << dt << std::endl;
        }

        Transform    transform;
        V3           color = {1,0,0};
    };
}


#endif // AX_ENTITY_H
