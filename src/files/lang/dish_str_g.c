#include <ultra64.h>

char *lang[] = {
	/*0x00*/ NULL,
	/*0x01*/ NULL,
	/*0x02*/ NULL,
	/*0x03*/ NULL,
	/*0x04*/ NULL,
	/*0x05*/ NULL,
	/*0x06*/ NULL,
	/*0x07*/ NULL,
	/*0x08*/ "Collect Night Sight from table to begin.\n",
	/*0x09*/ "Activate the Night Sight.\nLocate the light switch.\nTurn the lights back on.\n",
	/*0x0a*/ "Collect Data Uplink from table to begin.\n",
	/*0x0b*/ "Stand next to the terminal and use the Uplink.\n",
	/*0x0c*/ "You need to be holding the Data Uplink.\n",
	/*0x0d*/ "Connection established...\n",
	/*0x0e*/ "Terminal has been successfully hacked.\n",
	/*0x0f*/ "Connection broken - too far from PC.\n",
	/*0x10*/ "Collect ECM Mine from table to begin.\n",
	/*0x11*/ "Locate Hub and throw ECM Mine onto Hub.\n",
	/*0x12*/ "ECM Mine has been placed incorrectly.\n",
	/*0x13*/ "ECM Mine has been placed correctly.\n",
	/*0x14*/ "Collect CamSpy from table to begin.\n",
	/*0x15*/ "Locate Info Room PC and holograph it.\n",
	/*0x16*/ "Info Room PC successfully holographed.\n",
	/*0x17*/ "Lights have been reactivated.\n",
	/*0x18*/ "Collect Door Decoder from table to begin.\n",
	/*0x19*/ "Use Decoder on door pad to unlock it.\n",
	/*0x1a*/ "You need to be holding the Door Decoder.\n",
	/*0x1b*/ "Decoder attached. Initiating cracking routines...\n",
	/*0x1c*/ "Decoding complete. Door has been unlocked.\n",
	/*0x1d*/ "Collect Tracker from table to begin.\n",
	/*0x1e*/ "Locate IR Scanner using Tracker.\n",
	/*0x1f*/ "IR Scanner has been successfully located.\n",
	/*0x20*/ "Collect IR Scanner from table to begin.\n",
	/*0x21*/ "Locate secret door using IR Scanner.\n",
	/*0x22*/ "Secret door has been successfully located.\n",
	/*0x23*/ "Collect X-Ray Scanner from table to begin.\n",
	/*0x24*/ "Find hidden switches to shut down laser grid.\n",
	/*0x25*/ "All laser grids have been deactivated.\n",
	/*0x26*/ "Collect Disguise from table to begin.\n",
	/*0x27*/ "Fool someone into giving you Cloaking Device.\n",
	/*0x28*/ "Cloaking Device successfully retrieved.\n",
	/*0x29*/ "Laser Grid 1 has been deactivated.\n",
	/*0x2a*/ "Laser Grid 2 has been deactivated.\n",
	/*0x2b*/ "I'm here to pick up the equipment.\n",
	/*0x2c*/ "Go away, Joanna. You're not fooling anybody!\n",
	/*0x2d*/ "Here you go. Don't drop it now.\n",
	/*0x2e*/ "Cloaking Device has been secured successfully.\n",
	/*0x2f*/ "You're meant to use the Disguise, remember?\n",
	/*0x30*/ "You'll have to do better than that, Joanna.\n",
	/*0x31*/ "Joanna, where did you spring from?\n",
	/*0x32*/ "You have been detected by the camera.\n",
	/*0x33*/ "Collect Cloaking Device from table to begin.\n",
	/*0x34*/ "Use Cloaking Device and locate Carrington.\n",
	/*0x35*/ "I think we can safely say your training\nis now complete!\n",
	/*0x36*/ "Mission complete - Device Training passed!\n",
	/*0x37*/ "Mission failed - you have been detected.\n",
	/*0x38*/ "Select the Uplink.\n- Hold A Button.\n- Use Control Stick to change selection.\n- Highlight Data Uplink and release A Button.\n",
	/*0x39*/ "Select the CamSpy.\n- Hold A Button.\n- Use Control Stick to change selection.\n- Highlight CamSpy and release A Button.\n",
	/*0x3a*/ "Select the Night Vision.\n- Hold A Button.\n- Use Control Stick to change selection.\n- Highlight Night Vision and release A Button.\n",
	/*0x3b*/ "Select the Door Decoder.\n- Hold A Button.\n- Use Control Stick to change selection.\n- Highlight Door Decoder and release A Button.\n",
	/*0x3c*/ "Select the X-Ray Scanner.\n- Hold A Button.\n- Use Control Stick to change selection.\n- Highlight X-Ray Scanner and release A Button.\n",
	/*0x3d*/ "Select the Disguise.\n- Hold A Button.\n- Use Control Stick to change selection.\n- Highlight Disguise and release A Button.\n",
	/*0x3e*/ "Select the IR Scanner.\n- Hold A Button.\n- Use Control Stick to change selection.\n- Highlight IR Scanner and release A Button.\n",
	/*0x3f*/ "Select the Tracker.\n- Hold A Button.\n- Use Control Stick to change selection.\n- Highlight Tracker and release A Button.\n",
	/*0x40*/ "Select the Cloaking Device.\n- Hold A Button.\n- Use Control Stick to change selection.\n- Highlight Device and release A Button.\n",
	/*0x41*/ "Select the ECM Mine.\n- Hold A Button.\n- Use Control Stick to change selection.\n- Highlight ECM Mine and release A Button.\n",
	/*0x42*/ "Joanna, it's good to see you.\n",
	/*0x43*/ "Come with me.\nI'll walk you round the training rooms.\n",
	/*0x44*/ "The information center is through this door.\n",
	/*0x45*/ "In here we have the device lab.\n",
	/*0x46*/ "This leads to the simulant training room.\n",
	/*0x47*/ "This is the firing range, Jo.\n",
	/*0x48*/ "This corridor leads down to the hangar.\n",
	/*0x49*/ "HOVERCRATE\nPress B Button next to Hovcrate to grab it...\n",
	/*0x4a*/ "Press B Button when crate grabbed to release it.\n",
	/*0x4b*/ "HOVERBIKE\nDouble tap B Button next to Hovbike to ride it...\n",
	/*0x4c*/ "Double tap B Button when on Hovbike to dismount.\n",
	/*0x4d*/ "OPENING DOORS\nPress B Button next to door to open it.\n",
	/*0x4e*/ "B Button will also activate any object nearby.\n",
	/*0x4f*/ "ELEVATORS\nPress B Button next to door to call elevator.\n",
	/*0x50*/ "Cannot exit while training is in progress.\n",
	/*0x51*/ "Switch Code 1 has been obtained.\n",
	/*0x52*/ "Switch Code 2 has been obtained.\n",
	/*0x53*/ "Switch Code 3 has been obtained.\n",
	/*0x54*/ "Switch Code 4 has been obtained.\n",
	/*0x55*/ "LOOK UP\n- Press Down C Button to look up at the target.\n",
	/*0x56*/ "LOOK DOWN\n- Press Up C Button to look down at the target.\n",
	/*0x57*/ "Holoprogram 2 has been completed successfully.\n",
	/*0x58*/ "Holoprogram 4 has been completed successfully.\n",
	/*0x59*/ "Holoprogram 5 has been completed successfully.\n",
	/*0x5a*/ "Guard has been successfully disarmed.\n",
	/*0x5b*/ "Guard has been successfully knocked out.\n",
	/*0x5c*/ "Disarm this live target if you can.\n",
	/*0x5d*/ "Knock out this target - stealth is the key.\n",
	/*0x5e*/ "And the final guard...\n",
	/*0x5f*/ "DUCK\n- Hold R Button, then press Down C Button to duck.\n",
	/*0x60*/ "CROUCH\n- When ducking, hold R Button, then press Down C Button to duck.\n",
	/*0x61*/ "Holoprogram 3 has been completed successfully.\n",
	/*0x62*/ "Activate all the switches.\n",
	/*0x63*/ "Activate all of the wall switches.\n- Be quick, as they will quickly reset.\n",
	/*0x64*/ "Get the access codes by examining terminals.\n- Use the codes on the wall terminals.\n",
	/*0x65*/ "Code 1 has been obtained.\n",
	/*0x66*/ "Code 2 has been obtained.\n",
	/*0x67*/ "Code 3 has been obtained.\n",
	/*0x68*/ "Code 4 has been obtained.\n",
	/*0x69*/ "Training failed - you must face forward.\n",
	/*0x6a*/ "Holoprogram 1 has been completed successfully.\n",
	/*0x6b*/ "Unarmed combat - knock out the target.\n- Press Z Button repeatedly to punch.\n",
	/*0x6c*/ "Now try against a moving target...\n",
	/*0x6d*/ "And finally against a target that fights back.\n",
	/*0x6e*/ "Defeat all enemies without getting hit.\n",
	/*0x6f*/ "Training failed - you have been hit.\n",
	/*0x70*/ "Holoprogram 6 has been completed successfully.\n",
	/*0x71*/ "Holoprogram 7 has been completed successfully.\n",
	/*0x72*/ "TERMINALS\n- Press B Button next to terminal to use it.\n",
	/*0x73*/ "Now activate the red terminals on the wall.\n",
	/*0x74*/ "PP7\n",
	/*0x75*/ "TT33\n",
	/*0x76*/ "Skorpion\n",
	/*0x77*/ "AK47\n",
	/*0x78*/ "Uzi 9mm\n",
	/*0x79*/ "MP5K\n",
	/*0x7a*/ "M-16\n",
	/*0x7b*/ "FNP90\n",
	/*0x7c*/ NULL,
	/*0x7d*/ NULL,
	/*0x7e*/ NULL,
	/*0x7f*/ NULL,
};