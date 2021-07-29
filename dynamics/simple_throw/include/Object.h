#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <vector>

class Object
{
	public:
		/* Object(); */
		Object(float mass, std::vector<float> initial_positon, std::vector<float> initial_velocity);
		void Update(float dt);

		std::vector<float> GetPosition(void);
		std::vector<float> GetVelocity(void);
		std::vector<float> GetAcceleration(void);
		std::vector<float> GetForce(void);
	protected:
		float m_mass;
		/* float m_radius; */
		// float m_area;

		// (x, y) position vector
		std::vector<float> m_position;
		
		// (x, y) velocity vector
		std::vector<float> m_velocity;

		// (x, y) acceleration vector
		std::vector<float> m_acceleration;

		// (x, y) force vector
		std::vector<float> m_force;
	private:

		void UpdatePosition(float dt);
		void UpdateVelocity(float dt);
		void UpdateAcceleration();
		void UpdateForce();

		void ApplyForce(std::vector<float> force_vector);
		void ApplyGravity();
};

#endif
