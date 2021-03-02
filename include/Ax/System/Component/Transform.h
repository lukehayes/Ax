#ifndef AX_COMPONENT_TRANSFORM_H
#define AX_COMPONENT_TRANSFORM_H

#include "Ax/System/Common/Types.h"

namespace Ax::System::Component {

    class Transform
    {
        public:
               Transform():
                   m_position(0.0f, 0.0f, 0.0f),
                   m_rotation(0.0f, 0.0f, 0.0f),
                   m_scale(10.0f, 10.0f, 10.0f)
               {}

               Transform(const V3& position):
                   m_position(position),
                   m_rotation(0.0f, 0.0f, 0.0f),
                   m_scale(10.0f, 10.0f, 10.0f)
               {}

               ~Transform(){}

            V3& position();
            V3& rotation() ;
            V3& scale();

        private:
            V3 m_position;
            V3 m_rotation;
            V3 m_scale;
    };
}

inline V3&
Ax::System::Component::Transform::position() { return this->m_position; }

inline V3&
Ax::System::Component::Transform::rotation() { return this->m_rotation; }

inline V3&
Ax::System::Component::Transform::scale() { return this->m_scale; }

#endif
