#include "Particle.cpp"

namespace pfs {
	
class Swarm {
	private:
		Particle* m_pParticles;
		int lastTime;
		
	public:
		const static int N_PARTICLES = 5000;
		Swarm();
		virtual ~Swarm();
		void update(int elapsed);
		const Particle* const getParticles() { return m_pParticles; }
};

Swarm::Swarm(): lastTime(0) {
	m_pParticles = new Particle[N_PARTICLES];
}

Swarm::~Swarm() {
	delete[] m_pParticles;
}

void Swarm::update(int elapsed) {
	int interval = elapsed - lastTime;
	for (int i = 0; i < N_PARTICLES; i++) {
		m_pParticles[i].update(interval);
	}
	lastTime = elapsed;
}
	
}