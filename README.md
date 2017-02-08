# Space Attack -- Status: Active and in progress

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

### Issues:

#### Past Issues:
    - (2/7/17) Key.repeat was not working on the libsdl2-dev install of sdl2.0.5. Fixed with latest hg install though

#### Current issues:
    - (2/5/17) VSYNC currently not working. Lots of choppiness. See frame independent movement.

### Features:

#### Completed:
    - (2/6/17) Implemented simple frame independent movement
    - (2/6/17) smooth movement
    - (2/6/17) Better method for binding commands
    - (2/6/17) Command design pattern
    - (2/7/17) Reorganize controller, possibly make it so not every class needs reference to it
        - Made controller a singleton
    - (2/7/17) Reorganizing the timer and input handler into the controller
    - (2/7/17) Fixed memory leaks (besides opengl's implicit memory leaks)

#### In Progress:

#### Future:
    - basic enemy
    - Reorganize bullet + weapon classes
    - Textures
    - collision detection
    - Quad tree
