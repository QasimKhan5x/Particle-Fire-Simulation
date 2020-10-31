#include <stdlib.h>

namespace pfs {
	
struct Particle {
	double m_x;
	double m_y;
	
	Particle();
};

Particle::Particle() {
	m_x = 2.0 * rand() / RAND_MAX - 1;
	m_y = 2.0 * rand() / RAND_MAX - 1;
}	
	
}