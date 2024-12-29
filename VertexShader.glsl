#version 330 core
<<<<<<< HEAD
layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
=======

layout(Location=0) in vec3 position;

main() {
	gl_Position = vec4(position, 1.0);
}
>>>>>>> 40386bebb0a9c6de959c7ec61e5a1a2fba0a9ab9
