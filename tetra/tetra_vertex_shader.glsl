#version 450 core

in vec4 position;
in vec4 color;
out vec4 vsColor;

void main()
{
    vsColor = color;
    gl_Position = position;
}
