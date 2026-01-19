#include "../platform/Platform.hpp"
#pragma once

namespace Engine
{
    
    struct WindowSpec{
        const char* title;
        int width;
        int height;
    };

    constexpr const WindowSpec DefaultWinSpec={"Engine", 1600, 900}; 

    class Application
    {
        public:
        Application();
        ~Application();

        void start(const WindowSpec WinSpec);
        void stop();

        private:

        void setUp(const WindowSpec WinSpec);
        void tick();
        void cleanUp();

        bool isRunning = true;

        PlatformInstance* m_PlatformInstance = nullptr;
        WindowInstance* m_WindowInstance = nullptr;

    };

};