# Stage Chase — Full Task List (Full UE Practice Game)

Ordered list of everything needed for a high-quality, modular, free stream release. Contest project is separate and new.

## Phase 1 — Vertical Slice (Start Here)

1. **Project setup**
   - Create Unreal Engine 5.8+ project (or latest available).
   - Enable Enhanced Input, Chaos Vehicles (or simple character movement for first pass), Niagara, and basic audio.
   - Folder structure: Content/Blueprints, Content/Data, Content/Characters, Content/Vehicles, Content/Weapons, Content/Stages, Content/UI.

2. **Minimal playable loop**
   - One simple vehicle (or pawn with vehicle-like movement).
   - One stage area (open space with a performance zone trigger).
   - One basic weapon (hitscan pistol or melee).
   - One simple chase actor (follows player, speed increases with a performance score).
   - Drive → enter zone → rhythm performance → exit/defend → loop or next marker.

3. **Core rhythm prototype**
   - 4 receptors (Left/Down/Up/Right).
   - Note spawner that reads a simple chart (hardcoded or JSON).
   - Judgment system (Sick/Good/OK/Bad/Miss).
   - Score + combo that feeds a global performance intensity value.

## Phase 2 — Data-Driven Systems

4. **Level data loader**
   - Load levels from JSON (output of tools/generate_levels.py).
   - Spawn stage type, theme, weapon, chase intensity from data.

5. **Chart system**
   - Full chart JSON loader (time, lane, type, duration).
   - Support for holds.
   - Scroll speed and timing windows configurable.

6. **Custom song import**
   - Tool or runtime path to take an MP3, detect BPM/onsets, generate chart JSON.

## Phase 3 — Core Modular Systems

7. **Vehicle controller**
   - Smooth handling, boost on beat (optional), customizable stats.
   - Gamepad + keyboard from the start.

8. **Weapon system**
   - Modular weapons (pistol, shotgun, melee, festival gear).
   - Realistic feel: recoil, sound, impact feedback.
   - Loadout selectable.

9. **Chase AI**
   - Modular behaviors.
   - Intensity scales with rhythm performance.
   - Different chase types (crowd, security, deranged).

10. **Character system**
    - Weird premium modular characters (not Roblox/Fortnite style).
    - Beat-synced idle sway, hit reactions, material pulses.
    - Customizable parts and accessories.

## Phase 4 — Content & Polish

11. **Stages & environments**
    - 20–50 hand-tuned or generated stages from the level list.
    - Festival neon + deranged visual language.

12. **UI / UX**
    - Rhythm HUD (receptors, judgment text, combo, score).
    - Settings menu (difficulty, volume, loadout, visual density).
    - Level select or endless mode.

13. **Audio**
    - Music integration, hit sounds, vehicle sounds, weapon sounds, crowd reactions.

14. **Performance & streaming**
    - Optimize for solid framerate while streaming.
    - Clean packaging for Windows build.

## Phase 5 — Release Prep

15. **Free stream build**
    - Windows package under reasonable size.
    - itch.io page or direct download instructions.
    - Dev log / Glass Box notes of the process.

16. **Xbox prep (later)**
    - Controller polish.
    - ID@Xbox path if desired.

## Current Priority

**Start on Phase 1, Item 1 & 2: Project setup + minimal playable loop.**

Everything is data-driven and modular so later systems slot in without rewrites.
