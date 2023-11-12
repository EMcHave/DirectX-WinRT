#include "pch.h"
#include "Cube.h"
#include "Line.h"
#include <algorithm>

using namespace DirectX;


Cube::Cube()
{
    m_position = XMFLOAT3(0.0f, 0.0f, 0.0f);
    m_force = XMVectorZero();
    m_moment = XMVectorZero();
    m_numberOfConnections = 0;
    m_isContact = false;
    Update();
}

Cube::Cube(XMFLOAT3 position, XMFLOAT4 color,
           float radius, float scale, bool isFixed)
{
    m_numberOfConnections = 0;
    m_scale = scale;
    m_isFixed = isFixed;
    m_position = position;
    m_radius = radius;
    m_force = XMVectorZero();
    m_moment = XMVectorZero();
    m_initialMatrix = XMMatrixIdentity();
    m_isContact = false;
    m_color = color;
    Update();
}

Cube::Cube(DirectX::XMFLOAT3 position, XMVECTOR quat, XMFLOAT4 color,
           float radius, float scale, bool isFixed)
{
    m_numberOfConnections = 0;
    m_scale = scale;
    m_isFixed = isFixed;
    m_position = position;
    m_radius = radius;
    XMStoreFloat4(&m_quaternion, quat);
    m_force = XMVectorZero();
    m_moment = XMVectorZero();
    m_initialMatrix = XMMatrixIdentity();
    m_isContact = false;
    m_color = color;
    Update();
}

void Cube::SetInitialQuaternion(XMVECTOR quaternion)
{
    m_initialMatrix = XMMatrixRotationQuaternion(quaternion);
    Update();
}

void Cube::Update()
{
    XMStoreFloat4x4(
        &m_modelMatrix, 
        XMMatrixScaling(m_scale, m_scale, m_scale) * m_initialMatrix * XMMatrixRotationQuaternion(VectorQuaternion()) *
        XMMatrixTranslation(m_position.x, m_position.y, m_position.z)
    );
}

void Cube::Position(DirectX::XMFLOAT3 position)
{
    m_position = position;
    //Update();
}

void Cube::Position(DirectX::XMVECTOR position)
{
    DirectX::XMStoreFloat3(&m_position, position);
    //Update();
}

void Cube::Quaternion(DirectX::XMFLOAT4 quaternion)
{
    m_quaternion = quaternion;
    Update();
}

void Cube::Quaternion(DirectX::XMVECTOR quaternion)
{
    DirectX::XMStoreFloat4(&m_quaternion, quaternion);
    Update();
}

DirectX::XMFLOAT4 Cube::Quaternion()
{
    return m_quaternion;
}

void Cube::RegisterConnection(Connection* con)
{
    m_numberOfConnections += 1;
    m_connections.push_back(con);
}

void Cube::UnRegisterConnection(Connection* con)
{
    m_numberOfConnections -= 1;
    auto rmv = std::remove_if(m_connections.begin(), m_connections.end(),
        [&](Connection* el) {
            return el == con;
        });
    m_connections.erase(rmv, m_connections.end());
    //UpdateColor(winrt::Windows::Foundation::Numerics::float4(1, 1, 0, 1));
}

