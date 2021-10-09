#ifndef AX_COMPONENT_H
#define AX_COMPONENT_H

namespace Ax::System::Component {

    /**
     * The base component class for all to be Components.
     */
    class Component
    {
        public:
            Component() {}
            ~Component() {}

            virtual void update() = 0;
    };
}


#endif // AX_COMPONENT_H
