#include "./Application.hpp"
#include "../platform/Platform.hpp"

namespace Engine
{

    Application::Application(){};
    Application::~Application()
    {
        cleanUp();
    };

    void Application::start(const WindowSpec WinSpec)
    {
        setUp(WinSpec);

        while (isRunning)
        {
            tick();
        }

    }

    void Application::tick()
    {
        m_PlatformInstance->pollEvent();

        if(m_PlatformInstance->shouldClose())
        {
            isRunning = false;
        }

    };

    void Application::stop()
    {
        isRunning = false;
    };

    void Application::setUp(const WindowSpec WinSpec)
    {
        m_PlatformInstance = createPlatformInstance();
        if(!m_PlatformInstance)//In case of fail to create a platform
        {
            isRunning = false;
            return;
        }

        m_PlatformInstance->start();

        m_WindowInstance = m_PlatformInstance->createWindowInstance(WinSpec.title, WinSpec.width, WinSpec.height);
        m_WindowInstance->showWindow();

    };

    void Application::cleanUp()
    {

        if(m_PlatformInstance)
        {
            delete m_PlatformInstance; //So if platform was delete the Window and other resource will chainly shutdown too, so no need to delete all elements
            m_PlatformInstance = nullptr;
        }
    }

};