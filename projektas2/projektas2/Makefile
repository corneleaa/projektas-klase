# Kompiliatorius ir nustatymai
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
TARGET = projektas

# Failų sąrašas
SRC = main.cpp studentas.cpp
OBJ = $(SRC:.cpp=.o)

# Numatyta komanda 
all: $(TARGET)

# Kompiliavimas
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Objektinių failų kūrimas
%.o: %.cpp studentas.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

#  paleisti programą
run: $(TARGET)
	./$(TARGET)

#Isvalyti objektinius failus
clean:
	rm -f $(OBJ) $(TARGET)

