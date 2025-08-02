
g++ -std=c++17 -O2 \
    src/main.cpp \
    src/inputManager.cpp \
    src/gameManager.cpp \
    -o engine \
    -lsfml-graphics -lsfml-window -lsfml-system
