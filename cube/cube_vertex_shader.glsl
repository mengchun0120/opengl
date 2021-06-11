#version 450 core

in vec4 position;
in vec4 color;
out vec4 vsColor;
uniform mat4 rotateMatrixX, rotateMatrixY, rotateMatrixZ;

void main()
{
    vsColor = color;
    gl_Position = rotateMatrixX * rotateMatrixY * rotateMatrixZ * position;
}
