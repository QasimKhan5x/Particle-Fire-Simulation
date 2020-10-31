#include <stdlib.h>

namespace pfs {
	
struct Particle {
	double m_x;
	double m_y;
	double m_xspeed;
	double m_yspeed;
	
	Particle();
	void update();
};

Particle::Particle() {
	m_x = 2.0 * rand() / RAND_MAX - 1;
	m_y = 2.0 * rand() / RAND_MAX - 1;
	
	// get a random number in [-1,1] and scale it by 0.001
	m_xspeed = 0.001 * (2.0 * rand() / RAND_MAX - 1);
	m_yspeed = 0.001 * (2.0 * rand() / RAND_MAX - 1);
}

void Particle::update() {
	m_x += m_xspeed;
	m_y += m_yspeed;
	
	if (m_x <= -1.0 || m_x >= 1.0) {
		m_xspeed = -m_xspeed;
	}
	if (m_y <= -1.0 || m_y >= 1.0) {
		m_yspeed = -m_yspeed;
	}
}	
	
}