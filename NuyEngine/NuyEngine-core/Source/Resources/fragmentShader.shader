#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 in_color;
uniform vec2 in_light_pos;

in DATA
{
	vec4 position;
	vec4 color;
} fs_in;

void main()
{
	float intensity = 1.0 / length(fs_in.position.xy - in_light_pos);
	// color = in_color * intensity;
	color = fs_in.color * intensity;
}