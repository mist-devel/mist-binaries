mdvtool
=======

The MIST QL core primarily uses microdrive images in QLAY format. Unfortunately
this is not the primary format of QL files available in the net. Many are in
ZIP format instead and must be unpacked on the QL itself to corectly deal 
with special header flags.

Thus mdvtool was written.

It can be used to erase all data from a given MDV image and to write the 
contents of a ZIP file instead. Example:

mdvtool GamesCart.mdv erase name Gunner zip_import gunner.zip write gunner.mdv

This reads the GamesCart.mdv images, erases it. Sets it's name to "Gunner",
imports all files from the ZIP archive gunner.zip and writes the updated
mdv images back to disk under the name gunner.mdv

The resulting image can then be used with the MIST QL core ...
