# Stage Chase — Practice Game Roadmap

Free high-quality modular release for the stream. Test skills before the MegaJam contest entry (contest game will be totally new).

## Full Task List

See `docs/full_task_list.md` for the complete ordered list of everything needed.

## Current Focus — Phase 1: Vertical Slice

**Starting now.**

Detailed plan: `docs/vertical_slice.md`

1. Project setup (UE 5.8+, folders, Enhanced Input)
2. Minimal playable loop: Drive → Stage zone → Simple rhythm → Basic chase that reacts to score → Basic weapon → Exit and continue

## After Vertical Slice

- Data-driven levels and charts
- Full vehicle, weapon, chase, and character systems
- Custom song import
- 20–50 stages
- Free Windows stream build

## High Quality Targets

- Solid driving feel and satisfying rhythm feedback
- Clear visual language (festival neon + deranged chaos)
- Performance optimized for streaming
- Clean modular architecture (components, data assets, interfaces)

## Platform Targets

- **Windows PC** free stream build (itch.io or direct download). First and main target.
- **Xbox Series X|S** later (UE 5.8+ GDK path; requires free ID@Xbox approval for full console).

## Stream / Free Release Goals

- Playable full-UE Windows build with 20–50 levels
- Customizable options exposed
- Dev log / Glass Box style documentation of the process
- Giveaway on stream once the slice is fun

## Tech Notes

- Unreal Engine (prefer 5.8+ for MCP and easier Xbox on PC path)
- Agents for materials, lighting, blueprint iteration, chart generation
- Keep everything data-driven for modularity
- Input: keyboard + gamepad from the start so Xbox/PC controller feels native
