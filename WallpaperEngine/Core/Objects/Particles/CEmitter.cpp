#include "CEmitter.h"

#include "WallpaperEngine/Core/Core.h"

using namespace WallpaperEngine::Core::Objects::Particles;

CEmitter* CEmitter::fromJSON (json data)
{
    json::const_iterator directions_it = data.find ("directions");
    json::const_iterator distancemax_it = data.find ("distancemax");
    json::const_iterator distancemin_it = data.find ("distancemin");
    json::const_iterator id_it = data.find ("id");
    json::const_iterator name_it = data.find ("name");
    json::const_iterator origin_it = data.find ("origin");
    json::const_iterator rate_it = data.find ("rate");

    if (directions_it == data.end ())
    {
        throw std::runtime_error ("Particle emitter must have direction specified");
    }

    if (distancemax_it == data.end ())
    {
        throw std::runtime_error ("Particle emitter must have maximum distance");
    }

    if (distancemin_it == data.end ())
    {
        throw std::runtime_error ("Particle emitter must have minimum distance");
    }

    if (name_it == data.end ())
    {
        throw std::runtime_error ("Particle emitter must have a name");
    }

    if (origin_it == data.end ())
    {
        throw std::runtime_error ("Particle emitter must have an origin");
    }

    if (rate_it == data.end ())
    {
        throw std::runtime_error ("Particle emitter must have a rate");
    }

    return new CEmitter (
            WallpaperEngine::Core::ato3vf (*directions_it),
            *distancemax_it,
            *distancemin_it,
            (id_it == data.end () ? 0 : (irr::u32) (*id_it)),
            *name_it,
            WallpaperEngine::Core::ato3vf (*origin_it),
            *rate_it
    );
}

CEmitter::CEmitter (
        const irr::core::vector3df& directions,
        irr::u32 distancemax,
        irr::u32 distancemin,
        irr::u32 id,
        std::string name,
        const irr::core::vector3df& origin,
        irr::f64 rate):
    m_directions (directions),
    m_distancemax (distancemax),
    m_distancemin (distancemin),
    m_id (id),
    m_name (std::move(name)),
    m_origin (origin),
    m_rate (rate)
{
}


const std::string& CEmitter::getName () const
{
    return this->m_name;
}

irr::u32 CEmitter::getDistanceMax () const
{
    return this->m_distancemax;
}

irr::u32 CEmitter::getDistanceMin () const
{
    return this->m_distancemin;
}

irr::core::vector3df* CEmitter::getDirections ()
{
    return &this->m_directions;
}

irr::core::vector3df* CEmitter::getOrigin ()
{
    return &this->m_origin;
}

irr::f64 CEmitter::getRate () const
{
    return this->m_rate;
}