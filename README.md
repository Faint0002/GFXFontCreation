# GFXFontCreation
This is a tool that creates GFx scaleformd with an imported TrueType font
# What is a GFx?
A GFx is a file format. It is a modified swf scaleform formwt, with its key differences using elements from a tool by NVidia (Copyright 2007)
It's used by multiple game engines such as R.A.G.Engine and an older Call of Duty engine
# What is this used for?
This is used by Rockstar Games for scaleforms. It's primary use is fonts.
# Why was this made?
It was made for research purposes. I used it for custom fonts in Grand Theft Auto V and Red Dead Redemption 2
# Where are the files?
The files do not exist, they will not be provided out of security risks.
It uses swfmill and gfxexporter.
Swfmill can be found at https://www.swfmill.org/releases/
GFxExporter is a private tool I made reverse engineering Rockstars font loader and allocation system.
You can find a similar tool with the same functionality here: https://www.swfmill.org/releases/
# How do I use this?
This is a command line based tool. The useage is the following:
gfxfontcreation [filename].ttf [fontId]
EX: GFxFontCreation.exe example-font.ttf Example
# Are other font types supported?
No. They are not currently supported.
Swfmill would have to be modified and changed with support to both read the font type and properly inport said font type