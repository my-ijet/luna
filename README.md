# luna

Luna is a better Lua

## Build

```bash
# Initialize and build
./prepare.sh
cmake --build build/debug
cmake --build build/release

# Or manually with presets
cmake --preset debug && cmake --build build/debug
cmake --preset release && cmake --build build/release
```

## Run

```bash
./build/debug/luna
./build/release/luna
```
