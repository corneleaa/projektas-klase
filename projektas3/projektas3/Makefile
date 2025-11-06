# Kompiliatorius ir nustatymai
CXX = g++
STD = -std=c++17
WARN = -Wall
SRC = main.cpp studentas.cpp
OBJ = $(SRC:.cpp=.o)

# Numatytoji programa
TARGET = projektas

# Pagal nutylėjimą: kompiliuoja su -O2
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(STD) $(WARN) -O2 -o $(TARGET) $(OBJ)

%.o: %.cpp studentas.h mediana.h
	$(CXX) $(STD) $(WARN) -O2 -c $< -o $@

O1:
	$(CXX) $(STD) $(WARN) -O1 -o progO1 $(SRC)

O2:
	$(CXX) $(STD) $(WARN) -O2 -o progO2 $(SRC)

O3:
	$(CXX) $(STD) $(WARN) -O3 -o progO3 $(SRC)


run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET) progO1 progO2 progO3

