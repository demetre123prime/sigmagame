# Wildlands Survival — Unreal Engine 5 Starter

A native Unreal Engine 5 C++ survival-game starter. This is **not** an HTML or browser game.

## Status
This repository folder contains the playable-code foundation: a first-person character, movement/look/jump input, replicated survival stats (health, hunger, thirst, stamina), basic resource gathering interaction, project configuration, and Windows helper scripts.

It is a starter prototype, not a finished AAA game. It does not include licensed photorealistic art, a finished world, online matchmaking, or a packaged Windows executable. Open it in Unreal Engine to build and test locally.

## Requirements
- Unreal Engine 5.4 or newer (install through Epic Games Launcher)
- Visual Studio 2022 with **Game development with C++** and Windows SDK
- Windows 10/11, 64-bit

## Open the project
1. Install Unreal Engine 5.4+ and Visual Studio 2022 C++ workload.
2. Double-click `WildlandsSurvival.uproject`.
3. If asked, allow Unreal to build the C++ modules.
4. Open the project, create a level, and set it as the editor startup map.
5. Press Play.

## Controls
- WASD: move
- Mouse: look
- Space: jump
- E: interact with a resource actor (when one is placed in the level)

The default character is spawned by the game mode. For a quick test, add a floor and a few lights to an empty level.

## Build
Use Unreal Editor's **Platforms → Windows → Package Project** after the project compiles. The helper `Scripts/GenerateProjectFiles.bat` attempts to locate UnrealBuildTool through the standard Epic Games installation paths.

## Graphics / RTX 3050 guidance
Start with the **High** scalability preset, 1080p, TSR enabled, and Lumen software tracing only if performance allows. For a 6 GB laptop GPU, use medium shadow quality, moderate foliage density, texture streaming, and avoid 4K textures on every asset. A stable 60 FPS is a target to profile for, not a guarantee.

## Important next steps
- Add a landscape and original/licensed environment assets.
- Configure a proper input mapping context in Enhanced Input for a production build.
- Add save/load, crafting, inventory UI, building, wildlife AI, weather, and dedicated-server testing.
- Profile with Unreal Insights, `stat unit`, `stat gpu`, and `stat memory`.

All code here is original starter code. No third-party game assets are bundled.
