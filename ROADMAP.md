# Stage Chase — Practice Game Roadmap

Free high-quality modular release for the stream. Test skills before the MegaJam contest entry (contest game will be totally new).

## Immediate Next (this week)

1. **Vertical slice prototype (Full UE)** — Drive → Arrive → Rhythm perform → Defend/chase → Next stage. One vehicle, one stage, one weapon, basic chase.
2. **Data-driven levels** — Load from levels JSON. Modular so stages/weapons/chases can be swapped or added without code changes.
3. **Core systems (modular)**
   - Vehicle controller (smooth, customizable handling)
   - Rhythm input system (charts from data, customizable difficulty/lanes)
   - Weapon system (realistic feel, modular attachments/stats)
   - Chase AI (intensity scales with performance, modular behaviors)
4. **Customizability**
   - Settings for difficulty, music volume, weapon loadout, visual density
   - Level select or endless mode pulling from the 500
   - Easy to add new themes/weapons via data

## High Quality Targets

- Solid driving feel and satisfying rhythm feedback
- Clear visual language (festival neon + deranged chaos)
- Performance optimized for streaming
- Clean modular architecture (components, data assets, interfaces)

## Platform Targets

### Full Unreal Engine (only track)
- **Windows PC** free stream build (itch.io or direct download). First and main target.
- **Xbox Series X|S** later (UE 5.8+ GDK path; requires free ID@Xbox approval for full console).
- Supports the full vision: custom weird premium characters, realistic weapons, custom vehicle, deep Funky Friday-style rhythm system, beat-synced animations, data-driven everything.

### Contest
- Totally new project later for the MegaJam.

## Stream / Free Release Goals

- Playable full-UE Windows build with 20–50 levels
- Customizable options exposed
- Dev log / Glass Box style documentation of the process
- Giveaway on stream once the slice is fun

## Later (pre-MegaJam and beyond)

- Expand to full 500 or procedural runtime generation
- More weapons, chase types, deranged twists
- Polish pass, audio, particles
- Xbox if desired

## Tech Notes

- Unreal Engine (prefer 5.8+ for MCP and easier Xbox on PC path)
- Agents for materials, lighting, blueprint iteration, chart generation
- Keep everything data-driven for modularity
- Input: keyboard + gamepad from the start so Xbox/PC controller feels native
