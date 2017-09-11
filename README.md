# C-SDL-2D-GAME

A simple implementation of SDL2 and SDL2 image to create a game engine featuring;
  DeltaTime
  InputHandeling
  TextureManagement
  CollisonDetection
  2DVectors
  and a core game loop implementation

The engine comes with a complete development toolchain for cross-development on windows and linux operating systems through the use of CMAKE
- No additional files will be required to compile the program on linux, only SDL2 and other linked SDL2 library extensions
- Compilation on windows required MSBUILD, a FindSDL2_image.cmake, and an sdl2-config.cmake, in addition to the aforementioned development libs. Copies of these files have been included in the repository for easier setup, and as a backup
