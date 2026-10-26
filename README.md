# Stage Chase

**Deranged rhythm festival road-trip for the 2026 Epic AI MegaJam.**

Drive between festival stages to drop sets and sing. The crowd is chasing you the entire time. You have realistic weapons to defend yourself. The better you perform, the more unhinged the chase gets.

## Core Loop

1. **Drive** — Navigate roads and festival grounds while music plays. Light rhythm influence on movement (boost on the drop, drift on the beat).
2. **Arrive & Perform** — Pull up to a stage and enter the rhythm game. **Funky Friday / FNF-style four-lane arrow charts** (Left/Down/Up/Right scrolling notes, holds, timing judgments). Performance quality affects crowd love *and* aggression.
3. **Defend** — Use realistic weapons (pistols, shotguns, melee, improvised festival gear) to keep the chasing crowd, security, or worse off your vehicle and off the stage.
4. **Escape / Next Stage** — Outrun, outplay, or clear enough space to reach the next venue before the show collapses.

## Tone

A little deranged. Festival energy turned feral. Neon, sweat, fire, blood, and bass. Not grimdark for its own sake — chaotic, stylish, and over-the-top.

## Rhythm System

Funky Friday style: 4-lane arrows scrolling to receptors. Judgments (Sick/Good/OK/Bad/Miss), holds, accuracy, and combo feed directly into chase intensity. See `docs/rhythm_system.md` for Unreal component sketch and chart format.

## Levels

Use `tools/generate_levels.py` to produce any number of levels (default 500):

```bash
python tools/generate_levels.py --count 500 --out data/levels.json
```

Each level has: type (drive/stage/hybrid), theme, chase type + intensity, primary weapon, music vibe, deranged twist, drive distance, and rhythm length. Scale as needed for prototype or full jam.

## Prototype Goals (MegaJam window)

- One vehicle with solid driving feel
- Two stages with distinct vibes (pull from generated levels)
- Data-driven Funky Friday-style rhythm charts
- Basic chase AI that reacts to performance score
- At least one realistic weapon with satisfying feedback
- Playable vertical slice: drive → perform → defend → drive

## Tech / Tools

- Unreal Engine (or UEFN)
- MCP + coding agents for rapid iteration
- Agent-generated materials, lighting, crowd meshes, and chart data
- Target: Windows build under 1 GB for itch.io submission

## Categories to Consider

- Best Overall / Solo Driver
- Render Royalty (visual maximalism)
- Glass Box (dev log of the agent workflow)
- Pocket Powerhouse if we go mobile-friendly

---

Created for the 2026 Epic AI MegaJam. Theme TBD (revealed Nov 11).
