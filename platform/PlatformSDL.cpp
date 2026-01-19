#include "./Platform.hpp"
#include "../dependencies/include/SDL3/SDL.h"

namespace Engine
{

    //SECTION: WindowInstance (SDL: Implementation) 
    class WindowInstance_SDL : public WindowInstance
    {
        public:
        
        WindowInstance_SDL(const char * title, int width, int height){
            m_WindowSDL = SDL_CreateWindow(title, width, height, SDL_WINDOW_OPENGL);
        };

        ~WindowInstance_SDL() override
        {
            cleanUpWindow();
        };

        void showWindow() override
        {
            SDL_ShowWindow(m_WindowSDL);
        };

        void getSize(int &width, int &height) override
        {
            SDL_GetWindowSize(m_WindowSDL, &width, &height);
        }; 

        void cleanUpWindow() override
        {
            SDL_DestroyWindow(m_WindowSDL);
            m_WindowSDL = nullptr;
        };

        private:

        SDL_Window* m_WindowSDL = nullptr;

    };

    //SECTION: PlatformInstance (SDL: Implementation)
    class PlatformInstance_SDL : public PlatformInstance
    {

        public:

        PlatformInstance_SDL(){};
        ~PlatformInstance_SDL() override
        {
            delete m_WindowInstance;
            m_WindowInstance = nullptr;
        };

        void start() override
        {   

            //!!DESC??
            //* init SDL3 video 

            if(!SDL_Init(SDL_INIT_VIDEO))
            {
                //LOGS HERE (if fail)
            }

        };

        //SECTION: platform methods
        void pollEvent() override
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if(event.type == SDL_EVENT_QUIT)
                {
                    m_flagShouldClose = true;
                };
            };

        };

        bool shouldClose() const override
        {
            return m_flagShouldClose;
        };

        //SECTION: WindowInstance Interface creation
        WindowInstance* createWindowInstance(const char * title, int width, int height) override
        {
            m_WindowInstance = new WindowInstance_SDL(title, width, height);
            return m_WindowInstance;
        };


        //SECTION: platform private
        //!!DESC??
        //* contains a WindowInstance and a platform states.
        private:

        WindowInstance* m_WindowInstance = nullptr;

        bool m_flagShouldClose = false;

    };

    //SECTION: platform constructor
    PlatformInstance* createPlatformInstance()
    {
        return new PlatformInstance_SDL();
    };

};