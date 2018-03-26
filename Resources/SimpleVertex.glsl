uniform mat4 Projection;
uniform mat4 Model;
uniform mat4 View;

uniform vec4 Color;

attribute vec4 Position;

varying vec4 DestinationColor;

void main(void) {
	DestinationColor = Color;
	gl_Position = Projection * View * (Model * Position);
}
