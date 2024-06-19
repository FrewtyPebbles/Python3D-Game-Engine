#include "Quaternion.h"
#include "Vec3.h"

quaternion quaternion::from_axis_angle(vec3 axis, float angle) {
    return quaternion(glm::angleAxis(angle, axis.axis));
}  

void quaternion::rotate(vec3 axis, float angle) {
    quat *= glm::angleAxis(angle, axis.axis);
}

vec3 quaternion::to_euler() {
    return vec3(glm::eulerAngles(this->quat));
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
    return vec3(glm::cross(other.axis, quat));
}