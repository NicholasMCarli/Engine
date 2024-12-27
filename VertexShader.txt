#version 330 core

layout(Location=0) in vec3 position;

main() {
	gl_Position = vec4(position, 1.0);
}