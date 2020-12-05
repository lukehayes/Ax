#ifndef GFX_SHADER_H
#define GFX_SHADER_H

#include "engine.h"
#include "common/types.h"
#include "util/log.h"

GLuint vertex_shader, fragment_shader;
int success;
char infoLog[512];

typedef struct Shader
{
    // Properties
    const_str vsh_path;
    const_str fsh_path;
    GLuint program;
    
    // Function pointers;
    void (*init)();
} Shader;



void CG_CreateShader(Shader* shader, const_str vsh_source, const_str fsh_source)
{
    shader->vsh_path = vsh_source;
    shader->fsh_path = fsh_source;

    L("Source");
    L(vsh_source);
    L(fsh_source);

    // Vertex Shader Compilation
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &shader->vsh_path, NULL);
	glCompileShader(vertex_shader);

	// print compile errors if any
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		LE("Vertex Shader Compilation Failed", infoLog);
	};

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fsh_source, NULL);
	glCompileShader(fragment_shader);

	// print compile errors if any
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		LE("Fragment Shader Compilation Failed", infoLog);
	};

	shader->program = glCreateProgram();

	glAttachShader(shader->program, vertex_shader);
	glAttachShader(shader->program, fragment_shader);
	glLinkProgram(shader->program);

	glGetShaderiv(shader->program, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		printf("Linking Shader Failed. %s \n", infoLog);
	};

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	L("Shaders Loaded. All fine.");
}


//void
//CG_CreateBuffer(Buffer* buffer);

//void
//CG_DestroyBuffer(Buffer* buffer);

#endif
