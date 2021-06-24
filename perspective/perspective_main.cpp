#include <iostream>
#include <perspective_app.h>

int main(int argc, char *argv[])
{
    using namespace perspective;

    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " vertexShaderFile "
                  << "fragShaderFile" << std::endl;
        return 1;
    }

    std::string vertexShaderFile(argv[1]);
    std::string fragShaderFile(argv[2]);

    try
    {
        PerspectiveApp::initInstance(vertexShaderFile, fragShaderFile);
        PerspectiveApp::getInstance()->run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception happened: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
