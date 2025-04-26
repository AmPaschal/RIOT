# name of your application
APPLICATION = cord_lc_repro

# If no BOARD is found in the environment, use this default:
BOARD ?= native

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../..

# Add all the required modules
USEMODULE += cord_lc
USEMODULE += gnrc_ipv6_default

# Disable warnings
WERROR ?= 0

# Show compile commands
QUIET ?= 0

# Use LLVM

TOOLCHAIN ?= llvm

# Enable address sanitizer

CFLAGS += -fsanitize=address
CFLAGS += -fno-omit-frame-pointer

LINKFLAGS += -fsanitize=address
LINKFLAGS += -fno-omit-frame-pointer

include $(RIOTBASE)/Makefile.include
