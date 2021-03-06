#include <ultra64.h>

char *lang[] = {
	/*0x00*/ "|Background - \n\nIn revenge for the foiling of their grand plan, the Skedar have attacked the source of their troubles, the Carrington Institute. With an organized response out of the question, it falls to Joanna to save what she can of the Institute from total destruction.\n\n|Carrington - \n\nThey've caught us completely off guard, Jo! Save who and what you can, then get out yourself. After all, the Institute is the people, not the building.\n\n|Objective One: - Reactivate Automatic Defenses\n\nThere are automatic guns situated at strategic locations throughout the Carrington Institute. At present they are inactive, but if you can get to the control panel and activate them, they will help thin the attackers out.\n\n|Objective Two: - Minimize Hostage Casualties\n\nSome of the invading forces are holding key Institute staff hostage. Save as many of the hostages as you can. Look in the various labs throughout the upper floors of the building.\n\n|Objective Three: - Retrieve Experimental Weapon\n\nIn Foster's weapons lab there is a prototype submachine gun that we cannot let fall into enemy hands. This is because the weapon is capable of creating a temporary cloaking field. Find it and carry out some 'field research.'\n\n|Objective Four: - Destroy Sensitive Information\n\nIn Daniel's office there is a safe in which is kept the algorithm he used to crack the Maian communication codes so many years ago. It must be destroyed before dataDyne or the Skedar get hold of it. Use the laser to cut a way through the door.\n\n|Objective Five: - Deactivate Bomb\n\nOur sensors indicate there is a bomb in the Skedar craft on the landing pad! The only thing that can help you is the Data Uplink - get close to the ship, and use it to install a virus. The ship should then float clear of the Institute, and the bomb will detonate without harming anyone.\n\nEND\n",
	/*0x01*/ "CARRINGTON INSTITUTE\n",
	/*0x02*/ "|Background - \n\nIn revenge for the foiling of their grand plan, the Skedar have attacked the source of their troubles, the Carrington Institute. With an organized response out of the question, it falls to Joanna to save what she can of the Institute from total destruction.\n\n|Carrington - \n\nThey've caught us completely off guard, Jo! Save who and what you can, then get out yourself. After all, the Institute is the people, not the building.\n\n|Objective One: - Reactivate Automatic Defenses\n\nThere are automatic guns situated at strategic locations throughout the Carrington Institute. At present they are inactive, but if you can get to the control panel and activate them, they will help thin the attackers out.\n\n|Objective Two: - Minimize Hostage Casualties\n\nSome of the invading forces are holding key Institute staff hostage. Save as many of the hostages as you can. Look in the various labs throughout the upper floors of the building.\n\n|Objective Three: - Retrieve Experimental Weapon\n\nIn Foster's weapons lab there is a prototype submachine gun that we cannot let fall into enemy hands. This is because the weapon is capable of creating a temporary cloaking field. Find it and carry out some 'field research.'\n\n|Objective Four: - Deactivate Bomb\n\nOur sensors indicate there is a bomb in the Skedar craft on the landing pad! The only thing that can help you is the Data Uplink - get close to the ship, and use it to install a virus. The ship should then float clear of the Institute, and the bomb will detonate without harming anyone.\n\nEND\n",
	/*0x03*/ "|Background - \n\nIn revenge for the foiling of their grand plan, the Skedar have attacked the source of their troubles, the Carrington Institute. With an organized response out of the question, it falls to Joanna to save what she can of the Institute from total destruction.\n\n|Carrington - \n\nThey've caught us completely off guard, Jo! Save who and what you can, then get out yourself. After all, the Institute is the people, not the building.\n\n|Objective One: - Minimize Hostage Casualties\n\nSome of the invading forces are holding key Institute staff hostage. Save as many of the hostages as you can. Look in the various labs throughout the upper floors of the building.\n\n|Objective Two: - Retrieve Experimental Weapon\n\nIn Foster's weapons lab there is a prototype submachine gun that we cannot let fall into enemy hands. This is because the weapon is capable of creating a temporary cloaking field. Find it and carry out some 'field research.'\n\n|Objective Three: - Deactivate Bomb\n\nOur sensors indicate there is a bomb in the Skedar craft on the landing pad! The only thing that can help you is the Data Uplink - get close to the ship, and use it to install a virus. The ship should then float clear of the Institute, and the bomb will detonate without harming anyone.\n\nEND\n",
	/*0x04*/ "\n",
	/*0x05*/ "Reactivate automatic defenses\n",
	/*0x06*/ "Minimize hostage casualties\n",
	/*0x07*/ "Retrieve experimental weapon\n",
	/*0x08*/ "Destroy sensitive information\n",
	/*0x09*/ "Deactivate bomb\n",
	/*0x0a*/ "Obtain sensitive info.\n",
	/*0x0b*/ "Guard's\n",
	/*0x0c*/ "Sensitive info\n",
	/*0x0d*/ "Sensitive info\n",
	/*0x0e*/ "Picked up sensitive info.\n",
	/*0x0f*/ "Automatic gun activated.\n",
	/*0x10*/ "Too many hostages killed.\n",
	/*0x11*/ "Hostages have been saved.\n",
	/*0x12*/ "Sensitive information has been destroyed.\n",
	/*0x13*/ "Carrington has been killed.\n",
	/*0x14*/ "Joanna - we're under attack.\n",
	/*0x15*/ "Get the guns back on line - hurry.\n",
	/*0x16*/ "The Skedar have taken hostages.\n",
	/*0x17*/ "Get up to the offices and save them.\n",
	/*0x18*/ "They're using a new form of shield technology.\n",
	/*0x19*/ "Foster was working on a new weapon which may \nbe useful.\n",
	/*0x1a*/ "Damn it. My office... If they get access...\n",
	/*0x1b*/ "Get there first, Jo, and destroy the files.\n",
	/*0x1c*/ "Things are desperate. They've planted a bomb.\n",
	/*0x1d*/ "Find it and get it out of the building.\n",
	/*0x1e*/ "Access denied - authorization failure.\n",
	/*0x1f*/ "Emergency overrides have been engaged.\n",
	/*0x20*/ "Well done, Joanna. We're nearly clear...\n",
	/*0x21*/ "The last dropship is waiting for you. Hurry.\n",
	/*0x22*/ "Critical mission object has been destroyed.\n",
	/*0x23*/ "The autodefenses will really help me out.\n",
	/*0x24*/ "So this is what Foster was working on.\n",
	/*0x25*/ "I'll have to go carefully... The hostages are\ncounting on me.\n",
	/*0x26*/ "Well, at least I won't know if I'm doing\nanything wrong.\n",
	/*0x27*/ "The bomb has been detonated...\n",
	/*0x28*/ "You have been given a Devastator.\n",
	/*0x29*/ "All ready, Joanna? We can't keep the Maian delegation waiting. Or the President, of course.\n",
	/*0x2a*/ "Am I ready? What do you mean? I was ready half an hour ago. It was you holding us up!\n",
	/*0x2b*/ "But you know how it is, Joanna; I had to make sure my hair was just right, and then there was the suit...\n",
	/*0x2c*/ "They should keep you away from mirrors. Nervous?\n",
	/*0x2d*/ "Very. I've waited for this moment for so many years. Contact, friendly contact, between Humans and Maians is what the Institute was founded for. And in a few minutes we'll be at the White House, and it will finally happen...\n",
	/*0x2e*/ "Where did that come from?\n",
	/*0x2f*/ "It was up on ground level...\n",
	/*0x30*/ "Looks like someone doesn't know when to quit. We've got to get everyone out!\n",
	/*0x31*/ "Get clear! I'll hold them off; you can come back and get me later!\n",
	/*0x32*/ "At least, I hope you can.\n",
	/*0x33*/ "You need the Data Uplink.\n",
	/*0x34*/ "Connection has been made.\n",
	/*0x35*/ "Bypassing security systems.\n",
	/*0x36*/ "Virus has been downloaded successfully.\n",
	/*0x37*/ "Ship's engines have been activated.\n",
	/*0x38*/ "Connection to ship has been broken.\n",
	/*0x39*/ "Obtain Data Uplink.\n",
	/*0x3a*/ "\n",
	/*0x3b*/ "Data Uplink\n",
	/*0x3c*/ "A Data Uplink\n",
	/*0x3d*/ "Picked up a Data Uplink.\n",
	/*0x3e*/ NULL,
	/*0x3f*/ NULL,
};
