mdump2qlay

Converts mdump files (from Q-emulator author) to QLAY format for use in the MiST FPGA QL core.

The mdump format is used to image a microdrive as accurately as possible. It may contain
multiple copies of a single sector.

mdump2qlay converts the mdump file to QLAY format to produce a clone that retains the original
image copy at sector level hence it retains any copy protection.

mdump2qlay will detect and fix any missing block information from the mdump file. This is
not a problem for mdump files but QLAY requires this information to be accurate.
