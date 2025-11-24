CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -Iincludes

TARGET = zombies

SRC = src/main.cpp src/Zombie.cpp src/newZombie.cpp src/randomChump.cpp
OBJDIR = obj
OBJ = $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(SRC))

.PHONY: all clean fclean re
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all