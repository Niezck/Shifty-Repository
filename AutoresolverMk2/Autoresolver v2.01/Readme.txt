When typing in filenames, the '.txt' extension should not be typed.

Input files must be formatted properly or the program simply will not function. For the purposes of inputting, ignore any asterixes.

The first six lines must contain, in order:
*Number of player ships
*Number of AI ships
*Number of player command ships
*Number of AI command ships
*Bonus to player fleet
*Bonus to AI fleet
The format of these six lines must be as follows: [Something] = X. The '[Something] can be absolutely anything you like but it must be followed by an equals sign then a number.

The next two lines must contain, in order:
*Player flee options
*AI flee options (NOT YET IMPLEMENETED)
Flee options are formatted in the following way: [Something]=X/Y/Z. The '[Something] can be absolutely anything you like but it must be followed by an equals sign then the flee options. X is required for all flee options, an entry of 0 indicates no flee option. Y is optional depending on the flee option chosen, as is Z.
Flee options are as follows:
*1 = 50% casualties
*2 = All command ships dead
*3 = 10% chance each round
*4 = Specific ship destroyed. In this case Y must be the number of the ship
*5 = Specific ship reaches specific hull value or below. In this case Y must be the number of the ship and Z the hull value.

The next lines are largely variable but ships must be listed in the following order:
*Player command ships
*Player ships
*AI command ships
*AI ships

Command ship lines must take the following format:
*Ship Name = [Something]:POWER/[Something]:COMMAND/[Something]:HULL
Ship lines must take the following format:
*Ship Name = [Something]:POWER/[Something]:SHIELDMIT/[Something]:SHIELDSTR/[SOMETHING]:HULL

An entry of '1' into the Ship Name section will cause the program to automatically assign the ship a name.