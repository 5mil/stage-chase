# Vertical Slice — Starting Point

This is Task 1. Goal: a playable drive → perform → defend loop in Unreal Engine as fast as possible.

## Project Setup Checklist

- [ ] Create new Unreal Engine 5.8+ project (Third Person or blank + starter content).
- [ ] Name: StageChase
- [ ] Enable plugins:
  - Enhanced Input
  - Chaos Vehicles (optional for first pass; can use character movement first)
  - Niagara
- [ ] Folder structure:
  - Content/Blueprints/Core
  - Content/Blueprints/Rhythm
  - Content/Blueprints/Vehicle
  - Content/Blueprints/Weapons
  - Content/Blueprints/Chase
  - Content/Data/Charts
  - Content/Data/Levels
  - Content/UI
  - Content/Characters
  - Content/Stages

## Enhanced Input Setup (Do This First)

Create Input Actions:
- IA_Move (Axis2D)
- IA_Look (Axis2D)
- IA_RhythmLeft (Digital)
- IA_RhythmDown (Digital)
- IA_RhythmUp (Digital)
- IA_RhythmRight (Digital)
- IA_Fire (Digital)
- IA_Boost (Digital) — optional for later

Create Input Mapping Context: IMC_Default
- Keyboard: WASD for move, Arrow keys or DFJK for rhythm lanes, Left Mouse for fire
- Gamepad: Left Stick move, D-Pad or Face buttons for rhythm lanes, Right Trigger for fire

Add the mapping context to the player controller or pawn on BeginPlay.

## Minimal Loop to Build First

### 1. Player Movement
- Simple vehicle or character pawn that can drive around an open map.
- Keyboard + gamepad input via Enhanced Input.

### 2. Stage Zone
- One trigger volume labeled "Stage".
- On enter: switch to rhythm mode (or overlay rhythm HUD).
- On exit: return to free movement.

### 3. Rhythm Prototype (Minimal)
- 4 receptors fixed on screen or world-space.
- Simple note spawner that fires notes on a timer or from a tiny hardcoded chart.
- Press matching key/button in the timing window → success.
- Success increments a PerformanceScore variable.

### 4. Basic Chase
- One AI actor that follows the player.
- Its max speed or aggression scales with PerformanceScore.

### 5. Basic Weapon
- One hitscan or melee that can damage or knock back the chase actor.

## First Blueprint Structure (Suggested)

- **BP_PlayerPawn** (or BP_Vehicle)
  - Enhanced Input component or controller binding
  - PerformanceScore float (exposed)
  - Simple movement

- **BP_RhythmManager** (Actor or Component)
  - Spawns notes on a timer for prototype
  - Checks input against active notes
  - Broadcasts OnNoteHit / OnNoteMiss
  - Updates PerformanceScore on the player

- **BP_StageTrigger** (Trigger Volume)
  - On Begin Overlap: Enable rhythm mode / show HUD
  - On End Overlap: Disable rhythm mode

- **BP_ChaseAI**
  - Simple Follow behavior (AI Move To or direct movement)
  - Max Speed or Aggression multiplied by player PerformanceScore

- **BP_Weapon** (Component or Actor)
  - Hitscan or simple melee on IA_Fire
  - Can damage or apply impulse to ChaseAI

## Concrete Implementation Sketches

### Rhythm Judgment (Minimal)
```
On Rhythm Input (lane):
  Find closest active note in that lane
  if time difference < 0.1s → Sick (+100 score, +1.0 performance)
  else if < 0.2s → Good (+50, +0.5)
  else if < 0.3s → OK (+25, +0.2)
  else → Miss (-10, -0.3)
  Remove the note
```

PerformanceScore is clamped 0–10 and drives chase intensity.

### Chase Speed Formula
```
BaseSpeed = 400
Speed = BaseSpeed + (PerformanceScore * 80)
MaxSpeed = 1200
```

Update every frame or on score change. Higher performance = faster chase.

### Weapon Hitscan (Minimal)
```
On Fire:
  Line trace from camera / muzzle forward 5000 units
  If hit BP_ChaseAI:
    Apply damage or impulse backward
    Optional: temporarily reduce its speed or PerformanceScore
```

### Success Criteria for Vertical Slice
- You can drive around.
- Enter the stage, hit a few notes, see score go up.
- Chase gets faster the better you do.
- You can shoot or hit the chase to slow it down.
- Exit and continue driving.

## Next Immediate Actions

1. Create the Unreal project.
2. Set up Enhanced Input for movement + 4 rhythm buttons.
3. Place a simple stage trigger and a follow AI.
4. Implement the smallest possible note judgment.

Once this loop is fun, we layer data-driven charts, better vehicle, modular weapons, and the weird characters on top.

## Notes

- Keep every system as a component or subsystem so it stays modular.
- Prefer data assets / JSON over hardcoding where easy.
- Document decisions in this repo as we go.
