# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

TARGET = phonebook

SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJDIR = obj
OBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))

.PHONY: all clean
all: $(TARGET)

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
