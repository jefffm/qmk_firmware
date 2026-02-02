# AGENTS.md - QMK Firmware

Guidelines for AI coding agents working in the QMK Firmware repository.

## Build Commands

### Compile Firmware
```bash
# Compile specific keyboard:keymap
make <keyboard>:<keymap>
# Example: make planck/rev6:default

# Compile and flash
make <keyboard>:<keymap>:flash

# Compile all keymaps for a keyboard
make <keyboard>:all
```

### Testing
```bash
# Run all tests
make test:all

# Run specific test
make test:<test_name>
# Example: make test:basic

# List all tests
make list-tests

# Run Python tests
qmk pytest

# Run single Python test file
nose2 -s lib/python/qmk/tests test_cli_commands
```

### Linting and Formatting
```bash
# Format C code (core only)
qmk format-c --core-only -a

# Format Python code
qmk format-python -a

# Format JSON
qmk format-json

# Run linting
qmk lint

# Docker-based formatting (matches CI)
make format-core
make pytest
make format-and-pytest
```

### Cleanup
```bash
make clean          # Remove .build/
make distclean      # Remove .build/ and output files
```

## Code Style Guidelines

### C Code
- **Indentation**: 4 spaces (no tabs)
- **Column limit**: 1000 characters (be reasonable)
- **Braces**: Same line for functions, Allman style for conditionals
- **Pointer alignment**: Right (`int *ptr` not `int* ptr`)
- **Preprocessor**: Indent directives after hash (`#  include`)
- **Functions**: Short functions on single line allowed if empty
- **Comments**: Use `//` for single line, `/* */` for multi-line with copyright headers
- **License**: GPL v2/v3 compatible headers required for new files

### Python Code
- **Formatter**: yapf (configuration in setup.cfg)
- **Indentation**: 4 spaces
- **Column limit**: 256 characters
- **Line length**: 200 max per editorconfig
- **Import style**: Group stdlib, third-party, local; alphabetize within groups
- **Linter**: flake8 (ignores E501, E231 per setup.cfg)
- **Naming**: snake_case for functions/variables, PascalCase for classes

### File Organization
- **Headers**: Use `#pragma once` instead of include guards
- **Includes**: Sort not required (clang-format: SortIncludes: false)
- **Keyboards**: Place in `keyboards/<vendor>/<keyboard>/`
- **Keymaps**: Place in `keyboards/<keyboard>/keymaps/<name>/`
- **Tests**: C tests in `tests/<feature>/`, Python tests in `lib/python/qmk/tests/`

### Naming Conventions
- **C**: snake_case for functions/variables, UPPER_CASE for macros
- **Python**: snake_case for functions/variables, PascalCase for classes
- **Keyboard folders**: lowercase with underscores
- **Keymaps**: lowercase, descriptive names

### Error Handling
- **C**: Return error codes, use `dprint()` for debug output
- **Python**: Raise appropriate exceptions, use `cli.log.error()` for CLI

## Project Structure

```
keyboards/          # Keyboard definitions
quantum/           # Core firmware code
tests/             # C unit tests (Google Test)
lib/python/qmk/    # Python CLI and utilities
platforms/         # Platform-specific code (AVR, ARM, etc.)
drivers/           # Hardware drivers
docs/              # Documentation
```

## Important Notes

- Never commit secrets or API keys
- Run tests before submitting changes
- Follow existing code patterns in the same file
- Check `.editorconfig` for file-type specific settings
- Use `qmk` CLI for most operations instead of direct make
- Test names cannot contain hyphens (use underscores)
- Submodules: Run `qmk git-submodule` to sync

## Documentation

- Full docs at https://docs.qmk.fm
- Use VitePress for documentation preview
- Follow the PR template when submitting changes
