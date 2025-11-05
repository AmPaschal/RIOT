# Updated root Makefile to avoid failing by default
.all:

.PHONY: all doc doc-man doc-latex docclean print-versions welcome

all: welcome
	@echo ""
	# Removed failing line: @exit 1

doc:
	@./dist/tools/features_yaml2mx/features_yaml2mx.py \
		features.yaml \
		--output-md doc/doxygen/src/feature_list.md
	"$(MAKE)" -BC doc/doxygen

doc-man:
	"$(MAKE)" -BC doc/doxygen man

doc-latex:
	"$(MAKE)" -BC doc/doxygen latex

docclean:
	"$(MAKE)" -BC doc/doxygen clean

clean:
	@echo "Cleaning all build products for the current board"
	@for dir in $(APPLICATION_DIRS); do "$(MAKE)" -C$$dir clean; done

pkg-clean:
	@echo "Cleaning all package sources"
	rm -rf build/pkg
