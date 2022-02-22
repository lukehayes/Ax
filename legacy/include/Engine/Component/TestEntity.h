#ifndef AX_TEST_ENTITY_H
#define AX_TEST_ENTITY_H

#include "Ax/Engine/Component/Transform.h"
#include "Ax/Engine/Component/Entity.h"

namespace Ax::Engine::Component {

    using namespace Ax::Engine::Component;

    class TestEntity : public Entity
    {
        public:
            TestEntity() 
            {
                this->transform.position = {0,0,-10.0};
            }

            TestEntity(const V3& position) 
            {
                this->transform.position = position;
            }

            ~TestEntity() {}

            void update(double dt)
            {
                //static float c = 0.0;
                //c += 0.0001;
            }

            Transform getTransform()
            {
                return this->transform;
            }
            virtual V3 getColor()
            {
                return this->color;
            }

            virtual int getVerticies()
            {
                return this->verticies;
            }

            virtual GLenum getPrimitive()
            {
                return this->primitive;
            }

            Transform    transform;
            V3           color = {1,0,1};
            int verticies = 4;
            GLenum primitive = GL_TRIANGLE_STRIP;

    };
}


#endif // AX_ENTITY_H
