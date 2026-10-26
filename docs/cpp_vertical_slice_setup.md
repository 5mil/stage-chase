# C++ Vertical Slice Setup

Modular components pushed to `Source/StageChase/` for the practice game.

## Files Added

- `Public/RhythmManagerComponent.h` / `Private/RhythmManagerComponent.cpp`
  - Handles active notes, timing judgment (Sick/Good/OK/Miss), and PerformanceScore (0–10).
  - Call `OnRhythmInput(Lane)` from Enhanced Input.
  - Call `SpawnTestNote(Lane, Delay)` for prototype notes.

- `Public/ChaseAIComponent.h` / `Private/ChaseAIComponent.cpp`
  - Scales owner Character MaxWalkSpeed from PerformanceScore.
  - Formula: BaseSpeed + (Score * SpeedPerPerformance), clamped to MaxSpeed.
  - Call `SetPerformanceScore(Score)` whenever the rhythm manager updates score.

## How to Use in a Third Person Project

1. Create a new UE 5.8+ Third Person project named StageChase.
2. Copy the `Source/StageChase` folder into your project's Source directory (or add the files via the editor).
3. Add the module to your `.uproject` and `.Build.cs` if needed, then regenerate project files.
4. Compile.
5. In your player pawn:
   - Add `URhythmManagerComponent`.
   - Bind the 4 rhythm Input Actions to call `OnRhythmInput` with the matching lane.
6. In your chase character:
   - Add `UChaseAIComponent`.
   - From the player's rhythm component (or a manager), call `SetPerformanceScore` on the chase component when score changes.
7. For the weapon: use a simple line trace on the Fire input and apply impulse or damage to the chase actor.

## Next

These are the core modular pieces for the vertical slice. Wire them in Blueprints or expand with chart loading, holds, and better AI as needed.

All design details remain in `docs/vertical_slice.md`.
