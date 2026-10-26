# Characters — Weird, Premium, Customizable

Not Roblox. Not Fortnite. Cool, premium, and a little deranged.

Players drive and perform as unique festival entities. The look should feel high-end and art-directed: stylized proportions, rich materials, strong silhouettes, and customization that actually changes the vibe.

## Design Direction

- **Premium feel**: High-quality materials (subsurface, clearcoat, emissive accents, detailed normals), thoughtful lighting response, strong silhouette.
- **Weird**: Unusual proportions, surreal anatomy options, festival-mutated features, expressive faces that aren't cute or heroic.
- **Not**: Blocky, toy-like, or standard battle-royale cartoon.
- Fits the deranged festival tone — neon, sweat, chrome, organic, glitch, ritual.

## Customization System (Modular)

Data-driven so new options can be added without code changes.

### Core Modules

1. **Base Body**
   - Several base skeletons / proportions (tall & lanky, compact & dense, asymmetrical, multi-limbed variants, etc.)
   - Shared animation set where possible; unique sets for extreme bases.

2. **Head / Face**
   - Swappable heads with different eye counts, mouth styles, horn/antenna options.
   - Blend shapes or morph targets for performance reactions (singing, impact, etc.).

3. **Materials / Skins**
   - Premium material instances: chrome, wet latex, glowing circuitry, fleshy neon, cracked porcelain, liquid metal, festival glitter, etc.
   - Color channels + emissive intensity exposed.

4. **Accessories**
   - Modular attachments: extra arms, speaker implants, mask pieces, jewelry, weapon holsters, crowd-control devices, ritual objects.
   - Socket-based so they attach cleanly.

5. **Outfit Layers**
   - Jacket, pants, boots, gloves — each with material overrides.
   - Some pieces alter silhouette dramatically.

6. **Performance Mods**
   - Visual effects that trigger on rhythm hits (eye glow, particle burst, material pulse).
   - Tied to the Funky Friday judgment system.

### Customization UI

- In-game creator with live preview.
- Categories: Body, Head, Materials, Accessories, Outfit.
- Save / load presets.
- Stream-friendly: easy to show off wild combinations.

## Beat-Synced Animation

Characters move on screen with the beats during the rhythm performance sections.

### Core Behaviors

- **Idle Performance Loop**
  - Subtle body sway, head bob, and accessory motion locked to BPM.
  - Driven by the chart BPM or a Quartz clock / timeline.
  - Different intensity based on current combo or chase state.

- **Hit Reactions**
  - On note judgment (Sick / Good / etc.): short additive animation — head snap, shoulder pulse, arm flick, speaker mouth flare, eye glow burst.
  - Stronger reaction on higher judgments.
  - Misses can trigger a stumble or glitch stutter.

- **Hold Notes**
  - Sustained pose or pulsing motion while the hold is active.

- **Material & Accessory Sync**
  - Emissive intensity, clearcoat, or particle systems pulse on the beat.
  - Floating rings, extra limbs, or wiring animate in time with the music.
  - Morph targets on faces (mouth open on vocals, eyes widen on drops).

### Implementation Sketch (Unreal)

- Animation Blueprint with layered states:
  - Base performance idle (BPM-driven)
  - Additive hit reactions triggered by RhythmManager events
  - Blend spaces for intensity
- Use the existing `URhythmManagerComponent` events (OnNoteHit, OnMiss, OnComboChange) to drive AnimNotifies or direct montage plays.
- For modular bodies: Leader Pose Component so accessories and variant limbs follow the main skeleton, with optional secondary anims.
- Optional: Control Rig or simple procedural offsets for floating parts and jiggle.
- Materials use Custom Primitive Data or Material Parameter Collections updated on the beat for glow pulses.

### Feel Goals

- Characters feel alive and performing, not static models.
- Movement is stylish and premium — not exaggerated cartoon bounce.
- Sync is tight enough that good rhythm play makes the character look powerful.
- Weird anatomy still reads clearly in motion.

## Technical Notes (Unreal)

- Modular character using Leader Pose or similar for shared animations.
- Material instances + custom primitive data for per-player variation.
- Data Assets for each option (mesh, material, socket, stats if any).
- Character appearance component that applies selections at runtime.
- Later: simple morph or control-rig adjustments for finer weirdness.

## Example Directions

- Chrome-skinned figure with too many eyes and a speaker for a mouth — speaker pulses and eyes track on beats.
- Tall, dripping neon-organic form with floating accessory rings — rings orbit and body sways.
- Porcelain mask face that cracks and glows from inside during high combos — cracks pulse brighter on hits.
- Asymmetrical multi-arm performer with festival wiring growing out of the skin — extra arms gesture on notes.

All options should feel expensive and intentional, not generic or meme-y.

This system stays modular so we can expand the roster of weird premium parts over time and still keep the free stream build looking sharp.
