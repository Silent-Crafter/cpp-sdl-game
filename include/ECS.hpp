#pragma once

#include <cstddef>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

// what is this shit
// i dont know
// need to study
// feel free to educate me if you are reading this and know about it
// cpp noob here
using ComponentID = std::size_t;

inline ComponentID getComponentID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept
{
    static ComponentID typeID = getComponentID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
    private:
    public:
        Entity* entity;

        virtual void init() {}
        virtual void update() {}
        virtual void draw() {}

        virtual ~Component() {}
};

class Entity
{
    private:
        bool active = true;
        std::vector<std::unique_ptr<Component>> components;

        ComponentArray componentArray;
        ComponentBitSet componentBitSet;

    public:

        void update() 
        {
            for ( auto& c : components ) c->update();
            for ( auto& c : components ) c->draw();
        }

        void draw() {}
        bool isActive() const { return active; }
        void destroy() { active = false; }
};
