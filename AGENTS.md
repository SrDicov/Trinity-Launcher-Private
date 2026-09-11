# AGENTS.md

Qt6/C++17 desktop launcher for Minecraft Bedrock on Linux. Frontend only — game execution needs external `mcpelauncher` binaries.

## Build / run (use these, don't guess)

- First time: `make start` (deps + release build + run). Dev loop: `make run`. Release only: `make build`. Debug: `make debug`.
- Direct equivalent: `./build.sh --release --run` (dev, foreground logs) or `./build.sh --release --run --detached` (background). Binary lands at `build/app/trinity`.
- Deps only: `make deps` / `./build.sh --deps-only`. Clean: `make clean` (also fixes root-owned `build/` perms). Install: `make install` (`/usr/local/bin` + icons, prompts sudo internally).
- Never run `build.sh`/`make` with `sudo` — the script calls `sudo` itself only for deps/install. `CONTRIBUTING.md`'s `qmake` snippet is stale; use CMake/`build.sh`.
- `build.sh` forces `clang++`, `-msse3`, and Ninja when available. Manual configure must match: `cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang` then `cmake --build build --parallel $(nproc)`.
- CI (`.github/workflows/compilar.yml`) is just `./build.sh --deps` then `./build.sh --release` on ubuntu-latest. No tests, linter, or typecheck exist — verify by compiling + running.
- AppImage release: `.github/workflows/anylinux-appimage.yml` (matrix x86_64 + aarch64) runs `sh ./trinity-appimage.sh` inside `ghcr.io/pkgforge-dev/archlinux:latest`. AnyLinux rules: build on Arch only, install everything to `/usr` before deploy, pass binaries as args to `quick-sharun` (never copy `.so` by hand), never use `linuxdeploy`. Legacy Ubuntu+linuxdeploy workflows (`simple-`, `nightly-`, `appimage-arm-`, `qt5-old-`) are superseded — don't copy their `LD_LIBRARY_PATH` AppRun pattern.

## Runtime prerequisite

- `mcpelauncher-client` and `mcpelauncher-extract` must be on `PATH` (built separately from `mcpelauncher-manifest`, `qt6` branch — see `docs/BUILD.md`). Without them the UI runs but launch/extract fails.
- Never delete `~/.local/share/mcpelauncher/` (worlds/saves live there); uninstall preserves it.
- On x86_64, Bedrock >26.33 is unsupported; `TrinityUI` compiles in a `SHOW_X86_64_WARNING` banner (opt out with `-DDISABLE_X86_64_WARNING=ON`).

## Layout

- Entry: `app/src/main.cpp` → `qt_add_executable(trinity)` in `app/CMakeLists.txt`, links `TrinityCore` + `TrinityUI`.
- `src/TrinityLib/core/` + `include/TrinityLib/core/` → static `TrinityCore`: `version_manager`, `game_launcher`, `pack_installer`, `version_config`, `exporter`, `discord_manager`, `color_extractor`.
- `src/TrinityLib/ui/` + `include/TrinityLib/ui/` → static `TrinityUI` (links `TrinityCore` privately): `windows/launcher_window`, `windows/trinito_window`, `dialogs/extract_dialog`, `widgets/version_selector`, `app_helpers`.
- Root `CMakeLists.txt` wires `src/TrinityLib/core` → `src/TrinityLib/ui` → `app` → `src/mini-matugen-j`, then embeds translations. Qt modules: `Core Widgets Concurrent Network LinguistTools`.
- Assets live in `resources/` (`resources.qrc`, `fonts/`, `branding/`, `shortcuts/`, `runtime/`, `i18n/`). Nix (`flake.nix`) and Docker (`Dockerfile`, `compose.yaml`) are alternate envs only; `packaging/` is distro packaging.

## Translations (easy to break)

- Source of truth: `resources/i18n/*.ts` (Spanish `trinity_es.ts` is the base). Update strings with `make translations` / `./build.sh --update-ts` (runs `lupdate src/ include/` + `lrelease`), never hand-edit `.qm` files.
- Adding a language requires 3 touches: new `.ts` file, register in root `CMakeLists.txt` (`qt_standard_project_setup` langs + `TS_FILES`/`QM_FILES`), and add the `.qm` alias under `<qresource prefix="/i18n">` in `resources/resources.qrc`. See `TRANSLATION.md`; keep `%1`-style placeholders and `&` shortcuts intact.

## Conventions

- `camelCase` funcs/vars, `PascalCase` classes, `UPPER_SNAKE_CASE` consts, `snake_case` files, lowercase dirs. Doxygen-comment public functions (`/** ... */`).
- Conventional Commits (`feat:`, `fix:`, `docs:`, `refactor:`, `test:`, `chore:`). Keep diffs minimal — project prioritizes stability over optimization; don't unsolicitedly refactor/optimize.
