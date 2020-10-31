#include "Particle.cpp"

namespace pfs {
	
class Swarm {
	private:
		Particle* m_pParticles;
		
	public:
		const static int N_PARTICLES = 5000;
		Swarm();
		virtual ~Swarm();
		void update();
		const Particle* const getParticles() { return m_pParticles; }
};

Swarm::Swarm() {
	m_pParticles = new Particle[N_PARTICLES];
}

Swarm::~Swarm() {
	delete[] m_pParticles;
}

void Swarm::update() {
	for (int i = 0; i < N_PARTICLES; i++) {
		m_pParticles[i].update();
	}
}
	
}