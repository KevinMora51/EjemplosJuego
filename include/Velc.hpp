#pragma once

class Velc {
    float dx, dy;
public:
    Velc(float dx_ = 0.3f, float dy_ = 0.3f) : dx(dx_), dy(dy_) {}

    float getDx() const { return dx; }
    float getDy() const { return dy; }
    void setDx(float val) { dx = val; }
    void setDy(float val) { dy = val; }
    void invertirDx() { dx = -dx; }
    void invertirDy() { dy = -dy; }
};

