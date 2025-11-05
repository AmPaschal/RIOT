# Defines the root of the project.
# Be aware of how many directories deep you go!

# The value of root changes project by project but for now I'll have it be the static RIOT path
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/uri_parser/uri_parser.c \
       $(ROOT)/sys/fmt/fmt.c

# Harness to utilize, omit the extension!
H_ENTRY = uri_parser_process

# Extra CBMC flags to be passed during CBMC analysis
# Keep a small global unwind but increase specific loop unwinds needed for port parsing
H_CBMCFLAGS = --nondet-static --unwind 2 \
              --unwindset _consume_port.0:4,_consume_port.1:5,scn_u32_dec.0:5,_strchrb.0:32

# Env vars
H_DEF = 

# Include paths (no additions needed beyond these)
H_INC = -I$(ROOT) \
        -I$(ROOT)/sys/include/  \
        -I$(ROOT)/core/lib/include/  \
        -I$(ROOT)/core/include/  \
        -I$(ROOT)/cpu/native/include/  \
        -I$(ROOT)/drivers/include/

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include

# Override the report target to avoid permission issues with build/report
report: cbmc.xml property.xml coverage.xml
	@rm -rf build/report_alt
	$(VIEWER) \
	 --goto build/$(ENTRY).goto \
	 --srcdir $(ROOT) \
	 --reportdir build/report_alt \
	 --result build/reports/cbmc.xml \
	 --property build/reports/property.xml \
	 --coverage build/reports/coverage.xml
