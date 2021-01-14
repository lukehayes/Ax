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
                   m_scale(10.0f, 10.0f, 10.0f),
               {}

               ~Transform(){}

        private:
            V3 m_position;
            V3 m_rotation;
            V3 m_scale;
    };
}

inline V3
Core::Transorm::position() { return this->m_position; }

inline V3
Core::Transorm::rotation() { return this->m_rotation; }

inline V3
Core::Transorm::scale() { return this->m_scale; }

#endif
