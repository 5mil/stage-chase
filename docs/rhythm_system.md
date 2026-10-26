# Rhythm System — Funky Friday Style

When the player arrives at a stage, the game switches (or overlays) to a four-lane arrow chart inspired by Funky Friday / Friday Night Funkin'.

## Core Feel

- 4 lanes: Left, Down, Up, Right (color-coded)
- Notes scroll toward static receptors (upscroll or downscroll option)
- Judgments: Sick / Good / OK / Bad / Miss (timing windows)
- Hold notes and optional rolls
- Accuracy + combo affect chase intensity (higher score = more aggressive crowd or temporary stun)
- Customizable: scroll speed, keybinds, arrow skins, downscroll

## Chart Format (JSON)

Simple, data-driven format. Store charts in `data/charts/`.

```json
{
  "id": "sample_stage_1",
  "bpm": 128,
  "scrollSpeed": 1.2,
  "notes": [
    { "time": 0.5, "lane": 0, "type": "tap" },
    { "time": 1.0, "lane": 2, "type": "tap" },
    { "time": 1.5, "lane": 1, "type": "hold", "duration": 0.75 },
    { "time": 2.25, "lane": 3, "type": "tap" },
    { "time": 2.75, "lane": 0, "type": "tap" },
    { "time": 3.0, "lane": 1, "type": "tap" }
  ]
}
```

- `lane`: 0=Left, 1=Down, 2=Up, 3=Right
- `type`: "tap" or "hold"
- `time` / `duration` in seconds from chart start
- Easy to generate with agents or convert from existing FNF charts

## Unreal Component Sketch

Modular, data-driven. Prefer components + data assets.

### Key Classes / Components

1. **URhythmChart** (Data Asset or Struct)
   - Holds BPM, notes array, metadata
   - Loaded from JSON at runtime or baked into assets

2. **URhythmManagerComponent** (on GameMode or dedicated Actor)
   - Starts/stops chart
   - Tracks current time, accuracy, combo, score
   - Broadcasts events: OnNoteHit, OnMiss, OnComboChange, OnChartEnd
   - Feeds performance score to Chase AI

3. **ANoteSpawner** or **UNoteSpawnerComponent**
   - Spawns note actors or UI widgets based on chart time
   - Handles scroll speed and direction
   - Pools notes for performance

4. **AReceptor** or UI Receptors (4 of them)
   - Static targets
   - Flash / animate on hit
   - Color per lane

5. **ANoteActor** (or UUserWidget for pure UI)
   - Moves toward receptor
   - Handles hit detection / input matching
   - Hold progress visual

6. **UJudgmentSystem**
   - Timing windows (e.g. Sick: ±50ms, Good: ±100ms, etc.)
   - Returns judgment enum and score multiplier
   - Optional "Fresh" perfect timing burst

7. **Input Mapping**
   - Enhanced Input actions for Left/Down/Up/Right
   - Configurable keybinds (arrows, DFJK, WASD, etc.)

### Flow

1. Level or stage trigger starts chart via RhythmManager.
2. Chart loads notes.
3. Spawner creates notes at appropriate times, offset by scroll.
4. Player inputs match lanes → JudgmentSystem evaluates → feedback + score update.
5. On chart end or fail condition, return control to driving/chase and apply performance modifier to AI intensity.

### Modularity Notes

- Charts are pure data → easy agent generation or manual editing.
- Swap note visuals, judgment windows, and scroll behavior without touching core logic.
- Can run as full-screen overlay or in-world UI on the stage.
- Later: multi-key modes, modcharts, character animations synced to hits.

This keeps the rhythm system clean, customizable, and ready for the free stream build and later contest version.
