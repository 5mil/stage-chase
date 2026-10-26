# Custom Song Import + Auto Chart Mapping

Players can drop in an MP3 and the game (or a companion tool) automatically generates a Funky Friday-style chart from it.

## Feature Goals

- Import any MP3 (or WAV)
- Detect BPM and onsets / beats
- Generate a playable 4-lane chart automatically
- Optional difficulty levels (fewer notes on Easy, denser on Hard)
- Save the generated chart as JSON so it can be edited or reused
- Works offline for the free stream build

## High-Level Flow

1. User selects an MP3 file (in-game file dialog or drag-and-drop).
2. Audio is analyzed for:
   - BPM (tempo)
   - Beat / onset times (energy peaks, spectral flux, etc.)
3. Chart generator places notes on those times across the 4 lanes (with some variation so it doesn't feel robotic).
4. Output is a standard chart JSON (same format as `data/charts/`).
5. Rhythm system loads it immediately for playtesting.

## Auto-Mapping Approach

### Practical Options (pick one or combine)

**Option A — External Python tool (recommended for quality + modularity)**
- Use `librosa` or `aubio` for beat tracking and onset detection.
- Script lives in `tools/auto_chart.py`.
- Player (or streamer) runs it once, gets a JSON chart, drops it in the game.
- Easy to iterate and improve the algorithm without recompiling Unreal.

**Option B — In-Unreal (runtime)**
- Use Unreal's Audio Analysis tools / Quartz / custom DSP if available.
- Or a simple energy-based peak detector on the waveform.
- Faster iteration during play but less accurate than dedicated libraries.

**Option C — Hybrid**
- Python tool generates the chart.
- Unreal just loads the resulting JSON (already supported by the rhythm system).

### Simple Generation Rules (starter)

- Detect BPM and beat grid.
- Place a note on most strong beats.
- Randomly assign lanes (with bias against repeating the same lane too often).
- Occasionally turn a note into a short hold.
- Density scales with difficulty:
  - Easy: every 2nd or 4th beat
  - Normal: most beats
  - Hard: beats + some off-beats / denser patterns

## Unreal Integration Sketch

- `UCustomSongImporter` component or Blueprint:
  - File picker → load MP3 into a Sound Wave
  - Call analysis (or load pre-generated JSON)
  - Feed resulting `URhythmChart` to the existing RhythmManager
- Settings:
  - Difficulty
  - Note density slider
  - Prefer holds vs taps
- UI: "Import Song" button in the menu or pause screen. Generated chart appears in a custom songs list.

## Example Tool Stub (Python)

```python
# tools/auto_chart.py (conceptual)
# pip install librosa numpy
import librosa
import json
import random

def generate_chart(mp3_path, difficulty="normal", out_path="chart.json"):
    y, sr = librosa.load(mp3_path)
    tempo, beats = librosa.beat.beat_track(y=y, sr=sr)
    beat_times = librosa.frames_to_time(beats, sr=sr)

    notes = []
    for i, t in enumerate(beat_times):
        if difficulty == "easy" and i % 2 != 0:
            continue
        lane = random.randint(0, 3)
        note_type = "hold" if random.random() < 0.15 else "tap"
        duration = random.uniform(0.3, 0.8) if note_type == "hold" else 0
        notes.append({"time": float(t), "lane": lane, "type": note_type, "duration": duration})

    chart = {
        "id": "custom_" + mp3_path,
        "bpm": float(tempo),
        "scrollSpeed": 1.0,
        "notes": notes
    }
    with open(out_path, "w") as f:
        json.dump(chart, f, indent=2)
    return chart
```

## Next Steps for Implementation

1. Add the Python auto-chart tool (even a basic version).
2. Wire a simple file import in Unreal that loads the resulting JSON.
3. Add a "Custom Songs" menu entry.
4. Expose density / difficulty controls.
5. Later: better onset detection, lane patterning that follows the music better, hold placement on sustained notes.

This keeps the feature modular: the analysis can live outside the engine, the rhythm system already consumes the chart format, and players can bring any song to the festival.
