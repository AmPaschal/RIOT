## Setting up a proof for Zephyr

1. Clone the AmPaschal's fork of the Zephyr repository.
1. Create a new branch from the "cbmc_base_manual" branch and review the cbmc directory.
1. Rename the cbmc/proofs/harness_base directory to the name of the function you are harnessing.
1. Rename the function_name_harness.c file to <function_name>_harness.c where <function_name> represents the name of the function you are harnessing.
1. Edit the Makefile in cbmc/proofs/harness_base in line with the function you are harnessing.
1. Use "make" to build the harness.
1. The verification xml files will be in the build/reports subdirectory. Html files in the build/report/html subdirectory.
1. Remember to create commits and Git tags as you work through each stage of harness development.
