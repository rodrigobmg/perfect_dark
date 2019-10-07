#include <ultra64.h>

char *lang[] = {
	/*0x00*/ "Invincible",
	/*0x01*/ "All Guns",
	/*0x02*/ "Super x2 Health",
	/*0x03*/ "Super x2 Armor",
	/*0x04*/ "Bond Invisible",
	/*0x05*/ "Bond Phase",
	/*0x06*/ "Infinite Ammo",
	/*0x07*/ "DK Mode",
	/*0x08*/ "Tiny Bond",
	/*0x09*/ "Super x10 Health",
	/*0x0a*/ "Magnum",
	/*0x0b*/ "Laser",
	/*0x0c*/ "Golden Gun",
	/*0x0d*/ "Silver PP7",
	/*0x0e*/ "Gold PP7",
	/*0x0f*/ "invincibility on\n",
	/*0x10*/ "All Guns On\n",
	/*0x11*/ "Maximum Ammo\n",
	/*0x12*/ "Super x2 Health\n",
	/*0x13*/ "Super x2 Armor\n",
	/*0x14*/ "Invisibility On\n",
	/*0x15*/ "Bond Phase On\n",
	/*0x16*/ "Infinite Ammo On\n",
	/*0x17*/ "DK Mode On\n",
	/*0x18*/ "Extra Weapons\n",
	/*0x19*/ "Tiny Bond On\n",
	/*0x1a*/ "Paintball Mode On\n",
	/*0x1b*/ "Super x10 Health\n",
	/*0x1c*/ "Happy Now Karl?\n",
	/*0x1d*/ "Fast Mode On\n",
	/*0x1e*/ "Invincibility Off\n",
	/*0x1f*/ "All Guns Off\n",
	/*0x20*/ "Invisibility Off\n",
	/*0x21*/ "Bond Phase Off\n",
	/*0x22*/ "Infinite Ammo Off\n",
	/*0x23*/ "DK Mode Off\n",
	/*0x24*/ "Tiny Bond Off\n",
	/*0x25*/ "Paintball Mode Off\n",
	/*0x26*/ "Radar On\n",
	/*0x27*/ "Fast Mode Off\n",
	/*0x28*/ "NO NAME",
	/*0x29*/ "E R R O R\n",
	/*0x2a*/ "No briefing for this mission\n",
	/*0x2b*/ "\n",
	/*0x2c*/ "Objective",
	/*0x2d*/ "Completed\n",
	/*0x2e*/ "Incomplete\n",
	/*0x2f*/ "Failed\n",
	/*0x30*/ "Slowest Motion\n",
	/*0x31*/ "Very Slow Motion\n",
	/*0x32*/ "Slow Motion\n",
	/*0x33*/ "Normal Motion\n",
	/*0x34*/ "Fast Motion\n",
	/*0x35*/ "Very Fast Motion\n",
	/*0x36*/ "Fastest Motion\n",
	/*0x37*/ "Line Mode",
	/*0x38*/ "Paintball Mode",
	/*0x39*/ "Enemy Rockets",
	/*0x3a*/ "2x Rocket L.",
	/*0x3b*/ "2x Grenade L.",
	/*0x3c*/ "2x RC-P90",
	/*0x3d*/ "2x Throwing Knife",
	/*0x3e*/ "2x Hunting Knife",
	/*0x3f*/ "2x Laser",
	/*0x40*/ "Turbo Mode",
	/*0x41*/ "Fast Animation",
	/*0x42*/ "Slow Animation",
	/*0x43*/ "No Radar [Multi]",
	/*0x44*/ "One minute left.\n",
	/*0x45*/ "OBJECTIVES FAILED - Abort mission.\n",
	/*0x46*/ "Guard Greeting\n",
	/*0x47*/ "What's that gun\n",
	/*0x48*/ "Don't point that gun at me\n",
	/*0x49*/ "S/MPS",
	/*0x4a*/ "H/M",
	/*0x4b*/ "Y/D",
	/*0x4c*/ "P/D",
	/*0x4d*/ "CI 2023",
	/*0x4e*/ "BN: 161176",
	/*0x4f*/ "EYESPY",
	/*0x50*/ "MODEL 1.2",
	/*0x51*/ "GYROSTAT",
	/*0x52*/ "Meat",
	/*0x53*/ "Easy",
	/*0x54*/ "Normal",
	/*0x55*/ "Hard",
	/*0x56*/ "Perfect",
	/*0x57*/ "Dark",
	/*0x58*/ "MeatSim",
	/*0x59*/ "EasySim",
	/*0x5a*/ "NormalSim",
	/*0x5b*/ "HardSim",
	/*0x5c*/ "PerfectSim",
	/*0x5d*/ "DarkSim",
	/*0x5e*/ "PacifistSim",
	/*0x5f*/ "ShieldSim",
	/*0x60*/ "RocketSim",
	/*0x61*/ "KamikazeSim",
	/*0x62*/ "FistSim",
	/*0x63*/ "PredatorSim",
	/*0x64*/ "CowardSim",
	/*0x65*/ "JusticeSim",
	/*0x66*/ "VendettaSim",
	/*0x67*/ "CheetahSim",
	/*0x68*/ "TurtleSim",
	/*0x69*/ "RevengeSim",
	/*0x6a*/ "MeatSim:  This is the easiest of all the simulants to defeat and is therefore the best choice for the beginner.  It is not very intelligent and its shooting skills are very poor.\n",
	/*0x6b*/ "EasySim:  This simulant has basic skills & intelligence, but it can still be dangerous.\n",
	/*0x6c*/ "NormalSim:  This simulant is as skilled as the average human player.\n",
	/*0x6d*/ "HardSim:  This simulant is as skilled as a good human player.\n",
	/*0x6e*/ "PerfectSim: The ultimate adversary, the most intelligent and skilled simulant.  Most players will eventually want to use PerfectSim all the time as their skills improve.\n",
	/*0x6f*/ "DarkSim: Prototype cyborg developed by dataDyne to counteract Carrington operatives.  Remember that this simulant, unlike all the others, is not human.  This means that it may be able to do things which a human cannot.\n",
	/*0x70*/ "PacifistSim:  These simulants are scientists which protest the use of weapons.  They will go around the level hunting for guns that are lying around and horde them so that players cannot use them.  Of course, if you were to shoot them they might just drop a few!\n",
	/*0x71*/ "ShieldSim:  Always goes for maximum shield protection.  If this simulant loses any shield energy it will go and search for a new shield.  Not much use if there are no shields on the level!\n",
	/*0x72*/ "RocketSim:  This simulant loves to see things blow up.  It prefers weapons which make big explosions over conventional handguns or automatics.  This also extends to weapons which have explosive secondary functions!\n",
	/*0x73*/ "KamiKazeSim:  This simulant will stop at nothing to destroy it's target.  It is very aggressive and never keeps it's distance (even if it's holding a grenade!).  Be very careful of an adversary who is not afraid to die.\n",
	/*0x74*/ "FistSim:  This simulant protests the use of weapons in a similar way to the PacifistSims.  However it has no such reservations when it comes to unarmed combat.  It will always try to use it's fists to attack or disarm it's opponent.\n",
	/*0x75*/ "PredatorSim:  This simulant prefers to prey on the weak in order to get easier kills.  It will look for players who have just respawned, have an inferior weapon or are low on health.\n",
	/*0x76*/ "CowardSim:  This simulant does not really want to fight and will try and survive by running away.  It may sometimes attack but only if the opponent has an inferior weapon.  Draw out a better gun or shoot it and it will run away!\n",
	/*0x77*/ "JusticeSim:  This simulant has a strong sense of justice and dispises the tactics of the PredatorSim.  It will always try and kill the winning player in order to even up the score.\n",
	/*0x78*/ "VendettaSim:  Once this simulant picks a target, that player had better watch out!  A VendettaSim will pursue the player until the game is over!  Even if it is killed it will bear its grudge.\n",
	/*0x79*/ "CheetahSim:  These simulants have been trained for speed.  They can easily out-run a human player so it's no use  running away from a CheetahSim unless you know some good short-cuts!\n",
	/*0x7a*/ "TurtleSim:  This simulant wears a prototype shield generator developed by dataDyne scientists.  The generator projects a protective shield around its host which has twice the strength of a normal shield.  Unfortunately this restricts the hosts movement so it can only move at a slow pace.  TurtleSims carry this shield as standard even if there are no shields on the level.\n",
	/*0x7b*/ "RevengeSim:  Be careful if you shoot or kill a RevengeSim because it always attacks the player who last killed it.",
	/*0x7c*/ "Dark Combat",
	/*0x7d*/ "Skedar Mystery",
	/*0x7e*/ "CI Operative",
	/*0x7f*/ "dataDyne Action",
	/*0x80*/ "Maian Tears",
	/*0x81*/ "Alien Conflict",
	/*0x82*/ "Carrington Institute",
	/*0x83*/ "dD Central",
	/*0x84*/ "dD Central X",
	/*0x85*/ "dD Research",
	/*0x86*/ "dD Research X",
	/*0x87*/ "dD Extraction",
	/*0x88*/ "dD Extraction X",
	/*0x89*/ "Carrington Villa",
	/*0x8a*/ "Carrington Villa X",
	/*0x8b*/ "Chicago",
	/*0x8c*/ "Chicago X",
	/*0x8d*/ "G5 Building",
	/*0x8e*/ "G5 Building X",
	/*0x8f*/ "A-51 Infiltration",
	/*0x90*/ "A-51 Infiltration X",
	/*0x91*/ "A-51 Rescue",
	/*0x92*/ "A-51 Rescue X",
	/*0x93*/ "A-51 Escape",
	/*0x94*/ "A-51 Escape X",
	/*0x95*/ "Air Base",
	/*0x96*/ "Air Base X",
	/*0x97*/ "Air Force One",
	/*0x98*/ "Air Force One X",
	/*0x99*/ "Crash Site",
	/*0x9a*/ "Crash Site X",
	/*0x9b*/ "Pelagic II",
	/*0x9c*/ "Pelagic II X",
	/*0x9d*/ "Deep Sea",
	/*0x9e*/ "Deep Sea X",
	/*0x9f*/ "Institute Defense",
	/*0xa0*/ "Institute Defense X",
	/*0xa1*/ "Attack Ship",
	/*0xa2*/ "Attack Ship X",
	/*0xa3*/ "Skedar Ruins",
	/*0xa4*/ "Skedar Ruins X",
	/*0xa5*/ "End Credits",
	/*0xa6*/ "Random\n",
	/*0xa7*/ "Select All\n",
	/*0xa8*/ "Select None\n",
	/*0xa9*/ "Randomise\n",
	/*0xaa*/ "Weapon",
	/*0xab*/ "Function",
	/*0xac*/ "Orders",
	/*0xad*/ "No Weapon",
	/*0xae*/ "Pick Target\n",
	/*0xaf*/ "Follow",
	/*0xb0*/ "Attack",
	/*0xb1*/ "Defend",
	/*0xb2*/ "Hold",
	/*0xb3*/ "Normal",
	/*0xb4*/ "Download",
	/*0xb5*/ "Get Flag",
	/*0xb6*/ "Tag Box",
	/*0xb7*/ "Killed by",
	/*0xb8*/ "Killed",
	/*0xb9*/ "Beginner:21\n",
	/*0xba*/ "Trainee:20\n",
	/*0xbb*/ "Amateur:19\n",
	/*0xbc*/ "Rookie:18\n",
	/*0xbd*/ "Novice:17\n",
	/*0xbe*/ "Trooper:16\n",
	/*0xbf*/ "Agent:15\n",
	/*0xc0*/ "Star Agent:14\n",
	/*0xc1*/ "Special Agent:13\n",
	/*0xc2*/ "Expert:12\n",
	/*0xc3*/ "Veteran:11\n",
	/*0xc4*/ "Professional:10\n",
	/*0xc5*/ "Dangerous:9\n",
	/*0xc6*/ "Deadly:8\n",
	/*0xc7*/ "Killer:7\n",
	/*0xc8*/ "Assassin:6\n",
	/*0xc9*/ "Lethal:5\n",
	/*0xca*/ "Elite:4\n",
	/*0xcb*/ "Invincible:3\n",
	/*0xcc*/ "Near Perfect:2\n",
	/*0xcd*/ "Perfect:1\n",
	/*0xce*/ "DARTAMMO",
	/*0xcf*/ "MODEL 1.4",
	/*0xd0*/ "BN: 200959",
	/*0xd1*/ "Save Flag",
	/*0xd2*/ "Def Hill",
	/*0xd3*/ "Hold Hill",
	/*0xd4*/ "Get Case",
	/*0xd5*/ "Pop Cap",
	/*0xd6*/ "Protect",
	/*0xd7*/ "All Simulants",
	/*0xd8*/ "MODEL 1.3",
	/*0xd9*/ "BN: 261069",
	/*0xda*/ "Not enough room to launch ",
	/*0xdb*/ "Joanna Dark\n",
	/*0xdc*/ "Human (Female)\n",
	/*0xdd*/ "23 years 2 months\n",
	/*0xde*/ "|CI File #027 -\n\nTraining Status: Complete\nTraining Grade: A++\nActive Status: Assigned\n\n|Profile -\n\nHighly trained but inexperienced. Reactions superb. Proficient with a variety of weapons. Very competent all-round agent. Highest recorded training scores resulted in the creation of a new class of training grade. The embodiment of the Carrington Institute's ideal agent, hence the callsign 'Perfect Dark'.\n",
	/*0xdf*/ "Jonathan\n",
	/*0xe0*/ "Human (Male)\n",
	/*0xe1*/ "28 years 5 months\n",
	/*0xe2*/ "|CI File #009 -\n\nTraining Status: Complete\nTraining Grade: A+\nActive Status: Undercover\n\n|Profile -\n\nOur most experienced undercover agent. Highly accurate with his chosen weapon (a Magnum Revolver). Perfectly suited to undercover missions. Less suited to out-and-out combat. Before Joanna Dark he held the honour of having the highest recorded training scores.\n",
	/*0xe3*/ "Daniel Carrington\n",
	/*0xe4*/ "Human (Male)\n",
	/*0xe5*/ "62 years 8 months\n",
	/*0xe6*/ "|CI File #000 -\n\nTraining Status: N/A\nTraining Grade: N/A\nActive Status: N/A\n\n|Profile -\n\nIntelligent patriarchal scientist/entrepreneur, and founder of the Carrington Institute. Plans all missions carried out by his agents, runs each operation direct from a link in his office. Strange taste in clothes.\n",
	/*0xe7*/ "Cassandra De Vries\n",
	/*0xe8*/ "Human (Female)\n",
	/*0xe9*/ "39 years ? months\n",
	/*0xea*/ "|Analyst note -\n\nThe head of dataDyne Corp. Addicted to power, dislikes being anybody's underling. Hates it when she loses the initiative. Is prepared to do extremely unscrupulous things in order to get ahead of her competition, to whit Daniel Carrington, whom she hates. \n\n[source: WALL STREET JOURNAL]\n",
	/*0xeb*/ "Trent Easton\n",
	/*0xec*/ "Human (Male)\n",
	/*0xed*/ "46 years ? months\n",
	/*0xee*/ "|Analyst note -\n\nHead of the National Security Agency. Has a friendship of sorts with Cassandra De Vries although it operates more like a partnership of interest. He will tend to do what Cassandra says, possibly because although he has a dominant personality, it is not as dominant as hers. Figurehead for some of the rogue elements in the NSA.\n",
	/*0xef*/ "Dr. Caroll\n",
	/*0xf0*/ "The Caroll Sapient (AI)\n",
	/*0xf1*/ "6 months\n",
	/*0xf2*/ "|Profile -\n\nAn artificial intelligence created by the dataDyne corp with an emphasis on language skills and code-breaking. Fortunately he has morals, and due to his formidable level of intelligence has guessed some of dataDyne's future plans. The voice is highly precise and educated, and simulates the character of an academic.\n",
	/*0xf3*/ "Elvis\n",
	/*0xf4*/ "Maian (Male)\n",
	/*0xf5*/ "320 years\n",
	/*0xf6*/ "|Profile -\n\nAn alien from the Maian race. He is a 'Protector' (bodyguard) for the Maian ambassador who travels to Earth at Daniel Carrington's request. Protectors are trained to excel in the use of an assortment of weaponry. Elvis is a terraphile, finding Earth and everything about it fascinating.\n",
	/*0xf7*/ "Mr Blonde\n",
	/*0xf8*/ "Human (Male)\n",
	/*0xf9*/ "Late 20's\n",
	/*0xfa*/ "|Profile -\n\nA striking blonde young human male whose the voice is dull, annoying, and cringeworthy. Very tall. Appears to be masterminding the conspiracy in which Cassandra and Trent are involved. Little else is known.\n",
	/*0xfb*/ "Mr Blonde\n",
	/*0xfc*/ "Skedar (disguised)\n",
	/*0xfd*/ "unknown\n",
	/*0xfe*/ "|Updated Profile -\n\nThis is a Skedar Warrior lurking within a holographic projection of a striking blonde young human male in his late 20's.  The oral modulation unit gives the Skedar a precise, persuasive, and intelligent voice. It is a propaganda and manipulation tool for the Skedar, and an unusually subtle one.\n",
	/*0xff*/ "The US President\n",
	/*0x100*/ "Human (Male)\n",
	/*0x101*/ "50 years\n",
	/*0x102*/ "|Profile -\n\nA highly educated, shrewd African-American who is trying to do what is right but is surrounded by people like Trent Easton. He believes he has Trent under control after refusing the request for the loan of the Pelagic II to the dataDyne Corp. Perceived as being easily led by the majority of political commentators which is perhaps unfair.\n",
	/*0x103*/ "Maians\n",
	/*0x104*/ "The Maians are the race of aliens that have come to be known on Earth as 'Greys'. They have been monitoring Earth for a long time - several centuries - and are benevolent towards mankind, sensing great potential in the human race. Their contact on Earth is Daniel Carrington, a formal political contact has yet to be made.\n",
	/*0x105*/ "Skedar Warrior\n",
	/*0x106*/ "The Skedar are a warlike alien race who have fought the Maians for centuries and have only recently agreed to a ceasefire. Tend to use huge mechanized armatures to walk about and fight in, since they are in actual fact smaller, snakelike creatures. Very aggressive -  they have made war a religion, and are extremely devout.\n",
	/*0x107*/ "Background\n",
	/*0x108*/ "Millions of years ago, a battlecruiser of immense power was scuttled in the Pacific ocean by a race of aliens called Cetans. It was equipped with an untried weapon - the weak nuclear force de-coupler, which could in theory cause the bonds which held molecules together to fail. So that watching eyes would believe in the destruction of the ship, a message pod was sent back to the home system and vital parts of the drive systems were destroyed in the star system they had chosen to hide in.\n\nMaian aliens encounter life on Earth. They see potential, but decide to leave the primitive race of Humans alone to develop.\n\nThe Maians meet the Skedar and they have a fight that turns into a protracted war. After hundreds of years of fighting an uneasy peace develops. Fanatical Skedar continually test the boundaries of this peace with terrorist activities, but the Maians refuse to be drawn.\n\nThe Maians are wary of humans sensing that too many crises have arisen on Earth as a result of technology and 'outside context situations'.  They fear that announcing their presence may well precipitate further wars on the planet, and therefore decide to observe the race until it becomes more mature.\n\nDaniel Carrington jumps the gun by contacting a Maian ship in orbit above Earth. He has a plan that would help both parties, resulting in accelerated contact between humans and Maians. Having agreed that his plan is sound, and that he is a person of integrity, the Maians help Daniel Carrington to release their technology into the public domain.\n\nThe Skedar fanatics find a message pod from the Cetan battlecruiser. They immediately scout Earth in a particularly heavy-handed way, abducting people and mutilating animals in an attempt to find out where the battlecruiser is. Their tests direct them to the pacific ocean where they locate the ship. However, they need help to get to it.\n\nThey perform their own study of Earth and come up with a shortlist of companies with the resources to help them recover the sunken ship. At the top of the list is the dataDyne corporation. They contact the head of the corporation, Cassandra De Vries, and present her with a deal that sounds too good to be true - which it is. They say that in return for helping the Skedar raise 'their' ship from the ocean floor, they will give dataDyne enough technology to become the biggest corporation on the planet. All that dataDyne have to do is build an AI unit with language and code-breaking abilities.  This is tricky, but within their means. Work commences on the project.\n\nCassandra De Vries approaches the head of the NSA, Trent Easton, with the details. He attempts to get Presidential approval for the loan of a deep-sea research vessel to dataDyne but is refused by the president.  There is no way that the Skedar or dataDyne could steal the vessel without triggering the wrath of the US government so they settle on a plan of replacing the President with a clone that they can control. This promises to have extra rewards for Trent and Cassandra after the Skedar operation is finished.\n\nHowever, they will not have an awful lot of time to gloat. The Skedar plan to test the weak nuclear force de-coupler on Earth before wiping the Maians out of existence. Cassandra is blinded to the possibility of being double-crossed by the enormous gain in power she will have. This affliction also affects Trent Easton.\n\nBut dataDyne have made the one thing that can see such dangers emerge from the sea of facts around itself - the sapient AI created to crack the access codes of the Cetan battlecruiser. When it expresses concern about the mission it is being created for the response of Cassandra De Vries is to order its personality removed. Clearly it is thinking too much. In desperation it contacts the Carrington organisation with a plea for help, under the pseudonym Dr. Caroll...\n",
	/*0x109*/ "The Story\n",
	/*0x10a*/ "Untried agent Joanna Dark is assigned the mission to extract a scientist from the high security research area below the dataDyne skyscraper. She is surprised to discover that 'Dr. Caroll' is an AI created by the corporation, but continues with the mission to get him/it to a place of safety. With the alarm raised Joanna has to fight her way up the tower to get to the helipad for the extraction by dropship.\n\nIn response to this dataDyne targets Daniel Carrington and takes him hostage two days later at his private villa. They demand the return of the AI - their 'property' - in exchange for Daniel Carrington's life. Unknown to them, the AI is at the villa. Carrington had been talking with it to find out about dataDyne's future plans. Joanna rescues Daniel but is unable to prevent dataDyne from recovering Dr. Caroll but her boss has heard enough from the AI to prompt him into summoning a team of Maian specialists to Earth.\n\nJoanna is dispatched to Chicago to spy on a conspirators' meeting at the G5 building, a front for the dataDyne corp. She learns of the involvement of Trent Easton, the head of the NSA, and of the strange Nordic men that seem to be in control of the whole scheme. Once the plan to move on the President is disclosed by Trent, Jo calls in with the news but finds out there is another, more urgent job for her to complete first.\n\nThe specialists' have been intercepted by the conspirators, and the survivors of the crash and the crash wreckage itself have been taken to Area 51 in Nevada. Joanna is dropped in to link up with another Carrington Institute agent to rescue any survivors and to retrieve any of their equipment. When she breaks into the medlab Joanna discovers the Carrington Institute's secret - their allies are Maians, the aliens known as Greys. The particular alien she rescues is called Elvis. He was a bodyguard for the Ambassador who was coming in as the head of the team of specialists.\n\nHaving aided the remnants of the Maian delegation Joanna can turn to the matter of the President and dataDyne's designs against him. She poses as a member of the president's entourage to gain access to the airbase where Air Force One is stationed and manages to conceal herself on board the airplane. Once it is in the air Trent and the cloaked Skedar make their move - but Joanna is there to stop him. She gets the President to a safety capsule while a team of Trent's men scour the aircraft for him, intent on dragging the hapless politician aboard the Skedar UFO, now docked to AF1 via an umbilical. Jo weakens the umbilical but is unable to break it. She calls on Elvis, who decides to crash into it. All three craft go down in the Alaskan wilderness and the escape pod is launched.\n\nJo wakes up and tries to report in but finds her communications being jammed by a transmission from the Skedar craft. She sets off through the snow to find the President and Elvis. She comes across teams of cloaked Skedar who are searching for the President, Elvis, herself and some of the President's belongings. She tracks one group back to the downed Skedar ship where she discovers a clone of the President. She destroys this and shuts down the jamming device, then calls in the cavalry. The Skedar have been thwarted again, the President is saved, and Trent is killed horribly by the Skedar for failing to be competent in the first place.\n\nThrowing caution to the wind, dataDyne and the Skedar steal the Government's deep sea research vessel 'Pelagic II' and head out to the crash site. Joanna goes out with Elvis to disrupt activity on board the ship and to find out what the big project is. After crippling the diving operations on the ship and recalling the submersible they head down to the ocean floor, where they get their first sight of the sunken Cetan battlecruiser. Entering the ship through the portal the Skedar have made they come across a dead skedar warrior... clearly the assault team didn't have it all their own way. After fighting off the Skedar and avoiding the Cetans, Joanna and Elvis get to the core of the ship where they find the AI that was once Dr. Caroll. Once his personality is restored he urges Joanna and Elvis to leave the ship, which he intends to destroy for good.\n\nBack at the Carrington Institute, Joanna is about to leave for a Presidential reception at the White House when all hell breaks loose. The surviving Skedar assault team vent their anger on the people responsible for their failure to recover the Cetan ship. Joanna runs around the Institute trying to escort CI employees to the hangars while the Skedar attack different parts of the building. Joanna holds them off while the majority of the employees escape, before getting knocked unconscious and captured by the Skedar.\n\nShe wakes up in a holding cell on board the Skedar assault ship with Cassandra De Vries for company. The dataDyne CEO dies while creating a distraction for Joanna to break out. Jo manages to get through to lower the docking bay shields and Elvis brings a few friends in for a shooting party.\n\nThe captured ship enters orbit above the Skedar battle shrine, which gives Elvis a shock since the Maians could never find this Skedar holiest of holy places. If the Shrine is destroyed the Skedar morale would be dealt a fatal blow and there would be true peace instead of an uneasy ceasefire. Jo sets her sights on the leader of the Skedar, the high priest of the battle shrine, while Elvis returns to the Assault ship to summon the Maian fleet.\n\nThe game finishes with the temple in ruins... Elvis calls for a lull in the bombardment so that he can find Joanna. She is alive, held under a pile of rubble by a Skedar that grabbed her foot before she could get clear. Elvis lends her a gun to help convince the Skedar to let go, and they depart for orbit.\n",
	/*0x10b*/ "dataDyne Corporation\n",
	/*0x10c*/ "dataDyne are nasty\n",
	/*0x10d*/ "Carrington Institute\n",
	/*0x10e*/ "The Carrington Institute is lovely\n",
	/*0x10f*/ "Description\n- A tiny remote camera for stealthy exploration. Equipped for spectroscopic holography. Opens doors by projecting a human sized pulse of heat.\n\nTraining Instructions\n- Holograph the Hackers terminal next door in the Info room.\n\nOperation\n- Press Z to take a holograph. Pressing B will open any doors in the way.Hold down R to look around.\n",
	/*0x110*/ "Description\n- Enhances any visible light to produce an image of the surrounding area. Also highlights lifeforms. Overloads in normal light conditons, 'whiting out' the display.\n\nTraining Instructions\n- Head into the darkness, find the light switch and activate it to turn the lights back on.\n\nOperation\n- Select the Nightvision from your inventory to activate it. Reselect to deactivate.\n",
	/*0x111*/ "Description\n\n- Standalone code-breaking device. Attaches to the control panel and sifts through the possible combinations until the lock is opened.\n\nTraining Instructions\n- Find the pad by the locked door and use the door decoder on it to unlock the door.\n\nOperation\n- Stand next to the door pad and press B while holding the door decoder to use it.\n",
	/*0x112*/ "Description\n\n- Used to look through otherwise solid walls and objects. Can see things that the night vision and IR goggles can not.\n\nTraining Instructions\n- With the Xray Scanner on, search for the 2 hidden switches and activate them to turn off the laser grid.\n\nOperation\n- Select the Xray Scanner from your inventory to activate it. Reselect to deactivate.\n",
	/*0x113*/ "Description\n\n- Allay suspicion by the use of a disguise. But, always be alert for the possibility of being unmasked by a quick witted enemy.\n\nTraining Instructions\n- Grimshaw has a cloaking device waiting to be serviced. Head next door and 'aquire' it from him.\n\nOperation\n- To wear the disguise simply select it from your inventory.\n",
	/*0x114*/ "Drscription\n\n- Translates thermal data into visible images. Can be used in darkness and will also reveal anomalies such as hidden doors and weak wall sections.\n\nTraining Instructions\n- Turning on the IR scanner, find the hidden door and open it.\n\nOperation\n- Select the IR Scanner from your inventory to activate it. Reselect to deactivate.\n",
	/*0x115*/ "Description\n- Locates a particular object on a HUD radar map. Shows the relative bearing and distance.\n\nTraining Instructions\n- Activate the tracker and follow the radar signature to retrieve the item.\n\nOperation\n- Selecting the Tracker from your inventory will activate it. Reselect to deactivate.\n",
	/*0x116*/ "Description\n- Distrupts the radiation field around the wearer, creating a chameleon type effect. This field is disrupted when the wearer fires.\n\nTraining Instructions\n- Activate the cloaking device and head to Carringtons office to suprise him!\n\nOperation\n- Selecting the Cloaking Device from your inventory will activate it. Reselect to deactivate.\n",
	/*0x117*/ "Description\n- Emits a constantly shifting signal designed to jam any electronic communications device. Must be placed on the object to be effective.\n\nTraining Instructions\n- Throw the ECM mine onto the lighting hub located through the secret door.\n\nOperation\n- Press Z to throw the mine. Hold down R and move the stick to fine tune your aim before throwing.\n",
	/*0x118*/ "Description\n- Provides a link from the field agent to the Institute hackers back at HQ, who can then download data or crack electronic locks remotely.\n\nTraining Instructions\n- Use the Comms Uplink to hack the terminal in the corner, unlocking a secret door.\n\nOperation\n- Stand next to the terminal and press B when holding Comms Uplink.\n",
	/*0x119*/ "FIRING\n Press Z to fire gun\n",
	/*0x11a*/ "AUTO RELOAD\n Release Z to reload when magazine empty\n",
	/*0x11b*/ "MANUAL RELOAD\n Press B to reload early if magazine not full\n",
	/*0x11c*/ "Aiming: hold down R to enter aim mode\n",
	/*0x11d*/ "Use analog stick to move aiming sight\n",
	/*0x11e*/ "AUTO FIRE\n Hold Z to repeatedly fire automatically\n",
	/*0x11f*/ "ALTER AIM\n Press up C or down C to move sight up/down\n",
	/*0x120*/ "ZOOM\n Hold R to enter Zoom mode\n",
	/*0x121*/ "FAST FIRE\n Press Z quickly to fire faster\n",
	/*0x122*/ "ELVIS IS DEAD OR FALLEN OUT OF THE BACKGROUND\n",
	/*0x123*/ "Carrington Institute\0|Main building and base of operations\n",
	/*0x124*/ "Lucerne Tower\0|Global Headquarters\n",
	/*0x125*/ "Laboratory Basement\0|Underground research labs\n",
	/*0x126*/ "Carrington Villa\0|Private coastal retreat\n",
	/*0x127*/ "Chicago\0|Backstreets of the city\n",
	/*0x128*/ "G5 Building\0|dataDyne front corporation\n",
	/*0x129*/ "Area 51\0|Near Groom Dry Lake, Nevada\n",
	/*0x12a*/ "Alaskan Airbase\0|Brooks Range, Alaska\n",
	/*0x12b*/ "Air Force One\0|The President's Airplane\n",
	/*0x12c*/ "Crash Site\0|Victoria Island 71N 118W\n",
	/*0x12d*/ "Pelagic 2\0|Specialised Deep Sea Research Ship\n",
	/*0x12e*/ "Cetan Ship\0|The most alien environment on Earth\n",
	/*0x12f*/ "Skedar Assault Ship\0|Troop Carrying spacecraft\n",
	/*0x130*/ "Skedar Homeworld\0|The planet of the Battle Shrine\n",
	/*0x131*/ "Dropship\0|Insert subtitle here\n",
	/*0x132*/ "HoverCrate\0|Insert subtitle here\n",
	/*0x133*/ "HoverBike\0|subtitle here\n",
	/*0x134*/ "Cleaning Hovbot\0|Insert subtitle here\n",
	/*0x135*/ "Hovercopter\0|Insert subtitle here\n",
	/*0x136*/ "G5 Robot\0|Insert subtitle here\n",
	/*0x137*/ "A51 Interceptor\0|Insert subtitle here\n",
	/*0x138*/ "Maian Vessel\0|Insert subtitle here\n",
	/*0x139*/ "Skedar Shuttle\0|Insert subtitle here\n",
	/*0x13a*/ "The Institute building comprises many different areas: offices and laboratories, workshops and hangars. It is quite isolated from the outside world, which helps keep the operations covert.\n",
	/*0x13b*/ "In the midst of the business district, the austere skyscraper of the dataDyne Corporation stands out from the surroundings.\n",
	/*0x13c*/ "These heavily guarded, well hidden labs hold the key to dataDyne's future. Within them, techs work on top secret projects aimed at putting dataDyne on the top of the heap.\n",
	/*0x13d*/ "Owned by the Institute, this secluded residence is used by Daniel Carrington as a retreat from the pressures of the Institute. As well as an observatory, it has a power generator and an extensive wine cellar.\n",
	/*0x13e*/ "A seedy, grimy part of the city of Chicago, now closed to ground traffic. It is here that the G5 corporation has their headquarters.\n",
	/*0x13f*/ "Inside the G5 building is a meeting room protected by anti-recording safeguards. This is the safest place for dataDyne to formulate confidential plans.\n",
	/*0x140*/ "This section of the extensive facility known as Area 51 is based in the foothills around Groom Dry Lake. Exterior helipads and communication towers hint at the size of the complex beneath ground level.\n",
	/*0x141*/ "One of a series of reinforced airbases available as staging posts for Air Force One. Typically, the airbase is remote, in an inhospitable region, far away from prying eyes.\n",
	/*0x142*/ "This particular Air Force One is optimised for cold climates, useful when it is based in the north of Alaska. The flight destination is Oslo, Norway.\n",
	/*0x143*/ "In the rocky snow-covered landscape of the Arctic Circle the wreckage of the stricken plane has come to rest.\n",
	/*0x144*/ "Owned by the US government, the Pelagic 2 is capable of staging deep sea diving operations in all weathers. It is the only fully integrated ocean floor research vessel in the world.\n",
	/*0x145*/ "A huge ship of alien construction that has lain on the ocean floor for millions of years.\n",
	/*0x146*/ "An interplanetary assault ship that carries Skedar Warriors to their war zones. Part of the much-reduced Skedar battle fleet.\n",
	/*0x147*/ "A highly arid planet, wracked by earthquakes, sandstorms and hurricanes. It is part of a complex solar system that includes three suns.\n",
	/*0x148*/ "that thing in the first cutscene\n",
	/*0x149*/ "a floating crate\n",
	/*0x14a*/ "a floating bike\n",
	/*0x14b*/ "a floating hoover\n",
	/*0x14c*/ "a cool ship with startling AI and realistic dynamic movement\n",
	/*0x14d*/ "a superb attack drone with lovely rotating guns and brilliant AI\n",
	/*0x14e*/ "just as cool as the hovercopter, especially when it crashes\n",
	/*0x14f*/ "ooh! shiny\n",
	/*0x150*/ "skedar shuttle thing\n",
	/*0x151*/ "Description\n- A good agent notices everything around them.\n\nTraining Instructions\n- Examine all of the objects by looking directly at them.\n\nOperation\n-Look up- Press Down C\n-Look down- Press Up C\n-Free Look- Hold down R to enter aim mode and use the stick to look.\n",
	/*0x152*/ "Description\n- Proverb type saying about movement 1 here.\n\nTraining Instructions\n- Activate All Of The Switches In Front. Be Quick Though, As Each Switch Will Reset On A Time Limit.\n\nOperation\n- Sidestep left- Left C\n- Sidestep right- Right C\n\n",
	/*0x153*/ "Description\n- Proverb type saying about movement 2 here.\n\nTraining Instructions\n- Work your way through the obstacles using the moves available to you. Activate The Switches.\n\nOperation\n- Duck- Hold R then press down C.\n- Crouch- When ducking, Hold R then press down C.\n- Get Up- Tap R.\n\n",
	/*0x154*/ "Description\n- Proverb type saying about unarmed combat 1 here.\n\nTraining Instructions\n- Knock out all enemies without getting hit.\n\nOperation\n- Punch - Press Z repeatedly when unarmed to launch a flurry of punches.\n\n",
	/*0x155*/ "Description\n- Proverb type saying about unarmed combat 2 here.\n\nTraining Instructions\n- Knockout/Disarm all enemies without getting hit.\n\nOperation\n- Disarm - Hold B then press Z to disarm an enemy.\n- Knockout Punch - punch an unaware enemy from behind.\n",
	/*0x156*/ "Description\n- Proverb type saying about combat test 1 here.\n\nTraining Instructions\n- Beat all the unarmed enemies without getting hit.\n\n",
	/*0x157*/ "Description\n- Proverb type saying about combat test 2 here.\n\nTraining Instructions\n- Beat all the armed enemies without getting hit.\n\n",
	/*0x158*/ "holo_tips1\n",
	/*0x159*/ "holo_tips2\n",
	/*0x15a*/ "holo_tips3\n",
	/*0x15b*/ "holo_tips4\n",
	/*0x15c*/ "holo_tips5\n",
	/*0x15d*/ "holo_tips6\n",
	/*0x15e*/ "holo_tips7\n",
	/*0x15f*/ "holo_advice1\n",
	/*0x160*/ "holo_advice2\n",
	/*0x161*/ "holo_advice3\n",
	/*0x162*/ "holo_advice4\n",
	/*0x163*/ "holo_advice5\n",
	/*0x164*/ "holo_advice6\n",
	/*0x165*/ "holo_advice7\n",
	/*0x166*/ "device_tips1\n",
	/*0x167*/ "device_tips2\n",
	/*0x168*/ "device_tips3\n",
	/*0x169*/ "device_tips4\n",
	/*0x16a*/ "device_tips5\n",
	/*0x16b*/ "device_tips6\n",
	/*0x16c*/ "device_tips7\n",
	/*0x16d*/ "device_tips8\n",
	/*0x16e*/ "device_tips9\n",
	/*0x16f*/ "device_tips10\n",
	/*0x170*/ "device_advice1\n",
	/*0x171*/ "device_advice2\n",
	/*0x172*/ "device_advice3\n",
	/*0x173*/ "device_advice4\n",
	/*0x174*/ "device_advice5\n",
	/*0x175*/ "device_advice6\n",
	/*0x176*/ "device_advice7\n",
	/*0x177*/ "device_advice8\n",
	/*0x178*/ "device_advice9\n",
	/*0x179*/ "device_advice10\n",
	/*0x17a*/ "Instructions for falcon2\n",
	/*0x17b*/ "Instructions for falcon2scope\n",
	/*0x17c*/ "Instructions for falcon2silenced\n",
	/*0x17d*/ "Instructions for leegun1\n",
	/*0x17e*/ "Instructions for skedarpistol\n",
	/*0x17f*/ "Instructions for maianpistol\n",
	/*0x180*/ "Instructions for dy357\n",
	/*0x181*/ "Instructions for dy357_trent\n",
	/*0x182*/ "Instructions for cmp150\n",
	/*0x183*/ "Instructions for cyclone\n",
	/*0x184*/ "Instructions for maiansmg\n",
	/*0x185*/ "Instructions for anothersmg\n",
	/*0x186*/ "Instructions for pcgun\n",
	/*0x187*/ "Instructions for dydragon\n",
	/*0x188*/ "Instructions for k7avenger\n",
	/*0x189*/ "Instructions for ar34\n",
	/*0x18a*/ "Instructions for dysuperdragon\n",
	/*0x18b*/ "Instructions for shotgun\n",
	/*0x18c*/ "Instructions for sniperrifle\n",
	/*0x18d*/ "Instructions for z2020\n",
	/*0x18e*/ "Instructions for crossbow\n",
	/*0x18f*/ "Instructions for druggun\n",
	/*0x190*/ "Instructions for skedarminigun\n",
	/*0x191*/ "Instructions for dydevastator\n",
	/*0x192*/ "Instructions for dyrocket\n",
	/*0x193*/ "Instructions for skedarrocket\n",
	/*0x194*/ "Instructions for knife\n",
	/*0x195*/ "Instructions for laser\n",
	/*0x196*/ "Instructions for grenade\n",
	/*0x197*/ "Instructions for nbomb\n",
	/*0x198*/ "Instructions for timedmine\n",
	/*0x199*/ "Instructions for proximitymine\n",
	/*0x19a*/ "Instructions for remotemine\n",
	/*0x19b*/ "Style 1",
	/*0x19c*/ "Style 2",
	/*0x19d*/ "Style 3",
	/*0x19e*/ "Style 4",
	/*0x19f*/ "Blond",
	/*0x1a0*/ "Black",
	/*0x1a1*/ "Auburn",
	/*0x1a2*/ "Blue Rinse",
	/*0x1a3*/ "Player",
	/*0x1a4*/ "",
	/*0x1a5*/ "Identify\n",
	/*0x1a6*/ "Sim",
	/*0x1a7*/ "Challenges\n",
	/*0x1a8*/ "Load/Preset Games\n",
	/*0x1a9*/ "Quick Start\n",
	/*0x1aa*/ "Advanced Setup\n",
	/*0x1ab*/ "Combat Simulator\n",
	/*0x1ac*/ "Carrington Institute\n",
	/*0x1ad*/ "Team Score\n",
	/*0x1ae*/ "Finished Setup\n",
	/*0x1af*/ "Player 1 Team\n",
	/*0x1b0*/ "Player 2 Team\n",
	/*0x1b1*/ "Player 3 Team\n",
	/*0x1b2*/ "Player 4 Team\n",
	/*0x1b3*/ "Number Of Sims\n",
	/*0x1b4*/ "Sims Per Team\n",
	/*0x1b5*/ "Sim Difficulty\n",
	/*0x1b6*/ "Start Game\n",
	/*0x1b7*/ "Drop Out\n",
	/*0x1b8*/ "Player Settings\n",
	/*0x1b9*/ "Game Settings\n",
	/*0x1ba*/ "Quick Go\n",
	/*0x1bb*/ "Ready!\n",
	/*0x1bc*/ "Quick Team\n",
	/*0x1bd*/ "Players Only\n",
	/*0x1be*/ "Players and Simulants\n",
	/*0x1bf*/ "Player Teams\n",
	/*0x1c0*/ "Players versus Simulants\n",
	/*0x1c1*/ "Player-Simulant Teams\n",
	/*0x1c2*/ NULL,
	/*0x1c3*/ NULL,
	/*0x1c4*/ NULL,
	/*0x1c5*/ NULL,
	/*0x1c6*/ NULL,
	/*0x1c7*/ NULL,
	/*0x1c8*/ NULL,
	/*0x1c9*/ NULL,
	/*0x1ca*/ NULL,
	/*0x1cb*/ NULL,
	/*0x1cc*/ NULL,
	/*0x1cd*/ NULL,
	/*0x1ce*/ NULL,
	/*0x1cf*/ NULL,
	/*0x1d0*/ NULL,
	/*0x1d1*/ NULL,
	/*0x1d2*/ NULL,
	/*0x1d3*/ NULL,
	/*0x1d4*/ NULL,
	/*0x1d5*/ NULL,
	/*0x1d6*/ NULL,
	/*0x1d7*/ NULL,
	/*0x1d8*/ NULL,
	/*0x1d9*/ NULL,
	/*0x1da*/ NULL,
	/*0x1db*/ NULL,
};