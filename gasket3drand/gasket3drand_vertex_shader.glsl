#version 450 core

in vec4 position;
out vec4 color;

void main()
{
    color = vec4((1.0 + position.xyz) / 2.0, 1.0);
    gl_Position = position;
}
