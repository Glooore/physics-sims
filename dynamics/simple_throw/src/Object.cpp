#include "Object.h"
#include <assert.h>

Object::Object(float mass, std::vector<float> initial_position, std::vector<float> initial_velocity)
{
	assert(mass > 0);
	assert(initial_position.size() == 2);
	assert(initial_velocity.size() == 2);

	m_mass = mass;
	m_position = initial_position;
	m_velocity = initial_velocity;
	m_acceleration = std::vector<float> {0.0, -9.81};
};

std::vector<float> Object::GetPosition(void)
{
	return m_position;
};
std::vector<float> Object::GetVelocity(void)
{
	return m_velocity;
};
/* std::vector<float> Object::GetAcceleration(void); */
/* std::vector<float> Object::GetForce(void); */

void Object::Update(float dt)
{
	/* UpdateAcceleration(); */
	UpdateVelocity(dt);
	UpdatePosition(dt);
};

void Object::UpdatePosition(float dt)
{
	m_position[0] += m_velocity[0] * dt;
	m_position[1] += m_velocity[1] * dt;
};

void Object::UpdateVelocity(float dt)
{
	m_velocity[0] += m_acceleration[0] * dt;
	m_velocity[1] += m_acceleration[1] * dt;
};

void Object::UpdateAcceleration()
{

	m_acceleration[0] = m_mass * m_force[0];
	m_acceleration[1] = m_mass * m_force[1];
};

/* void Object::UpdateForce() */
/* { */

/* }; */
