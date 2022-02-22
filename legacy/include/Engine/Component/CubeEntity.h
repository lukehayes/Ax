#ifndef AX_TEST_ENTITY_H
#define AX_TEST_ENTITY_H

#include "Ax/Engine/Component/Transform.h"
#include "Ax/Engine/Component/Entity.h"

namespace Ax::Engine::Component {

    using namespace Ax::Engine::Component;
    class CubeEntity : public Entity
    {
        public:
            CubeEntity() 
            {
                this->transform.position = {0,0,-10.0};
            }

            CubeEntity(const V3& position) 
            {
                this->transform.position = position;
            }

            ~CubeEntity() {}

            void update(double dt)
            {
                static float c = 0.0;
                c += 0.0001;
                transform.position.z = speed * std::sin(c) * 100;
            }

            //Transform getTransform()
            //{
                //return this->transform;
            //}

            //V3 getColor()
            //{
                //return this->color;
            //}

            //int getVerticies()
            //{
                //return this->verticies;
            //}

            //GLenum getPrimitive()
            //{
                //return this->primitive;
            //}

            Transform    transform;
            V3           color = {1,0,1};
            int verticies = 36;
            GLenum primitive = GL_TRIANGLES;

    };
}


#endif // AX_ENTITY_H
