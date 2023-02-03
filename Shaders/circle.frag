#version 460 core

// Outputs colors in RGBA
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec3 color;
// Inputs the texture coordinates from the Vertex Shader
in vec2 texCoord;

in vec4 position;

// Gets the Texture Unit from the main function
uniform sampler2D tex0;

float circleShape(float radius)
{
	float value = distance(vec2(position.x, position.y), vec2(0.0));
	return step(radius, value);
}

void main()
{
	float aRadius = 0.5;
	float threshold = 0.1;
	float dist = distance(position.xy, vec2(0.0));
    if (dist > aRadius)
        discard;
	vec3 aColor = vec3(1.0,0.0,0.0);
    float d = dist / aRadius;
    // vec3 color = mix(color.rgb, vec3(0.0), step(1.0-threshold, d));

    FragColor = vec4(aColor, 1.0);
}