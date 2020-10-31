#include <stdlib.h>
#include <math.h>
namespace pfs {
	
struct Particle {
	double m_x;
	double m_y;
	double m_speed;
	double m_direction;
	
	Particle();
	void update();
};

Particle::Particle(): m_x(0), m_y(0) {
	m_direction = 2 * M_PI * rand() / RAND_MAX;
	m_speed = 0.003 * rand() / RAND_MAX;
}

void Particle::update() {
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);
	
	m_x += xspeed;
	m_y += yspeed;
}	
	
}