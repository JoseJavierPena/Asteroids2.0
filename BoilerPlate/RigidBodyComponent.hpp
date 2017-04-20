//#pragma once
//#ifndef RIGID_COMPONENT_HPP_ 
//#define RIGID_COMPONENT_HPP_
//
//#include "Vector2.hpp"
//
//#include <iostream>
//
//class RigidBodyComponent : public Vector2
//{
//public:
//		RigidBodyComponent();
//		RigidBodyComponent(Vector2 gravity, Vector2 position, float mass = 1.0f, float dragFactor = 1.0f);
//		~RigidBodyComponent();
//
//		void Update(double deltaTime);
//		void ApplyForce(const Vector2 force, float angleInRadians = 1.0f);
//
//		void setMass(float mass) { m_mass = mass; };
//		void setVelocity(Vector2 velocity) { m_velocity = velocity; };
//
//		float getMass() const { return m_mass; };
//		float getSpeed() const { return m_velocity.getLengt; };
//		Vector2 getVelocity() const { return m_velocity; };
//
//protected:
//		float m_mass;
//		float m_drag;
//		Vector2 m_position;
//		Vector2 m_force;
//		Vector2 m_gravity;
//		Vector2 m_velocity;
//};
//
//#endif // !RIGID_COMPONENT_HPP_ 