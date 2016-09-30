#include <memory>
#include <iostream>
#include <iomanip>

#include <Box2D/Box2D.h>

#include <Seidel.hpp>

struct box {
    box(b2World& b2_world) : b2_world(b2_world) {
        b2BodyDef body_def;
        body_def.type = b2_dynamicBody;
        body_def.position.Set(0.0f, 10.0f);
        body = b2_world.CreateBody(&body_def);

        b2PolygonShape box_shape;
        box_shape.SetAsBox(2.0f, 2.0f);

        b2FixtureDef fixture_def;
        fixture_def.shape = &box_shape;
        fixture_def.density = 1.0f;
        fixture_def.friction = 0.3f;

        body->CreateFixture(&fixture_def);
    }
    b2Body* get_body() {
        return body;
    }
private:
    b2World& b2_world;
    b2Body* body;
};

int main() {

    sdl::SDL sdl(SDL_INIT_VIDEO);

    // creating a world
    b2Vec2 gravity(1.0f, -10.0f);
    b2World world(gravity);

    // creating a ground body
    b2BodyDef ground_body_def;
    ground_body_def.position.Set(0.0f, -20.0f);
    b2Body* ground_body = world.CreateBody(&ground_body_def);

    // creating a ground box
    b2PolygonShape ground_box;
    ground_box.SetAsBox(50.0f, 10.0f);

    // create fixture (associate the box shape with the body)
    ground_body->CreateFixture(&ground_box, 0.0f);

    box b(world);

    float time_step = 1.0f / 60.0f;
    int32 velocity_iterations = 6;
    int32 position_iterations = 2;
    for (int i = 0; i < 80; ++i) {
        world.Step(time_step, velocity_iterations, position_iterations);
        b2Vec2 position = b.get_body()->GetPosition();
        //float32 angle = ground_body->GetAngle();
        std::cout << std::setprecision(4) << std::setw(10) << position.x << ", " << std::setprecision(4) << position.y << '\n';
    }
}
