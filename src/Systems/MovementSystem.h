#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

class MovementSystem: public System {
    public:
        MovementSystem() {
            // TODO
            // RequireComponent<TransformComponent>();
            // RequireComponent<...>();
        }

        void update() {
            // TODO
            // Loop all entities that the system is interested in
            for (auto entity: GetEntities()){
                // Update entity position based on its velocity
            }
        }
};


#endif