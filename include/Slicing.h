#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>

#include "Method.h"

using namespace std;

class Slicing : public Method {
    using super = Method;

private:
	int _index;
    vector<vector<GLfloat>> _vertex;
	vector<float> _texture_1d, _texture_3d;
	vector<vector<float>> _template;

	void generate_texture_1d();
	void generate_texture_3d();
	void push(glm::vec3 data, int index);
	void calculate();

public:
	Slicing();
	Slicing(string inf_file, string raw_file);
	~Slicing();

	void run(glm::vec3 view_position);
	vector<float>& texture_1d();
	vector<float>& texture_3d();
	glm::ivec3 texture_1d_shape();
	glm::ivec3 texture_3d_shape();

	vector<GLfloat>& vertex() override;
	vector<int> attribute() override;
	GLenum render_mode() override;
};