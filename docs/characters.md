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

## Technical Notes (Unreal)

- Modular character using Leader Pose or similar for shared animations.
- Material instances + custom primitive data for per-player variation.
- Data Assets for each option (mesh, material, socket, stats if any).
- Character appearance component that applies selections at runtime.
- Later: simple morph or control-rig adjustments for finer weirdness.

## Example Directions

- Chrome-skinned figure with too many eyes and a speaker for a mouth.
- Tall, dripping neon-organic form with floating accessory rings.
- Porcelain mask face that cracks and glows from inside during high combos.
- Asymmetrical multi-arm performer with festival wiring growing out of the skin.

All options should feel expensive and intentional, not generic or meme-y.

This system stays modular so we can expand the roster of weird premium parts over time and still keep the free stream build looking sharp.
