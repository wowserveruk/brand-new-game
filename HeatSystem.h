#pragma once
class HeatSystem {
public:
    int heat = 0;
    void Add(int amount) { heat += amount; if (heat > 100) heat = 100; }
    void CoolDown() { if (heat > 0) heat--; }
    bool IsPoliceChasing() const { return heat >= 70; }
};
