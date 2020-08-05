//
// Created by menegais1 on 12/07/2020.
//

#include "Transform.h"

Transform::Transform(const fvec3 &position, const fvec3 &rotation, const fvec3 &scale) : position(position),
                                                                                         rotation(rotation),
                                                                                         scale(scale) {}

Transform::Transform() {

}
