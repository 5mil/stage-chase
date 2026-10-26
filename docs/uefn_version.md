# Stage Chase — Parallel UEFN Version

A simplified Fortnite island built in parallel with the full Unreal Engine practice game. Same vibe, same core loop idea, adapted to UEFN constraints. Not the MegaJam contest entry (that will be a totally new project).

## Goals

- Playable multiplayer island that captures the deranged festival chase + rhythm performance fantasy.
- Free to play in Fortnite for stream giveaways / testing reach.
- Reuse concepts, themes, level ideas, and chart data where possible.
- Stay within UEFN limits (Verse, devices, Scene Graph, Fortnite character model).

## Core Loop (UEFN Adaptation)

1. **Drive / Move** — Use Fortnite vehicles or custom movement devices to travel between stage areas.
2. **Arrive & Perform** — Enter a rhythm zone. Simplified arrow / button-prompt system using devices or Verse UI (not full custom note spawner). Accuracy affects score and crowd intensity.
3. **Defend** — Use Fortnite weapons or custom ability devices to push back chasing players / NPCs / props.
4. **Escape / Next Stage** — Reach the next venue or survive the round.

## What Transfers vs What Changes

### Can reuse / adapt
- Level themes and deranged twists (from the 500-level generator)
- Music vibe ideas and BPM targets
- Chase intensity concept (performance score → more pressure)
- Visual language (neon festival, chaos)
- Chart timing ideas (simplified note sequences)

### Must adapt or simplify
- **Characters**: Fortnite character + skins / accessories instead of custom weird premium models. Use emotes and ability VFX for performance reactions.
- **Rhythm system**: Device-based or Verse UI prompts instead of full scrolling 4-lane note actors. Still 4 directions, timing judgments, holds where possible.
- **Weapons**: Fortnite arsenal or custom ability devices (now publishable). Realistic feel approximated with sound and VFX.
- **Vehicle**: Fortnite vehicles or simple custom movement.
- **AI / Chase**: Verse-controlled NPCs, prop spawners, or player-vs-player pressure instead of full custom AI.

## Technical Approach (UEFN)

- **Verse** for game state, scoring, intensity scaling, and custom logic.
- **Devices** for triggers, timers, UI, weapon granters, vehicle spawners, etc.
- **Scene Graph** (where useful) for modular stage pieces.
- **Custom Abilities** (now publishable) for performance reactions and defensive tools.
- Data: hardcode or load simplified chart/level data via Verse structures (no external JSON loading like full UE).

## Parallel Development Notes

- Keep the full UE project as the high-fidelity version.
- UEFN version is a separate island project.
- Share design docs, theme lists, and chart concepts between them.
- Stream both when ready: full UE for quality, UEFN for easy multiplayer access.

## Next Steps for UEFN Track

1. Create the UEFN island project.
2. Block out 2–3 stage areas with festival props.
3. Implement a simple 4-direction rhythm prompt system in Verse.
4. Add a basic chase pressure mechanic (spawning or speed increase based on score).
5. Wire one defensive ability / weapon granter.
6. Test multiplayer loop.

This keeps the practice game moving on two tracks without blocking the full UE vertical slice or the future contest entry.
