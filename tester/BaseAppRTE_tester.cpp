#include "../core/Application.hpp"

int main(int argc, char** argv)
{
    Engine::Application app;

    Engine::WindowSpec winSpec;
    winSpec.title  = "Engine Runtime Test";
    winSpec.width  = 1280;
    winSpec.height = 720;

    app.start(winSpec);

    return 0;
}