#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>

#include "Volume.h"

using namespace std;

class Method {
protected:
    Volume volume;

public:
    Method();
    Method(string inf_file, string raw_file);
    virtual ~Method();

    glm::vec3 volume_shape();

    virtual vector<GLfloat>& vertex() = 0;
    virtual vector<int> attribute() = 0;
    virtual GLenum render_mode() = 0;
};