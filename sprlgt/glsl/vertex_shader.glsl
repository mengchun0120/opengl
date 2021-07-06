#version 450 core

uniform mat4 modelViewMatrix;
uniform mat4 projMatrix;
in vec3 inPos;
in vec3 inNormal;
out vec3 normal;
out vec3 pos;

void main()
{
    gl_Position = projMatrix * modelViewMatrix * vec4(inPos, 1.0);
    normal = inNormal;
    pos = inPos;
}
