#pragma once
#include "Cube.h"

class Connection
{
public:
	Connection(
		std::shared_ptr<Cube> p1,
		std::shared_ptr<Cube> p2,
		std::array<std::shared_ptr<Line>, 3> v1,
		std::array<std::shared_ptr<Line>, 3> v2);

	void Update();
	const std::shared_ptr<Cube> p1() { return m_particle1; }
	const std::shared_ptr<Cube> p2() { return m_particle2; }

	DirectX::XMVECTOR& n_i1(int i) const { return m_vectors1[i - 1]->VectorOrientation(); }
	DirectX::XMVECTOR& n_i2(int i) const { return m_vectors2[i - 1]->VectorOrientation(); }

	const std::shared_ptr<Line> v1_i(int i) { return m_vectors1[i]; }
	const std::shared_ptr<Line> v2_i(int i) { return m_vectors2[i]; }
private:
	std::shared_ptr<Cube> m_particle1;
	std::shared_ptr<Cube> m_particle2;

	std::array<std::shared_ptr<Line>, 3> m_vectors1;
	std::array<std::shared_ptr<Line>, 3> m_vectors2;
};

