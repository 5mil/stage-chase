# Levels Data

## Generate 500 levels

```bash
python ../tools/generate_levels.py --count 500 --out levels_500.json
```

The generator is deterministic (seed 42 by default). Output is a JSON array of level objects with:

- id, name, type (drive/stage/hybrid)
- theme, chase_type, chase_intensity (1-10 scaling)
- primary_weapon, music_vibe, deranged_twist
- drive_distance, rhythm_length_seconds

Load this in Unreal as a Data Table or via a simple JSON importer for fully modular, customizable levels. Add new themes/weapons/twists by editing the lists in `tools/generate_levels.py` and regenerating.

Sample structure (first level):
```json
{
  "id": 1,
  "name": "Underground Bunker #1",
  "type": "drive",
  "theme": "Underground Bunker",
  "chase_type": "Feral Fans",
  "chase_intensity": 1,
  "primary_weapon": "Flare Gun",
  "music_vibe": "Slow Burn Build",
  "deranged_twist": "Vehicle starts floating",
  "drive_distance": 342,
  "rhythm_length_seconds": 71
}
```
