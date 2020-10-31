#include <stdlib.h>
#include <math.h>
namespace pfs {
	
struct Particle {
	double m_x;
	double m_y;
	
	Particle();
	void update(int interval);
	
	private:
		double m_speed;
		double m_direction;
		void init();
};

Particle::Particle() {
	init();
}

void Particle::init() {
	m_x = 0;
	m_y = 0;
	m_direction = 2 * M_PI * rand() / RAND_MAX;
	m_speed = 0.03 * rand() / RAND_MAX;
	
	// Explosion is inversely proportional to distance to center
	m_speed *= m_speed;
}

void Particle::update(int interval) {
	
	m_direction += interval * 0.0003;
	
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);
	
	// Ensure uniform speed in all systems
	m_x += xspeed * interval;
	m_y += yspeed * interval;
	
	
	// Reinitialize particles that fall off the screen
	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		init();
	}
	
	// Reinitialize a particle a 100th of the time
	if (rand() < RAND_MAX/100) {
		init();
	}
}	
	
}