# Particle Fire Simulation
This program manages a bunch of virtual particles that gradually change color and circle around each other. The particles have a nice blur effect to them as well.

# Requires
- [SDL2 Library](https://www.libsdl.org/download-2.0.php)

I use mingw32 to compile C/C++ programs. After downloading the SDL2 development library for mingw, you can follow [this guide](http://lazyfoo.net/SDL_tutorials/lesson01/windows/mingw/index.php) to ensure you can compile a C/C++ program that uses SDL2. 

# Compile
Use g++ -o main.exe main.cpp -lmingw32 -lSDL2main -lSDL2

# Further Explorations
- [ ] Create an installer
- [ ] Use swarms of particles to find approximate solutions to equations **(AI)**
- [ ] Create fountains **(GUI)**
- [ ] Allow particles to bounce around the screen and orbit each other **(GUI)**
- [ ] Create mathematical simulations of how particles move **(Math)**
