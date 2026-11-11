# Arcade

Epitech 2019 C++ project: a retro gaming platform where both the **games** and the **graphics libraries** are shared libraries loaded at runtime (`dlopen`) and can be swapped while playing.

- **Games:** Pac-Man, Nibbler (snake)
- **Graphics backends:** SFML, ncurses, Allegro
- Core with menu and score tracking, talking to modules through the `IGameModule` / `IDisplayModule` interfaces

## Build

Requires `g++`, SFML, ncurses and Allegro.

```bash
make            # builds the core, the graphics libs (lib/) and the games (games/)
```

## Run

```bash
./arcade ./lib/lib_arcade_ncurses.so
```

The argument is the graphics library to start with. Interface documentation: [`doc/Documentation_Arcade.pdf`](doc/Documentation_Arcade.pdf).
