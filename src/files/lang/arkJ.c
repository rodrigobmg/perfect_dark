#include <ultra64.h>

char *lang[] = {
	/*0x00*/ "|Background - \n\nThe alarm has been given and there are dataDyne shock troops ready for you throughout the building. Exit via the foyer is impossible due to the number of ground troops present. The transport will collect you and Dr. Caroll from the helipad.\n\n|Carrington - \n\nI don't have to remind you to protect Dr. Caroll at all costs, Joanna. Cassandra and dataDyne are going to be throwing all the obstacles they can in your path to prevent you from getting Dr. Caroll out. Good luck.\n\n|Objective One: - Gain Access to Upper Floors\n\nFight your way around the foyer until you can get access to one of the lifts that will take you and Dr. Caroll to the upper floors of the building.\n\n|Objective Two: - Reactivate Elevator\n\nWe traced an order to shut down the only accessible elevator to a PC on the lowest floor of offices. You have to find that PC and change the order to get the elevator going again.\n\n|Objective Three: - Destroy dataDyne Gunship\n\nThere is a dataDyne security gunship circling the building which outguns your jumpship and will shoot you out of the sky. Terminate it with extreme prejudice, since it will be trying to do the same thing to you.\n\n|Objective Four: - Defeat Cassandra's Bodyguards\n\nWe suspect that Cassandra has deployed her bodyguards to block the route to the helipad. It is almost certain that you'll be unable to avoid them, so expect serious resistance when you encounter them.\n\n|Objective Five: - Return To Helipad For Evac\n\nGet to the Helipad where your dropship will be waiting. And don't forget Dr. Caroll.\n\nEND\n",
	/*0x01*/ "LUCERNE TOWER\n",
	/*0x02*/ "|Background - \n\nThe alarm has been given and there are dataDyne shock troops ready for you throughout the building. Exit via the foyer is impossible due to the number of ground troops present. The transport will collect you and Dr. Caroll from the helipad.\n\n|Carrington - \n\nI don't have to remind you to protect Dr. Caroll at all costs, Joanna. Cassandra and dataDyne are going to be throwing all the obstacles they can in your path to prevent you from getting Dr. Caroll out. Good luck.\n\n|Objective One: - Gain Access to Upper Floors\n\nFight your way around the foyer until you can get access to one of the lifts that will take you and Dr. Caroll to the upper floors of the building.\n\n|Objective Two: - Destroy dataDyne Gunship\n\nThere is a dataDyne security gunship circling the building which outguns your jumpship and will shoot you out of the sky. Terminate it with extreme prejudice, since it will be trying to do the same thing to you.\n\n|Objective Three: - Defeat Cassandra's Bodyguards\n\nWe suspect that Cassandra has deployed her bodyguards to block the route to the helipad. It is almost certain that you'll be unable to avoid them, so expect serious resistance when you encounter them.\n\n|Objective Four: - Return To Helipad For Evac\n\nGet to the Helipad where your dropship will be waiting. And don't forget Dr. Caroll.\n\nEND\n",
	/*0x03*/ "|Background - \n\nThe alarm has been given and there are dataDyne shock troops ready for you throughout the building. Exit via the foyer is impossible due to the number of ground troops present. The transport will collect you and Dr. Caroll from the helipad.\n\n|Carrington - \n\nI don't have to remind you to protect Dr. Caroll at all costs, Joanna. Cassandra and dataDyne are going to be throwing all the obstacles they can in your path to prevent you from getting Dr. Caroll out. Good luck.\n\n|Objective One: - Gain Access to Upper Floors\n\nFight your way around the foyer until you can get access to one of the lifts that will take you and Dr. Caroll to the upper floors of the building.\n\n|Objective Two: - Defeat Cassandra's Bodyguards\n\nWe suspect that Cassandra has deployed her bodyguards to block the route to the helipad. It is almost certain that you'll be unable to avoid them, so expect serious resistance when you encounter them.\n\n|Objective Three: - Return To Helipad For Evac\n\nGet to the Helipad where your dropship will be waiting. And don't forget Dr. Caroll.\n\nEND\n",
	/*0x04*/ NULL,
	/*0x05*/ NULL,
	/*0x06*/ NULL,
	/*0x07*/ NULL,
	/*0x08*/ NULL,
	/*0x09*/ "Access Foyer Elevator\n",
	/*0x0a*/ "Reactivate Office Elevator\n",
	/*0x0b*/ "Destroy Datadyne Hovercopter\n",
	/*0x0c*/ "Defeat Cassandras Bodyguards\n",
	/*0x0d*/ "Rendezvous at Helipad\n",
	/*0x0e*/ "Accessing elevator controls....\n",
	/*0x0f*/ "LIGHTS ARE NOW ON !\n",
	/*0x10*/ "Dr Caroll has been killed\n",
	/*0x11*/ "Dr Caroll is under attack!\n",
	/*0x12*/ "Dr Caroll has been damaged\n",
	/*0x13*/ "Too late! She's here...\n",
	/*0x14*/ "You've become quite an annoyance..\n",
	/*0x15*/ "Goodnight Ms Dark\n",
	/*0x16*/ "LIGHTS NOW ON\n",
	/*0x17*/ "LIGHTS NOW OFF\n",
	/*0x18*/ "MISSION FAILED\n",
	/*0x19*/ "MISSION SUCCESSFUL\n",
	/*0x1a*/ "Helichopper warning goes here\n",
	/*0x1b*/ "Obtain Night Sight\n",
	/*0x1c*/ "Cassandra De Vries'\n",
	/*0x1d*/ "Night Sight\n",
	/*0x1e*/ "Night Sight\n",
	/*0x1f*/ "Picked up Night Sight\n",
	/*0x20*/ "We meet again girl!\n",
	/*0x21*/ "Foyer Elevator Accessed\n",
	/*0x22*/ "Office Elevator Door Has Been Unlocked\n",
	/*0x23*/ "Datadyne Hovercopter Eliminated\n",
	/*0x24*/ "Cassandras Bodyguards Have Been Defeated\n",
	/*0x25*/ "That's not how it goes\n",
	/*0x26*/ "Yes it is\n",
	/*0x27*/ "Give it to me, you're doing it wrong\n",
	/*0x28*/ "Stop annoying me\n",
	/*0x29*/ "Will you just hurry up\n",
	/*0x2a*/ "Oh No....Too Late\n",
	/*0x2b*/ "She's Here...\n",
	/*0x2c*/ "Get Her\n",
	/*0x2d*/ "Critical Mission Object Destroyed \n",
	/*0x2e*/ "Obtain Eye Spy\n",
	/*0x2f*/ "Dr Carolls\n",
	/*0x30*/ "Eye Spy\n",
	/*0x31*/ "An Eye Spy\n",
	/*0x32*/ "Picked up an Eye Spy\n",
	/*0x33*/ "They've locked down the ground floor - \nget to the elevator!\n",
	/*0x34*/ "That copter needs to be taken out, or \nthe jumpship'll get shot down!\n",
	/*0x35*/ "I can't leave any bodyguards standing.\n",
	/*0x36*/ "Don't keep the Jumpship waiting - \nget back to the landing pad.\n",
	/*0x37*/ "Obtain Alpha Keycard\n",
	/*0x38*/ "Guards\n",
	/*0x39*/ "Office Keycard\n",
	/*0x3a*/ "Office Keycard\n",
	/*0x3b*/ "Picked up Cassandra's Office Keycard.\n",
	/*0x3c*/ "Sound the alarm, she's here!",
	/*0x3d*/ "Lights out!",
	/*0x3e*/ "What the...?",
	/*0x3f*/ "Going somewhere?",
	/*0x40*/ "Something I can do for you, old woman?",
	/*0x41*/ "Return our sapient immediately! You don't know what you're doing.",
	/*0x42*/ "Yes I do, I'm leaving.",
	/*0x43*/ "One more chance! Give it back, and you could come and work for me.",
	/*0x44*/ "Sorry! Gotta shoot.",
	/*0x45*/ "You must get the sapient back. We cannot proceed without it.",
	/*0x46*/ "I know that!",
	/*0x47*/ "I also know who to talk to... Mr. Carrington.",
	/*0x48*/ NULL,
	/*0x49*/ NULL,
	/*0x4a*/ NULL,
	/*0x4b*/ NULL,
};
