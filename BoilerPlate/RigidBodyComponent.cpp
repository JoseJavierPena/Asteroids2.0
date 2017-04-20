//#include "RigidBodyComponent.hpp"
//
////const std::string COMP_NAME = "PHYSICS_COMPONENT";
//
//RigidBodyComponent::RigidBodyComponent()
//	: m_gravity(0.0f, 0.0f)
//	, m_position(0.0f, 0.0f)
//	, m_mass(1.0f)
//	, m_drag(1.0f)
//{};
//
//RigidBodyComponent::RigidBodyComponent(Vector2 gravity, Vector2 position, float mass, float dragFactor)
//	: m_mass(mass)
//	, m_drag(dragFactor)
//	, m_position(position)
//	, m_gravity(gravity)
//{};
//
//RigidBodyComponent::~RigidBodyComponent()
//{};
//
//void RigidBodyComponent::Update(double deltaTime)
//{
//	//Apply acceleration
//	m_velocity += m_gravity;
//
//	//Apply drag
//	m_velocity *= m_drag;
//
//	
//}