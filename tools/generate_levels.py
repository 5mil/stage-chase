#!/usr/bin/env python3
"""
Stage Chase level generator.
Run: python generate_levels.py --count 500 --out levels.json
Produces varied drive/stage/hybrid levels with deranged festival twists,
chase types, weapons, and music vibes for the MegaJam prototype.
"""
import json
import random
import argparse

THEMES = [
    "Main Stage Inferno", "Rooftop Rave", "Moving Truck Stage", "Underground Bunker",
    "Cliffside Sunset", "Floating Platform", "Warehouse Rave", "Forest Clearing",
    "Highway Shoulder", "Abandoned Mall", "Beach Bonfire", "Bridge Overpass",
    "Parking Garage", "Train Yard", "Industrial Yard", "Cathedral Ruins",
    "Desert Highway", "City Alley", "Mountain Switchback", "Lake Dock"
]
CHASE = ["Feral Fans", "Security Riot", "Rival Band", "Mutated Crowd", "Police Pursuit", "Drone Swarm", "Pyro Crew", "Bass Cult"]
WEAPONS = ["Pistol", "Shotgun", "SMG", "Bat", "Flare Gun", "Improvised Mic Stand", "Fire Extinguisher", "Chainsaw (festival edition)"]
VIBES = ["High BPM Drop", "Slow Burn Build", "Freestyle Chaos", "Multi-lane Precision", "Call-and-Response", "Bass-Heavy Stomp"]
TWISTS = [
    "Stage is on fire", "Crowd sings the wrong lyrics aggressively", "Weapon is a microphone that shoots",
    "Vehicle starts floating", "Bass drops reverse gravity", "Security joins the performance",
    "Rival steals your setlist", "Crowd becomes the stage", "Lighting rig falls", "Fuel is running out"
]

def generate(count: int, seed: int = 42):
    random.seed(seed)
    levels = []
    for i in range(1, count + 1):
        theme = random.choice(THEMES)
        levels.append({
            "id": i,
            "name": f"{theme} #{i}",
            "type": "hybrid" if i % 3 == 0 else ("stage" if i % 2 == 0 else "drive"),
            "theme": theme,
            "chase_type": random.choice(CHASE),
            "chase_intensity": min(10, 1 + (i // max(1, count // 10))),
            "primary_weapon": random.choice(WEAPONS),
            "music_vibe": random.choice(VIBES),
            "deranged_twist": random.choice(TWISTS),
            "drive_distance": random.randint(200, 1200),
            "rhythm_length_seconds": random.randint(45, 180),
            "notes": f"Drive then perform. Defend with weapon against chase. Twist active."
        })
    return {"total": count, "game": "Stage Chase", "levels": levels}

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--count", type=int, default=500)
    parser.add_argument("--seed", type=int, default=42)
    parser.add_argument("--out", type=str, default="levels.json")
    args = parser.parse_args()
    data = generate(args.count, args.seed)
    with open(args.out, "w") as f:
        json.dump(data, f, indent=2)
    print(f"Wrote {args.count} levels to {args.out}")
