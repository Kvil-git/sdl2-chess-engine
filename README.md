# SDL Chess Engine

##### A modular chess engine and GUI built with C++, SDL2, and modern chess programming techniques. Designed to support multiple interface modes and playing options.  
### Features
##### ✅ Implemented
```
    Bitboard-based board representation with efficient piece positioning

    Magic bitboard move generation for sliding pieces (rooks, bishops, queens)

    Complete move generation for all piece types including special moves (castling, en passant)

    SDL2-based 2D graphical interface with piece rendering

    Multiple GUI components with interface abstractions

    Modular architecture separating engine, GUI, and core functionality

    CMake build system with testing support (Google Test)

    FEN string parsing for position setup

    Basic position evaluation (material counting)
```
##### 🚧 In Progress
```
    Game management system (partially implementated)

    Move input handling for different interface types

    3D rendering interface (initial math libraries implemented)

    Console-based interface
```

##### 📋 Planned Features
```
    Complete chess rule implementation (check, checkmate, stalemate)

    Advanced evaluation function (positional scoring, piece activity)

    Search algorithm (minimax with alpha-beta pruning)

    UCI protocol implementation for engine compatibility

    Lichess bot integration

    3D chess visualization

    Game analysis mode

    PGN import/export

    Time control management

    Opening book support

    Endgame tablebase support
```

##### Project Structure
```
sdl chess engine/
├── Assets/                 # Piece images and resources
├── Core/                  # Game management and control
├── Engine/               # Chess engine core
│   ├── Board/            # Board representation
│   ├── MoveGenerator/    # Move generation logic
│   └── PositionEvaluation/ # Evaluation functions
├── Enums/               # Type definitions
├── Functions/           # Utility functions
├── GUI/                # User interface components
│   ├── GUIComponents/   # Renderers and input handlers
│   └── GUITypes/        # Interface variations
├── Math/               # 3D math utilities
├── Structs/            # Data structures
└── Tests/              # Unit tests
```

#### Building
##### Dependencies
```
    CMake (3.12+)

    SDL2

    SDL2_image

    Google Test (for tests)
```

#### Build Instructions
```bash

mkdir build && cd build
cmake ..
make
```
##### Targets
```
    SdlChessEngine: Main application

    EngineTests: Unit tests for move generation
```
##### Usage

###### Run the main executable:
```bash

./build/SdlChessEngine

Run tests:
bash

./build/EngineTests
```

##### Credits
```
    2D chess set: JohnPablok's improved Cburnett chess set
```

##### License
###### This project is provided for educational and personal use. Please respect the attribution requirements for the included assets.

##### Contributing
###### This is a personal project with a focus on learning chess programming concepts and creating a modular, extensible architecture. So no contributing =)
