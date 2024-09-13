# Define the compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = agent-suid
INSTALL_PATH = /usr/local/bin

# Default target for compiling the program
all: $(TARGET)
	@echo "Compiling the program..."

# Rule to compile the C program (suppress command output with @)
$(TARGET): main.c
	@$(CC) $(CFLAGS) -o $(TARGET) main.c

# Rule to install the compiled binary to /usr/local/bin, print success message, and clean up
install: $(TARGET)
	@echo "Installing $(TARGET) to $(INSTALL_PATH)..."
	@install -m 0755 $(TARGET) $(INSTALL_PATH)
	@echo "$(TARGET) installed successfully."
	@$(MAKE) clean  # Clean up after installation

# Rule to uninstall the binary from /usr/local/bin
uninstall:
	@echo "Uninstalling $(TARGET) from $(INSTALL_PATH)..."
	@rm -f $(INSTALL_PATH)/$(TARGET)
	@echo "$(TARGET) uninstalled successfully."

# Rule to clean up compiled files
clean:
	@echo "Cleaning up..."
	@rm -f $(TARGET)
	@echo "Clean up complete."

.PHONY: all install uninstall clean


