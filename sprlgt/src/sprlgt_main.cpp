#include <iostream>
#include <sprlgt_app_config.h>
#include <sprlgt_sphere_lighting_app.h>

int main(int argc, char* argv[])
{
    using namespace sprlgt;
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
        AppConfig cfg(configFile);
        SphereLightingApp app(vertexShaderFile, fragShaderFile, cfg);
        app.run();
    }
    catch (const exception& e)
    {
        cerr << "Exception happened: " << e.what() << endl;
    }
}

