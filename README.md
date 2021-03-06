# Space Attack

Space Attack (or whatever the name becomes) is a personal project I've started since I have wanted to make a game for a while. The game is going to be a blend of the classic space invaders and castle defender. There will be at least two modes: one where you are defending your base using your spaceship and placed defenses, and one where you are on the offensive, trying to clear out an area of aliens. Some of the intended features include:
    - Multple Levels of AI for the enemies
    - Co-op online play with friends
    - Accurate collision detection between various shaped enemies
    - Controllable camera
    - Physics (momentum transfer, and hopefully more)
    - Sound

A large part of this project is to explore different areas of game development. I could have used Unreal or Unity, but I am using C++ and SDL2 so I can manually implement all the different aspects and learn from the ground up how they all work.

## Status:

Below is a record if issues to fix and features to implement, mostly so I don't forget and can track progress.

### Current issues:
    - VSYNC currently not working. Lots of choppiness. (2/5/17). See frame independent movement.
    - Key.repeat flag just not working with at least sdl 2.0.5 (2/5/17)

### Features:

#### Completed:
    - (2/6/17) Implemented simple frame independent movement
    - (2/6/17) smooth movement

#### In Progress:
    - (2/6/17) Command design pattern (NEEDS WORK!!)

#### Future:
    - Manual solution to Key.Repeat issue and timer for weapon rate of fire
    - Reorganize bullet + weapon classes
    - Reorganize controller, possibly make it so not every class needs reference to it
    - collision detection
    - Quad tree
