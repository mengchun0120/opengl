#version 450 core

in vec4 position;
in vec4 color;
out vec4 vsColor;
uniform mat4 modelMatrix, projMatrix;

void main()
{
    vsColor = color;
    gl_Position = projMatrix * modelMatrix * position;
}
