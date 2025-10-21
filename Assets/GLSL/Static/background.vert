#version 460 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 InstPos;

uniform mat4 gVP;

void main() {

	gl_Position = gVP * (vec4(aPos, 1.f) + vec4(InstPos, 0.f));

}