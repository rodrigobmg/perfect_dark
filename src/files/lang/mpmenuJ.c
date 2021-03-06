#include <ultra64.h>

char *lang[] = {
	/*0x00*/ "Most Suicidal\n",
	/*0x01*/ "Who Needs Ammo?\n",
	/*0x02*/ "Who Needs Armor?\n",
	/*0x03*/ "Best Protected\n",
	/*0x04*/ "Marksmanship\n",
	/*0x05*/ "Most Professional\n",
	/*0x06*/ "Most Deadly\n",
	/*0x07*/ "Most Harmless\n",
	/*0x08*/ "Most Cowardly\n",
	/*0x09*/ "Most Frantic\n",
	/*0x0a*/ "Most Honorable\n",
	/*0x0b*/ "Most Dishonorable\n",
	/*0x0c*/ "Shortest Life\n",
	/*0x0d*/ "Longest Life\n",
	/*0x0e*/ "Double Kill\n",
	/*0x0f*/ "Triple Kill\n",
	/*0x10*/ "Quad Kill\n",
	/*0x11*/ "Game Setup\n",
	/*0x12*/ "Load Settings\n",
	/*0x13*/ "Scenario\n",
	/*0x14*/ "Arena\n",
	/*0x15*/ "Options\n",
	/*0x16*/ "Teams\n",
	/*0x17*/ "Weapons\n",
	/*0x18*/ "Limits\n",
	/*0x19*/ "Simulants\n",
	/*0x1a*/ "Save Settings\n",
	/*0x1b*/ "Abort Game\n",
	/*0x1c*/ "Player Setup\n",
	/*0x1d*/ "Load Player\n",
	/*0x1e*/ "Name\n",
	/*0x1f*/ "Character\n",
	/*0x20*/ "Handicap\n",
	/*0x21*/ "Control\n",
	/*0x22*/ "Player Options\n",
	/*0x23*/ "Statistics\n",
	/*0x24*/ "Start Game\n",
	/*0x25*/ "Drop Out\n",
	/*0x26*/ "Save Player\n",
	/*0x27*/ "Save Copy Of Player\n",
	/*0x28*/ "Stuff\n",
	/*0x29*/ "Soundtrack\n",
	/*0x2a*/ "Team Names\n",
	/*0x2b*/ "Ratio\n",
	/*0x2c*/ "Lock\n",
	/*0x2d*/ "None\n",
	/*0x2e*/ "Last Winner\n",
	/*0x2f*/ "Last Loser\n",
	/*0x30*/ "Random\n",
	/*0x31*/ "Challenge\n",
	/*0x32*/ "Combat Challenges\n",
	/*0x33*/ "Abort Challenge\n",
	/*0x34*/ "Abort\n",
	/*0x35*/ "Are you sure you want\nto abort the game?\n",
	/*0x36*/ "Abort\n",
	/*0x37*/ "Cancel\n",
	/*0x38*/ "%s Overview\n",
	/*0x39*/ "Accept\n",
	/*0x3a*/ "Cancel\n",
	/*0x3b*/ "Team Names\n",
	/*0x3c*/ "Back\n",
	/*0x3d*/ "Change Team Name\n",
	/*0x3e*/ "Soundtrack\n",
	/*0x3f*/ "Current:\n",
	/*0x40*/ "Multiple Tunes\n",
	/*0x41*/ "Back\n",
	/*0x42*/ "Multiple Tunes\n",
	/*0x43*/ "Random\n",
	/*0x44*/ "Select Tunes\n",
	/*0x45*/ "Select Tune\n",
	/*0x46*/ "Team Control\n",
	/*0x47*/ "Teams Enabled\n",
	/*0x48*/ "Teams:\n",
	/*0x49*/ "Auto Team...\n",
	/*0x4a*/ "Back\n",
	/*0x4b*/ "Auto Team\n",
	/*0x4c*/ "Two Teams\n",
	/*0x4d*/ "Three Teams\n",
	/*0x4e*/ "Four Teams\n",
	/*0x4f*/ "Maximum Teams\n",
	/*0x50*/ "Humans vs Simulants\n",
	/*0x51*/ "Human-Simulant Pairs\n",
	/*0x52*/ "Cancel\n",
	/*0x53*/ "Simulants\n",
	/*0x54*/ "Add Simulant...\n",
	/*0x55*/ "1:\n",
	/*0x56*/ "2:\n",
	/*0x57*/ "3:\n",
	/*0x58*/ "4:\n",
	/*0x59*/ "5:\n",
	/*0x5a*/ "6:\n",
	/*0x5b*/ "7:\n",
	/*0x5c*/ "8:\n",
	/*0x5d*/ "Clear All\n",
	/*0x5e*/ "Back\n",
	/*0x5f*/ "Difficulty:\n",
	/*0x60*/ "Change Type...\n",
	/*0x61*/ "Character...\n",
	/*0x62*/ "Delete Simulant\n",
	/*0x63*/ "Back\n",
	/*0x64*/ "Simulant Character\n",
	/*0x65*/ "Add Simulant\n",
	/*0x66*/ "Change Simulant\n",
	/*0x67*/ "Normal Simulants\n",
	/*0x68*/ "Special Simulants\n",
	/*0x69*/ "Ready!\n",
	/*0x6a*/ "...and waiting\n",
	/*0x6b*/ "Limits\n",
	/*0x6c*/ "Time\n",
	/*0x6d*/ "Score\n",
	/*0x6e*/ "Restore Defaults\n",
	/*0x6f*/ "Back\n",
	/*0x70*/ "No Limit\n",
	/*0x71*/ "%d\n",
	/*0x72*/ "%d Min\n",
	/*0x73*/ "Arena\n",
	/*0x74*/ "Dark\n",
	/*0x75*/ "Golden\n",
	/*0x76*/ "Random\n",
	/*0x77*/ "Skedar",
	/*0x78*/ "Pipes",
	/*0x79*/ "Ravine",
	/*0x7a*/ "G5 Building",
	/*0x7b*/ "Sewers",
	/*0x7c*/ "Warehouse",
	/*0x7d*/ "Matrix",
	/*0x7e*/ "Ruins",
	/*0x7f*/ "Area 52",
	/*0x80*/ "Base",
	/*0x81*/ "Rooftop",
	/*0x82*/ "Fortress",
	/*0x83*/ "Villa",
	/*0x84*/ "Car Parking Lot",
	/*0x85*/ "Temple",
	/*0x86*/ "Complex",
	/*0x87*/ "Felicity",
	/*0x88*/ "Random",
	/*0x89*/ "Load Player\n",
	/*0x8a*/ "<B> to cancel\n",
	/*0x8b*/ "Load Game Settings\n",
	/*0x8c*/ "%s:  Scenario: %s   Arena: %s    Simulants: %d",
	/*0x8d*/ "Presets\n",
	/*0x8e*/ "Player Name\n",
	/*0x8f*/ "Character\n",
	/*0x90*/ "Load Head...\n",
	/*0x91*/ "Statistics\n",
	/*0x92*/ "Kills:\n",
	/*0x93*/ "Deaths:\n",
	/*0x94*/ "Accuracy:\n",
	/*0x95*/ "Head Shots:\n",
	/*0x96*/ "Ammo Used:\n",
	/*0x97*/ "Damage Dealt:\n",
	/*0x98*/ "Pain Received:\n",
	/*0x99*/ "Games Played:\n",
	/*0x9a*/ "Games Won:\n",
	/*0x9b*/ "Games Lost:\n",
	/*0x9c*/ "Time Spent:\n",
	/*0x9d*/ "Distance:\n",
	/*0x9e*/ "Medals Won:\n",
	/*0x9f*/ "   Accuracy:\n",
	/*0xa0*/ "   Head Shot:\n",
	/*0xa1*/ "   KillMaster:\n",
	/*0xa2*/ "   Survivor:\n",
	/*0xa3*/ "Your Title:\n",
	/*0xa4*/ "Back\n",
	/*0xa5*/ "Completed Challenges\n",
	/*0xa6*/ "Back\n",
	/*0xa7*/ "Options\n",
	/*0xa8*/ "Highlight Pickups\n",
	/*0xa9*/ "Highlight Players\n",
	/*0xaa*/ "Highlight Teams\n",
	/*0xab*/ "Radar\n",
	/*0xac*/ "Back\n",
	/*0xad*/ "Weapons\n",
	/*0xae*/ "Set:\n",
	/*0xaf*/ "Current Weapon Setup:\n",
	/*0xb0*/ "1:\n",
	/*0xb1*/ "2:\n",
	/*0xb2*/ "3:\n",
	/*0xb3*/ "4:\n",
	/*0xb4*/ "5:\n",
	/*0xb5*/ "6:\n",
	/*0xb6*/ "Back\n",
	/*0xb7*/ "Save Game Setup\n",
	/*0xb8*/ "Do you want to save over\nyour original game file?\n",
	/*0xb9*/ "Save Over Original\n",
	/*0xba*/ "Save Copy\n",
	/*0xbb*/ "Do Not Save\n",
	/*0xbc*/ "Game File Name\n",
	/*0xbd*/ "Enter a name for your\ngame setup file:\n",
	/*0xbe*/ "Confirm\n",
	/*0xbf*/ "Your player file is\nalways saved\nautomatically.\n",
	/*0xc0*/ "Save a copy now?\n",
	/*0xc1*/ "No\n",
	/*0xc2*/ "Yes\n",
	/*0xc3*/ "Drop out\n",
	/*0xc4*/ "Are you sure you\nwant to drop out?\n",
	/*0xc5*/ "Drop Out\n",
	/*0xc6*/ "Cancel\n",
	/*0xc7*/ "Control\n",
	/*0xc8*/ "Control Style\n",
	/*0xc9*/ "Reverse Pitch\n",
	/*0xca*/ "Look Ahead\n",
	/*0xcb*/ "Head Roll\n",
	/*0xcc*/ "Auto-Aim\n",
	/*0xcd*/ "Aim Control\n",
	/*0xce*/ "Sight On Screen\n",
	/*0xcf*/ "Show Target\n",
	/*0xd0*/ "Zoom Range\n",
	/*0xd1*/ "Ammo On Screen\n",
	/*0xd2*/ "Gun Function\n",
	/*0xd3*/ "Paintball\n",
	/*0xd4*/ "Back\n",
	/*0xd5*/ "Hold\n",
	/*0xd6*/ "Toggle\n",
	/*0xd7*/ "Combat Options\n",
	/*0xd8*/ "Briefcase Options\n",
	/*0xd9*/ "Hacking Options\n",
	/*0xda*/ "Pop A Cap Options\n",
	/*0xdb*/ "Hill Options\n",
	/*0xdc*/ "Flags Options\n",
	/*0xdd*/ "Boxes Options\n",
	/*0xde*/ "One-Hit Kills\n",
	/*0xdf*/ "Slow Motion\n",
	/*0xe0*/ "Fast Movement\n",
	/*0xe1*/ "Display Team\n",
	/*0xe2*/ "No Radar\n",
	/*0xe3*/ "No Auto-Aim\n",
	/*0xe4*/ "No Player Highlight\n",
	/*0xe5*/ "No Pickup Highlight\n",
	/*0xe6*/ "Highlight Target\n",
	/*0xe7*/ "Highlight Mac\n",
	/*0xe8*/ "Boxes on Radar\n",
	/*0xe9*/ "Hill on Radar\n",
	/*0xea*/ "Mobile Hill\n",
	/*0xeb*/ "Time\n",
	/*0xec*/ "Flags on Radar\n",
	/*0xed*/ "Highlight Briefcase\n",
	/*0xee*/ "Show on Radar\n",
	/*0xef*/ "Back\n",
	/*0xf0*/ "Off\n",
	/*0xf1*/ "On\n",
	/*0xf2*/ "Smart\n",
	/*0xf3*/ "Scenario\n",
	/*0xf4*/ "Free for All!\n",
	/*0xf5*/ "-Teamwork-\n",
	/*0xf6*/ "Combat",
	/*0xf7*/ "Capture The Briefcase",
	/*0xf8*/ "Hack That Mac",
	/*0xf9*/ "Pop A Cap",
	/*0xfa*/ "King Of The Hill",
	/*0xfb*/ "Capture The Flag",
	/*0xfc*/ "Touch That Box",
	/*0xfd*/ "Combat",
	/*0xfe*/ "Briefcase",
	/*0xff*/ "Hack",
	/*0x100*/ "Pop",
	/*0x101*/ "Hill",
	/*0x102*/ "Flags",
	/*0x103*/ "Boxes",
	/*0x104*/ "Game Over\n",
	/*0x105*/ "Title:\n",
	/*0x106*/ "Weapon of Choice:\n",
	/*0x107*/ "Awards:\n",
	/*0x108*/ "1st\n",
	/*0x109*/ "2nd\n",
	/*0x10a*/ "3rd\n",
	/*0x10b*/ "4th\n",
	/*0x10c*/ "5th\n",
	/*0x10d*/ "6th\n",
	/*0x10e*/ "7th\n",
	/*0x10f*/ "8th\n",
	/*0x110*/ "9th\n",
	/*0x111*/ "10th\n",
	/*0x112*/ "11th\n",
	/*0x113*/ "12th\n",
	/*0x114*/ "Player Ranking\n",
	/*0x115*/ "Deaths\n",
	/*0x116*/ "Score\n",
	/*0x117*/ "Team Ranking\n",
	/*0x118*/ "Stats for %s",
	/*0x119*/ "Deaths\n",
	/*0x11a*/ "Kills\n",
	/*0x11b*/ "Inventory\n",
	/*0x11c*/ "Control\n",
	/*0x11d*/ "Game Time:\n",
	/*0x11e*/ "End Game\n",
	/*0x11f*/ "Pause\n",
	/*0x120*/ "Unpause\n",
	/*0x121*/ "End Game\n",
	/*0x122*/ "Are you sure?\n",
	/*0x123*/ "Cancel\n",
	/*0x124*/ "End Game\n",
	/*0x125*/ "PerfectHead\n",
	/*0x126*/ "Load A Saved Head\n",
	/*0x127*/ "Make A New Head\n",
	/*0x128*/ "Edit A Loaded Head\n",
	/*0x129*/ "Edit A PerfectHead\n",
	/*0x12a*/ "Choose slot to edit:\n",
	/*0x12b*/ "Cancel\n",
	/*0x12c*/ "Make A New Head\n",
	/*0x12d*/ "Load A Saved Head\n",
	/*0x12e*/ "Where do you want to be able\n",
	/*0x12f*/ "to use this head?\n",
	/*0x130*/ "Combat Simulator\n",
	/*0x131*/ "All Missions\n",
	/*0x132*/ "Both\n",
	/*0x133*/ "Cancel\n",
	/*0x134*/ "Camera Set-Up\n",
	/*0x135*/ "Insert your camera into your\n",
	/*0x136*/ "Game Boy Pak.\n",
	/*0x137*/ "Then, Insert your Game Boy Pak\n",
	/*0x138*/ "into any controller.\n",
	/*0x139*/ "OK\n",
	/*0x13a*/ "Cancel\n",
	/*0x13b*/ "Error\n",
	/*0x13c*/ "Game Boy Camera Not Detected!\n",
	/*0x13d*/ "Please check all connections\n",
	/*0x13e*/ "and try again.\n",
	/*0x13f*/ "Cancel\n",
	/*0x140*/ "Choose Camera\n",
	/*0x141*/ "More than one camera detected.\n",
	/*0x142*/ "Please select which camera you\nwant to use\n",
	/*0x143*/ "OK\n",
	/*0x144*/ "Cancel\n",
	/*0x145*/ "PerfectHead\n",
	/*0x146*/ "Take A Picture Now\n",
	/*0x147*/ "Load Picture From Camera\n",
	/*0x148*/ "Cancel\n",
	/*0x149*/ "Load From Camera\n",
	/*0x14a*/ "Choose picture to read from camera:\n",
	/*0x14b*/ "Cancel\n",
	/*0x14c*/ "Take Picture\n",
	/*0x14d*/ "Shoot!\n",
	/*0x14e*/ "Cancel\n",
	/*0x14f*/ "Keep Picture\n",
	/*0x150*/ "Try Again\n",
	/*0x151*/ "Load PerfectHead\n",
	/*0x152*/ "Insert the Controller Pak\n",
	/*0x153*/ "containing the head you\n",
	/*0x154*/ "wish to load into any\n",
	/*0x155*/ "controller.\n",
	/*0x156*/ "Controller Pak:\n",
	/*0x157*/ "Cancel\n",
	/*0x158*/ "Source:\n",
	/*0x159*/ "Pak 1",
	/*0x15a*/ "Pak 2",
	/*0x15b*/ "Pak 3",
	/*0x15c*/ "Pak 4",
	/*0x15d*/ "<none>",
	/*0x15e*/ "PerfectHead Editor\n",
	/*0x15f*/ "Take Another Picture\n",
	/*0x160*/ "Change Head\n",
	/*0x161*/ "Position Picture\n",
	/*0x162*/ "Color Face & Hair\n",
	/*0x163*/ "Shape Head\n",
	/*0x164*/ "Remove Head\n",
	/*0x165*/ "Cancel Changes\n",
	/*0x166*/ "Keep Changes\n",
	/*0x167*/ "Shape Head\n",
	/*0x168*/ "Depth\n",
	/*0x169*/ "OK\n",
	/*0x16a*/ "Cancel\n",
	/*0x16b*/ "Position Image\n",
	/*0x16c*/ "Brightness\n",
	/*0x16d*/ "OK\n",
	/*0x16e*/ "Cancel\n",
	/*0x16f*/ "Choose Head\n",
	/*0x170*/ "OK\n",
	/*0x171*/ "Cancel\n",
	/*0x172*/ "Remove PerfectHead\n",
	/*0x173*/ "Are you sure you want to\n",
	/*0x174*/ "remove this head from memory?\n",
	/*0x175*/ "Delete\n",
	/*0x176*/ "Cancel\n",
	/*0x177*/ "Cancel Changes\n",
	/*0x178*/ "Are you sure you want to\n",
	/*0x179*/ "throw away your changes?\n",
	/*0x17a*/ "Throw Away\n",
	/*0x17b*/ "Go Back To Editor\n",
	/*0x17c*/ "Save PerfectHead\n",
	/*0x17d*/ "You have edited this head.\n",
	/*0x17e*/ "Do you want to keep your changes?\n",
	/*0x17f*/ "Keep\n",
	/*0x180*/ "Revert\n",
	/*0x181*/ "Save PerfectHead\n",
	/*0x182*/ "Your changes will be kept in memory.\n",
	/*0x183*/ "Would you like to save your changes\n",
	/*0x184*/ "to the controller pak?\n",
	/*0x185*/ "Save\n",
	/*0x186*/ "Don't Save\n",
	/*0x187*/ "Save PerfectHead\n",
	/*0x188*/ "You can now save your head on to\n",
	/*0x189*/ "a controller pak if you wish.\n",
	/*0x18a*/ "If you want to do this, please\n",
	/*0x18b*/ "ensure a controller pak is inserted\n",
	/*0x18c*/ "and choose \"Save\".\n",
	/*0x18d*/ "Save\n",
	/*0x18e*/ "Don't Save\n",
	/*0x18f*/ "Head Complete!\n",
	/*0x190*/ "To use your head in the combat simulator,\n",
	/*0x191*/ "select the head from the character menu\n",
	/*0x192*/ "of the player/simulant settings menu.\n",
	/*0x193*/ "Your Mission heads will now appear\n",
	/*0x194*/ "in any of the missions you play.\n",
	/*0x195*/ "You can now edit your head further if you wish.\n",
	/*0x196*/ "Finish\n",
	/*0x197*/ "Edit Head\n",
	/*0x198*/ "Head Color\n",
	/*0x199*/ "Face:\n",
	/*0x19a*/ "Hairstyle:\n",
	/*0x19b*/ "OK\n",
	/*0x19c*/ "Cancel\n",
	/*0x19d*/ "Press B to Go Back\n",
	/*0x19e*/ "Hangar Information\n",
	/*0x19f*/ "Hologram Training Programs\n",
	/*0x1a0*/ "Device List\n",
	/*0x1a1*/ "Information\n",
	/*0x1a2*/ "Locations\n",
	/*0x1a3*/ "Vehicles\n",
	/*0x1a4*/ "Character Profiles\n",
	/*0x1a5*/ "Other Information\n",
	/*0x1a6*/ "Training Stats\n",
	/*0x1a7*/ "Time Taken:\n",
	/*0x1a8*/ "Completed!\n",
	/*0x1a9*/ "Failed!\n",
	/*0x1aa*/ "Ok\n",
	/*0x1ab*/ "Resume\n",
	/*0x1ac*/ "Cancel\n",
	/*0x1ad*/ "Abort\n",
	/*0x1ae*/ "Character Profile\n",
	/*0x1af*/ "Name:\n",
	/*0x1b0*/ "Age:\n",
	/*0x1b1*/ "Race:\n",
	/*0x1b2*/ "Press B to Go Back\n",
	/*0x1b3*/ "Cheats\n",
	/*0x1b4*/ "It is now safe to turn off your computer\n",
	/*0x1b5*/ "Cancel\n",
	/*0x1b6*/ "Bronze\n",
	/*0x1b7*/ "Silver\n",
	/*0x1b8*/ "Gold\n",
	/*0x1b9*/ "Difficulty\n",
	/*0x1ba*/ "Difficulty:\n",
	/*0x1bb*/ "Select Difficulty:\n",
	/*0x1bc*/ "   \n",
	/*0x1bd*/ "Weapon\n",
	/*0x1be*/ "Training Info\n",
	/*0x1bf*/ "Training Stats\n",
	/*0x1c0*/ "Completed!\n",
	/*0x1c1*/ "Score:\n",
	/*0x1c2*/ "Targets Destroyed:\n",
	/*0x1c3*/ "Difficulty:\n",
	/*0x1c4*/ "Time Taken:\n",
	/*0x1c5*/ "Weapon:\n",
	/*0x1c6*/ "Accuracy:\n",
	/*0x1c7*/ "Not Failed\n",
	/*0x1c8*/ "Out of Ammo\n",
	/*0x1c9*/ "Time Over\n",
	/*0x1ca*/ "Score Unattainable\n",
	/*0x1cb*/ "Too Inaccurate\n",
	/*0x1cc*/ "Bullseye\n",
	/*0x1cd*/ "Zone 1\n",
	/*0x1ce*/ "Zone 2\n",
	/*0x1cf*/ "Zone 3\n",
	/*0x1d0*/ "Hit total\n",
	/*0x1d1*/ "Scoring\n",
	/*0x1d2*/ "10\n",
	/*0x1d3*/ "5\n",
	/*0x1d4*/ "2\n",
	/*0x1d5*/ "1\n",
	/*0x1d6*/ "Ammo Limit:\n",
	/*0x1d7*/ "Time Limit:\n",
	/*0x1d8*/ "Min Accuracy:\n",
	/*0x1d9*/ "Goal Targets:\n",
	/*0x1da*/ "Goal Score:\n",
	/*0x1db*/ "Cheats\n",
	/*0x1dc*/ "Done\n",
	/*0x1dd*/ "Warning\n",
	/*0x1de*/ "If you activate any cheats, then you\nwill be unable to progress further in the game\nwhile those cheats are active.\n",
	/*0x1df*/ "OK\n",
	/*0x1e0*/ "Cancel\n",
	/*0x1e1*/ "Player %d: ",
	/*0x1e2*/ "Press Start!\n",
	/*0x1e3*/ "Searching for Camera!\n",
	/*0x1e4*/ "Calibrating Camera\n",
	/*0x1e5*/ "Downloading Image\n",
	/*0x1e6*/ "Loading Image\n",
	/*0x1e7*/ "Saving Image\n",
	/*0x1e8*/ "Transfering Image\n",
	/*0x1e9*/ "Uploading Segment\n",
	/*0x1ea*/ "Initialising Pak\n",
	/*0x1eb*/ "Getting PerfectHead\n",
	/*0x1ec*/ "Saving PerfectHead\n",
	/*0x1ed*/ "Auto Camera Adjustment\n",
	/*0x1ee*/ "Please Wait...\n",
	/*0x1ef*/ NULL,
};
