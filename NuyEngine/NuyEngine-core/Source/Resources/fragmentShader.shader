#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 in_color;
uniform vec2 in_light_pos;

in vec4 pos;

void main()
{
	float intensity = 1.0 / length(pos.xy - in_light_pos);
	color = in_color * intensity;
}