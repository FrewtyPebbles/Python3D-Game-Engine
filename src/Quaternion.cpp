#include "Quaternion.h"
#include "Vec3.h"
#define _USE_MATH_DEFINES
#include <math.h>

quaternion quaternion::from_axis_angle(vec3 axis, float angle) {
    return glm::angleAxis(angle, axis.get_normalized().axis);
}  
 
void quaternion::rotate(vec3 axis, float angle) {
    quat *= glm::angleAxis(angle, axis.axis);
}

vec3 quaternion::to_euler() {
    return glm::eulerAngles(quat);
}

quaternion quaternion::from_euler(const vec3& euler_vec) {
    return quaternion(euler_vec.axis);
}

vec3 quaternion::operator*(vec3 const& other)
{
    return vec3(quat*other.axis);
}

vec3 quaternion::cross(vec3 const& other)
{
    return glm::cross(other.axis, quat);
}

vec3 quaternion::get_up() {
    glm::mat4 rotMatrix = glm::toMat4(quat);
    return glm::vec3(rotMatrix[0][1], rotMatrix[1][1], rotMatrix[2][1]);
}

vec3 quaternion::get_right() {
    glm::mat4 rotMatrix = glm::toMat4(quat);
    return glm::vec3(rotMatrix[0][0], rotMatrix[1][0], rotMatrix[2][0]);;
}

vec3 quaternion::get_forward() {
    glm::mat4 rotMatrix = glm::toMat4(quat);
    return glm::vec3(rotMatrix[0][2], rotMatrix[1][2], rotMatrix[2][2]);
}