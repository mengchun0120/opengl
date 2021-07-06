#version 450 core

uniform vec3 ambientProduct, diffuseProduct, specularProduct;
uniform vec3 lightPos, eyePos;
uniform float shineness;
in vec3 normal;
in vec3 pos;
out vec4 color;

void main()
{
    vec3 ambient, diffuse, specular;

    ambient = ambientProduct;

    vec3 lightVec = normalize(lightPos - pos);
    float diffuseFactor = max(dot(normal, lightVec), 0.0);
    diffuse = diffuseFactor * diffuseProduct;

    vec3 eyeVec = normalize(eyePos - pos);
    vec3 halfVec = normalize(lightVec + eyeVec);
    float nh = dot(normal, halfVec);

    if (nh <= 0.0)
    {
        specular = vec3(0.0, 0.0, 0.0);
    }
    else
    {
        specular = pow(nh, shineness) * specularProduct;
    }

    color = vec4(ambient + diffuse + specular, 1.0);
}

