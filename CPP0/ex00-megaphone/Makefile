CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

TARGET = megaphone

SRC = megaphone.cpp
OBJDIR = obj
OBJ = $(OBJDIR)/megaphone.o

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)
