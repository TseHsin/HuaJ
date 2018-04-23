#version 450 core
layout (location = 0) in vec3 position;
uniform mat4 mvp;
uniform vec3 offset;

void main() {
    gl_Position = mvp * vec4(position, 1.0);
}