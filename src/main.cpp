#include <memory>
#include <iostream>
#include <iomanip>

#include <Box2D/Box2D.h>

#include <Seidel.hpp>

namespace {
    constexpr int WINDOW_WIDTH = 800;
    constexpr int WINDOW_HEIGHT = 600;
    constexpr float WORLD_WIDTH = 10.0f;
    constexpr float WORLD_HEIGHT = 6.667f;
    constexpr float WIDTH_RATIO = WINDOW_WIDTH / WORLD_WIDTH;
    constexpr float HEIGHT_RATIO = WINDOW_HEIGHT / WORLD_HEIGHT; 
}

struct Size {
    float width;
    float height;
};

struct Position {
    float x;
    float y;
};

struct Color {
    int red;
    int green;
    int blue;
    int alpha;
};

struct Ground {
    Ground(b2World& b2_world, const Size& size, const Position& position, const Color& color) 
            : world(b2_world), size_(size), position_(position), color_(color) {
        // creating a ground body
        b2BodyDef ground_body_def;
        ground_body_def.position.Set(position.x, position.y);
        body = world.CreateBody(&ground_body_def);

        // creating the shape of the ground box
        b2PolygonShape shape;
        shape.SetAsBox(size.width / 2.0f, size.height / 2.0f);

        // create fixture (associate the box shape with the body)
        body->CreateFixture(&shape, 0.0f);
    }
    Size size() {
        return size_;
    }
    Position position() {
        return position_;
    }
    Color color() {
        return color_;
    }
    b2Vec2 b2_position() {
        return body->GetPosition();
    }
private:
    b2World& world;
    b2Body* body;
    Size size_;
    Position position_;
    Color color_;
};

struct Box {
    Box(b2World& b2_world, const Size& size, const Position& position, const Color& color) 
            : world(b2_world), size_(size), color_(color) {
        b2BodyDef body_def;
        body_def.type = b2_dynamicBody;
        body_def.position.Set(position.x, position.y);
        body = world.CreateBody(&body_def);

        b2PolygonShape shape;
        shape.SetAsBox(size.width / 2.0f, size.height / 2.0f);

        b2FixtureDef fixture_def;
        fixture_def.shape = &shape;
        fixture_def.density = 1.0f;
        fixture_def.friction = 0.3f;

        body->CreateFixture(&fixture_def);
    }
    Size size() {
        return size_;
    }
    Position position() {
        b2Vec2 b2_pos = body->GetPosition();
        return Position {b2_pos.x, b2_pos.y};
    }
    Color color() {
        return color_;
    }
private:
    b2World& world;
    b2Body* body;
    Size size_;
    Color color_;
};

SDL_Rect make_sdl_rect(const Size& size, const Position& position) {
    SDL_Rect rect;
    rect.w = size.width * WIDTH_RATIO;
    rect.h = size.height * HEIGHT_RATIO;
    rect.x = static_cast<int>((position.x - size.width / 2) * WIDTH_RATIO);
    rect.y = WINDOW_HEIGHT - static_cast<int>((position.y + size.height / 2) * HEIGHT_RATIO);
    return rect;
}

void draw_ground(Ground& ground, sdl::Window& window) {
    SDL_Rect rect = make_sdl_rect(ground.size(), ground.position());
    std::clog << "Ground rect: @" << rect.x << ", " << rect.y << "  " << rect.w << "x" << rect.h << '\n';
    const Color& color = ground.color();
    SDL_SetRenderDrawColor(window.renderer(), color.red, color.green, color.blue, color.alpha);
    SDL_RenderFillRect(window.renderer(), &rect);
    SDL_RenderPresent(window.renderer());
}

void draw_box(Box& box, sdl::Window& window) {
    SDL_Rect rect = make_sdl_rect(box.size(), box.position());
    std::clog << "Box rect: @" << rect.x << ", " << rect.y << "  " << rect.w << "x" << rect.h << '\n';
    const Color& color = box.color();
    SDL_SetRenderDrawColor(window.renderer(), color.red, color.green, color.blue, color.alpha);
    SDL_RenderFillRect(window.renderer(), &rect);
    SDL_RenderPresent(window.renderer());
}

int main() {
    sdl::SDL sdl(SDL_INIT_VIDEO);
    sdl::Window window("Bars v1.0", WINDOW_WIDTH, WINDOW_HEIGHT);

    // creating a world
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);

    Ground ground(world, Size {10.0f, .3f}, Position {5.0f, .15f}, Color {0, 255, 0, 255});
    Box box_1(world, Size {.2f, .2f}, Position {5.0f, 5.0f}, Color {255, 255, 255, 255});

    float time_step = 1.0f / 60.0f;
    int32 velocity_iterations = 6;
    int32 position_iterations = 2;
    for (int i = 0; i < 250; ++i) {
        window.clear();
        draw_ground(ground, window);
        draw_box(box_1, window);

        world.Step(time_step, velocity_iterations, position_iterations);
        //b2Vec2 position = box.position();
        //float32 angle = ground_body->GetAngle();
        //std::cout << std::setprecision(4) << std::setw(10) << position.x << ", " << std::setprecision(4) << position.y << '\n';

        SDL_Delay(10);
    }
}
