#include <iostream>
#include <sphere_app.h>

int main(int argc, char* argv[])
{
    using namespace sphere;
    using namespace std;

    if (argc != 4)
    {
        cerr << "Usage: " << argv[0]
             << " vertexShaderFile fragShaderFile configFile"
             << endl;
        return 1;
    }

    string vertexShaderFile(argv[1]);
    string fragShaderFile(argv[2]);
    string configFile(argv[3]);

    try
    {
        SphereApp::initInstance(vertexShaderFile, fragShaderFile, configFile);
        SphereApp::getInstance()->run();
    }
    catch (const exception& e)
    {
        cerr << "Exception happened: " << e.what() << endl;
    }
}

