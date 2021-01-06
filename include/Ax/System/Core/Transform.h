#ifndef AX_SYS_CORE_TRANSFORM_H
#define AX_SYS_CORE_TRANSFORM_H

#include "Ax/System/Common/Types.h"

namespace Core
{

    class Transform
    {
        public:
            Transform(){}
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
