#pragma once

namespace Engine
{

    class WindowInstance
    {

        //!!FLOWS??
        //* a object design.
        //* This WindowInstance has no stop function because WindowInstance doesn't decide when to stop 
        //  the one that decide is higher order inheritance (PlatformInstance, Application)
        //* Handle Window creation and management

        public:

        //SECTION: destruct
        virtual ~WindowInstance() = default;

        //SECTION: window func
        virtual void cleanUpWindow() = 0;
        virtual void showWindow() = 0;
        virtual void getSize(int &width, int &height) = 0;

    };

    class PlatformInstance
    {

        //!!FLOWS??
        //* struct and start design.
        //* This PlatformInstance has no stop function because PlatformInstance doesn't decide when to stop 
        //  the one that decide is higher order inheritance (Application)
        //* Handle WindowInstances and other OS driver

        public:

        //SECTION: Initialization
        virtual ~PlatformInstance() = default;
        virtual void start() = 0;

        //SECTION: WindowInstance creation
        //!!DESC??
        virtual WindowInstance* createWindowInstance(const char * title, int width, int height) = 0;

        //SECTION: Platform methods
        virtual void pollEvent() = 0;
        virtual bool shouldClose() const = 0;

    };

    PlatformInstance* createPlatformInstance();

};
